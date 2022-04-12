class NetworkModelAnalyzer:
  def __init__(self, thread_characteristics, main_thread_pid):
    self.thread_characteristics = thread_characteristics
    self.main_thread_pid = main_thread_pid
    self.network_model = {}
    self.network_model["accept_dispatch"] = False
    self.network_model["network_dispatch"] = False
    self.network_model["network_epoll"] = False
    self.network_model["nonblocking"] = False
    self.network_model["blocking"] = False
    self.network_model["accept_thread_pool_size"] = -1
    self.network_model["network_thread_pool_size"] = -1

  def analyze_network_model(self):
    accept_threads = []
    network_threads = []

    for thread in self.thread_characteristics:
      if "T_NETIO_LISTEN" in self.thread_characteristics[thread]["func"]["functionality"]:
        accept_threads.append(thread)
      if "T_NETIO_TCP_SEND" in self.thread_characteristics[thread]["func"]["functionality"]:
        network_threads.append(thread)

    assert len(accept_threads) == 1, f"There should be only one type of thread handling connections. {len(accept_threads)} threads found."
    assert len(network_threads) == 1, f"There should be only one type of thread handling requests. {len(network_threads)} threads found."

    accept_thread = accept_threads[0]
    network_thread = network_threads[0]

    if accept_thread != network_thread:
      self.network_model["network_dispatch"] = True

    # Analyze accept thread.
    if self.thread_characteristics[accept_thread]["pids/tids"][0][1] != self.main_thread_pid:
      self.network_model["accept_dispatch"] = True
    self.network_model["accept_thread_pool_size"] = round(float(self.thread_characteristics[accept_thread]["count"]["reqs"]["intercept"]))

    # Analyze network thread.
    if "T_EPOLL" in self.thread_characteristics[network_thread]["func"]["functionality"]:
      self.network_model["network_epoll"] = True
      assert "T_CLONE" not in self.thread_characteristics[network_thread]["func"]["functionality"], "We assume epoll models use thread pool."
      self.network_model["network_thread_pool_size"] = round(float(self.thread_characteristics[network_thread]["count"]["reqs"]["intercept"]))
    else:
      self.network_model["network_epoll"] = False
      assert len(self.thread_characteristics[network_thread]["socket_settings"]) == 1, "Threads within a cluster should have the same socket settings."
      if "O_NONBLOCK" in self.thread_characteristics[network_thread]["socket_settings"][0]:
        self.network_model["nonblocking"] = True
      else:
        self.network_model["blocking"] = True
    
    assert(sum([self.network_model["network_epoll"], self.network_model["nonblocking"], self.network_model["blocking"]]) == 1)
    return self.network_model

  def get_network_model(self):
    return self.network_model