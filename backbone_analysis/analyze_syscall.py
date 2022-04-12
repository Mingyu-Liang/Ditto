import json

candidate_syscalls = ["read", "readv", "pread", "preadv", "recv", "recvfrom", 
                      "recvmsg", "write", "writev", "pwrite", "pwritev", "send", 
                      "sendto", "sendmsg", "stat", "fstat", "open", "openat", "close"]
ignored_syscalls = ["epoll_wait", "futex", "epoll_ctl", "getpid"]

class SyscallAnalyzer:
  def __init__(self, syscall_result, related_tids):
    self.related_tids = related_tids
    self.syscall_result = syscall_result
    self.syscall_info = {}

  def __check_tid(self, tid):
    if tid in self.related_tids:
      return True
    else:
      return False
  
  def analyze_syscalls(self):
    overall_syscalls = self.syscall_result['syscall']
    for line in overall_syscalls:
      tid = int(line.split(",")[1])
      if self.__check_tid(tid):
        pos = line.split(",")[-1].find("sys")
        syscall_name = line.split(",")[-1][pos+4:]
        if syscall_name.startswith("new"):
          syscall_name = syscall_name[3:]
        if syscall_name.endswith("64"):
          syscall_name = syscall_name[:-2]
        if syscall_name not in candidate_syscalls:
          # We ignore some specific syscalls and syscalls invoked less than 1% of the requests.
          if syscall_name not in ignored_syscalls and overall_syscalls[line] / self.syscall_result['reqs'] > 0.01:
            print(f"Error: {syscall_name} not in candidate syscalls list, please check!")
          continue
        if syscall_name in self.syscall_info:
          if syscall_name not in ["read", "write", "readv", "writev"]:
            self.syscall_info[syscall_name]['freq'] += overall_syscalls[line] / self.syscall_result['reqs']
        else:
          self.syscall_info[syscall_name] = {}
          if syscall_name in ["read", "write", "readv", "writev"]:
            self.syscall_info[syscall_name]['file'] = {}
            self.syscall_info[syscall_name]['file']['freq'] = 0
            self.syscall_info[syscall_name]['file']['para_dist'] = {}
            self.syscall_info[syscall_name]['file']['para_dist']['count'] = {}
            self.syscall_info[syscall_name]['socket'] = {}
            self.syscall_info[syscall_name]['socket']['freq'] = 0
            self.syscall_info[syscall_name]['socket']['para_dist'] = {}
            self.syscall_info[syscall_name]['socket']['para_dist']['count'] = {}
          elif syscall_name in ["pread", "pwrite", "preadv", "pwritev"]:
            self.syscall_info[syscall_name]['freq'] = overall_syscalls[line] / self.syscall_result['reqs']
            self.syscall_info[syscall_name]['para_dist'] = {}
            self.syscall_info[syscall_name]['para_dist']['count'] = {}
            self.syscall_info[syscall_name]['para_dist']['offset'] = {}
          else:
            self.syscall_info[syscall_name]['freq'] = overall_syscalls[line] / self.syscall_result['reqs']
            self.syscall_info[syscall_name]['para_dist'] = {}
            self.syscall_info[syscall_name]['para_dist']['count'] = {}

          # For simplicity we use one vector to store the data for read and readv
          # and ensure the total amount of data is the same.
          if syscall_name in ["read", "write", "readv", "writev"]: 
            for line in self.syscall_result[syscall_name]:
              tid = int(line.split(",")[1])
              type = line.split(",")[-1].split(" ")[-1]
              if type == "other":
                continue
              count = int(line.split(",")[-2])
              if self.__check_tid(tid):
                if count not in self.syscall_info[syscall_name][type]['para_dist']['count']:
                  self.syscall_info[syscall_name][type]['para_dist']['count'][count] = 1
                else:
                  self.syscall_info[syscall_name][type]['para_dist']['count'][count] += 1
          elif syscall_name in ["recv", "send", "recvfrom", "sendto", "recvmsg", "sendmsg"]: 
            for line in self.syscall_result[syscall_name]:
              tid = int(line.split(",")[1])
              count = int(line.split(",")[-1])
              if self.__check_tid(tid):
                if count not in self.syscall_info[syscall_name]['para_dist']['count']:
                  self.syscall_info[syscall_name]['para_dist']['count'][count] = 1
                else:
                  self.syscall_info[syscall_name]['para_dist']['count'][count] += 1
          elif syscall_name in ["pread", "pwrite", "preadv", "pwritev"]:
            for line in self.syscall_result[syscall_name]:
              tid = int(line.split(",")[1])
              offset = int(line.split(",")[-2])
              count = int(line.split(",")[-1])
              if self.__check_tid(tid):
                if count not in self.syscall_info[syscall_name]['para_dist']['count']:
                  self.syscall_info[syscall_name]['para_dist']['count'][count] = 1
                else:
                  self.syscall_info[syscall_name]['para_dist']['count'][count] += 1
                if offset not in self.syscall_info[syscall_name]['para_dist']['offset']:
                  self.syscall_info[syscall_name]['para_dist']['offset'][offset] = 1
                else:
                  self.syscall_info[syscall_name]['para_dist']['offset'][offset] += 1
    
    for syscall_name in self.syscall_info:
      if syscall_name in ["read", "write", "readv", "writev"]:
        self.syscall_info[syscall_name]['file']['freq'] = sum(self.syscall_info[syscall_name]['file']['para_dist']['count'].values()) / self.syscall_result['reqs']
        self.syscall_info[syscall_name]['socket']['freq'] = sum(self.syscall_info[syscall_name]['socket']['para_dist']['count'].values()) / self.syscall_result['reqs']
  
    return self.syscall_info
    
  def get_syscall_info(self):
    return self.syscall_info

  def get_syscall_info_json(self):
    return json.dumps(self.syscall_info)