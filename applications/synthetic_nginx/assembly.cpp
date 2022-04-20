#include <cstdint>
using namespace std;
void runAssembly(uint64_t* mem_data, uint64_t req_id, uint64_t* curr_mem_addrs, uint64_t* curr_pointer_chasing_mem_addrs) {
uint64_t next_mem_addr;
uint64_t next_pointer_chasing_mem_addr;
__asm__ __volatile__ (
"lea rdi, QWORD PTR[%0]\n"
"lea rsi, QWORD PTR[%0+208]\n"
"mov rcx, 26\n"
"rep movsb byte ptr [rdi], byte ptr [rsi]\n"
:
:"r" (mem_data)
:"cc", "rdi", "rsi", "rcx"
);
if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_0_asm_start\n"
"br_uncond_func_0_block_0_rep_0_1:"
"test r11d, 512\n"
"jz br_cond_func_0_block_0_rep_0_4\n"
"br_cond_func_0_block_0_rep_0_4:"
"jmp br_uncond_func_0_block_0_rep_0_2\n"
"func_0_block_0_rep_0_asm_start:"
"and rax, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_0_0\n"
"br_cond_func_0_block_0_rep_0_0:"
"mov rdx, rbx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_0_1\n"
"br_cond_func_0_block_0_rep_0_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"and QWORD PTR[r10 + 0], rdx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_0_rep_0_2\n"
"br_cond_func_0_block_0_rep_0_2:"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_0_3\n"
"br_cond_func_0_block_0_rep_0_3:"
"sub rbx, rsi\n"
"jmp br_uncond_func_0_block_0_rep_0_0\n"
"br_uncond_func_0_block_0_rep_0_2:"
"mov QWORD PTR[r10 + 0], rdx\n"
"and rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"and rsi, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_0_asm_end\n"
"br_uncond_func_0_block_0_rep_0_0:"
"mov QWORD PTR[r10 + 0], rsi\n"
"add rsi, QWORD PTR[r10 + 0]\n"
"add QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"jmp br_uncond_func_0_block_0_rep_0_1\n"
"func_0_block_0_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_0\n"
"dummy_call_func_0_block_0_rep_0:"
"ret\n"
"end_func_0_block_0_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_1_asm_start\n"
"br_uncond_func_0_block_0_rep_1_0:"
"and rax, QWORD PTR[r10 + 0]\n"
"add rax, rbx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_1_2\n"
"br_cond_func_0_block_0_rep_1_2:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rax\n"
"or QWORD PTR[r10 + 0], rbx\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_0_rep_1_3\n"
"br_cond_func_0_block_0_rep_1_3:"
"mov rcx, rbx\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_1_4\n"
"br_cond_func_0_block_0_rep_1_4:"
"test r11d, 131072\n"
"jz br_cond_func_0_block_0_rep_1_5\n"
"br_cond_func_0_block_0_rep_1_5:"
"add rcx, rcx\n"
"sub rdx, rax\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_1_6\n"
"br_cond_func_0_block_0_rep_1_6:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_1_7\n"
"br_cond_func_0_block_0_rep_1_7:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_0_rep_1_8\n"
"br_cond_func_0_block_0_rep_1_8:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_1_9\n"
"br_cond_func_0_block_0_rep_1_9:"
"jmp func_0_block_0_rep_1_asm_end\n"
"func_0_block_0_rep_1_asm_start:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_1_0\n"
"br_cond_func_0_block_0_rep_1_0:"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_1_1\n"
"br_cond_func_0_block_0_rep_1_1:"
"add rdx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_1_0\n"
"func_0_block_0_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_1\n"
"dummy_call_func_0_block_0_rep_1:"
"ret\n"
"end_func_0_block_0_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_2_asm_start\n"
"func_0_block_0_rep_2_asm_start:"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_0_rep_2_0\n"
"br_cond_func_0_block_0_rep_2_0:"
"sub rax, QWORD PTR[r10 + 0]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_2_1\n"
"br_cond_func_0_block_0_rep_2_1:"
"mov rbx, rbx\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rdx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, rax\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_2_2\n"
"br_cond_func_0_block_0_rep_2_2:"
"and rdx, rdx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rdx, rdx\n"
"and rsi, rdi\n"
"or rdi, QWORD PTR[r10 + 0]\n"
"and rbx, rdx\n"
"or rdi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rcx, rdi\n"
"sub rsi, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, rdx\n"
"sub rcx, rsi\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_2_3\n"
"br_cond_func_0_block_0_rep_2_3:"
"jmp func_0_block_0_rep_2_asm_end\n"
"func_0_block_0_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_2\n"
"dummy_call_func_0_block_0_rep_2:"
"ret\n"
"end_func_0_block_0_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_3_asm_start\n"
"func_0_block_0_rep_3_asm_start:"
"or rax, QWORD PTR[r10 + 0]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"mov rcx, rdx\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_0_rep_3_0\n"
"br_cond_func_0_block_0_rep_3_0:"
"mov rsi, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rax\n"
"mov rax, rdi\n"
"mov QWORD PTR[r10 + 0], rdi\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_3_1\n"
"br_cond_func_0_block_0_rep_3_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_3_2\n"
"br_cond_func_0_block_0_rep_3_2:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"sub rax, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 0]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_3_3\n"
"br_cond_func_0_block_0_rep_3_3:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_0_rep_3_4\n"
"br_cond_func_0_block_0_rep_3_4:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_3_asm_end\n"
"func_0_block_0_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_3\n"
"dummy_call_func_0_block_0_rep_3:"
"ret\n"
"end_func_0_block_0_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_4_asm_start\n"
"br_uncond_func_0_block_0_rep_4_0:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_0_rep_4_5\n"
"br_cond_func_0_block_0_rep_4_5:"
"or rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_4_6\n"
"br_cond_func_0_block_0_rep_4_6:"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_4_7\n"
"br_cond_func_0_block_0_rep_4_7:"
"or rax, rbx\n"
"mov rax, rax\n"
"jmp func_0_block_0_rep_4_asm_end\n"
"func_0_block_0_rep_4_asm_start:"
"mov rax, rax\n"
"or rax, rax\n"
"call dummy_call_func_0_block_0_rep_4\n"
"mov rax, rax\n"
"mov rbx, rax\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_4_0\n"
"br_cond_func_0_block_0_rep_4_0:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_4_1\n"
"br_cond_func_0_block_0_rep_4_1:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_0_rep_4_2\n"
"br_cond_func_0_block_0_rep_4_2:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_4_3\n"
"br_cond_func_0_block_0_rep_4_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_0_rep_4_4\n"
"br_cond_func_0_block_0_rep_4_4:"
"jmp br_uncond_func_0_block_0_rep_4_0\n"
"func_0_block_0_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_4\n"
"dummy_call_func_0_block_0_rep_4:"
"ret\n"
"end_func_0_block_0_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_5_asm_start\n"
"br_uncond_func_0_block_0_rep_5_1:"
"jmp br_uncond_func_0_block_0_rep_5_2\n"
"br_uncond_func_0_block_0_rep_5_0:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_5_0\n"
"br_cond_func_0_block_0_rep_5_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"call dummy_call_func_0_block_0_rep_5\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_5_1\n"
"func_0_block_0_rep_5_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rax, rbx\n"
"mov rbx, rcx\n"
"jmp br_uncond_func_0_block_0_rep_5_0\n"
"br_uncond_func_0_block_0_rep_5_2:"
"and rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_0_rep_5_1\n"
"br_cond_func_0_block_0_rep_5_1:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_5_2\n"
"br_cond_func_0_block_0_rep_5_2:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_5_3\n"
"br_cond_func_0_block_0_rep_5_3:"
"jmp func_0_block_0_rep_5_asm_end\n"
"func_0_block_0_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_5\n"
"dummy_call_func_0_block_0_rep_5:"
"ret\n"
"end_func_0_block_0_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_6_asm_start\n"
"func_0_block_0_rep_6_asm_start:"
"call dummy_call_func_0_block_0_rep_6\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rax\n"
"mov rax, rax\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_0_rep_6_0\n"
"br_cond_func_0_block_0_rep_6_0:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"and rax, rax\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rbx, rcx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_6_1\n"
"br_cond_func_0_block_0_rep_6_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rcx\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_6_2\n"
"br_cond_func_0_block_0_rep_6_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rdx\n"
"mov rcx, rax\n"
"jmp func_0_block_0_rep_6_asm_end\n"
"func_0_block_0_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_6\n"
"dummy_call_func_0_block_0_rep_6:"
"ret\n"
"end_func_0_block_0_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_7_asm_start\n"
"func_0_block_0_rep_7_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_7_0\n"
"br_cond_func_0_block_0_rep_7_0:"
"and rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, rcx\n"
"imul rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_7_0\n"
"br_uncond_func_0_block_0_rep_7_1:"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_0_rep_7_asm_end\n"
"br_uncond_func_0_block_0_rep_7_0:"
"add rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_7_1\n"
"br_cond_func_0_block_0_rep_7_1:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_7_2\n"
"br_cond_func_0_block_0_rep_7_2:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov rax, rax\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"mov rax, rcx\n"
"jmp br_uncond_func_0_block_0_rep_7_1\n"
"func_0_block_0_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_7\n"
"dummy_call_func_0_block_0_rep_7:"
"ret\n"
"end_func_0_block_0_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_8_asm_start\n"
"br_uncond_func_0_block_0_rep_8_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"jmp func_0_block_0_rep_8_asm_end\n"
"func_0_block_0_rep_8_asm_start:"
"mov rcx, rcx\n"
"mov rax, rcx\n"
"add rax, QWORD PTR[r10 + 0]\n"
"sub rdx, rcx\n"
"jmp br_uncond_func_0_block_0_rep_8_0\n"
"br_uncond_func_0_block_0_rep_8_1:"
"mov rax, rbx\n"
"mov rax, rdx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_8_2\n"
"br_cond_func_0_block_0_rep_8_2:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_8_3\n"
"br_cond_func_0_block_0_rep_8_3:"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_0_rep_8_4\n"
"br_cond_func_0_block_0_rep_8_4:"
"mov rbx, rax\n"
"mov rax, rsi\n"
"jmp br_uncond_func_0_block_0_rep_8_2\n"
"br_uncond_func_0_block_0_rep_8_0:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_8_0\n"
"br_cond_func_0_block_0_rep_8_0:"
"test r11d, 512\n"
"jz br_cond_func_0_block_0_rep_8_1\n"
"br_cond_func_0_block_0_rep_8_1:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_8_1\n"
"func_0_block_0_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_8\n"
"dummy_call_func_0_block_0_rep_8:"
"ret\n"
"end_func_0_block_0_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_9_asm_start\n"
"br_uncond_func_0_block_0_rep_9_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_9_1\n"
"br_cond_func_0_block_0_rep_9_1:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_9_2\n"
"br_cond_func_0_block_0_rep_9_2:"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_0_rep_9_3\n"
"br_cond_func_0_block_0_rep_9_3:"
"add rcx, QWORD PTR[r10 + 0]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_0_rep_9_4\n"
"br_cond_func_0_block_0_rep_9_4:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_9_asm_end\n"
"func_0_block_0_rep_9_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_0_rep_9_0\n"
"br_cond_func_0_block_0_rep_9_0:"
"and rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_9_0\n"
"func_0_block_0_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_9\n"
"dummy_call_func_0_block_0_rep_9:"
"ret\n"
"end_func_0_block_0_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_10_asm_start\n"
"func_0_block_0_rep_10_asm_start:"
"sub rax, QWORD PTR[r10 + 0]\n"
"add rbx, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rbx, rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_0_rep_10_0\n"
"br_cond_func_0_block_0_rep_10_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rcx\n"
"and rsi, rdx\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_10_1\n"
"br_cond_func_0_block_0_rep_10_1:"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_10_2\n"
"br_cond_func_0_block_0_rep_10_2:"
"mov rdi, rdi\n"
"mov rcx, rdi\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_10_3\n"
"br_cond_func_0_block_0_rep_10_3:"
"mov QWORD PTR[r10 + 0], rdi\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], r8\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, r8\n"
"mov rcx, rdi\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"mov rcx, rcx\n"
"mov rsi, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_10_4\n"
"br_cond_func_0_block_0_rep_10_4:"
"jmp func_0_block_0_rep_10_asm_end\n"
"func_0_block_0_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_10\n"
"dummy_call_func_0_block_0_rep_10:"
"ret\n"
"end_func_0_block_0_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_11_asm_start\n"
"br_uncond_func_0_block_0_rep_11_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_11_asm_end\n"
"func_0_block_0_rep_11_asm_start:"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_11_0\n"
"br_cond_func_0_block_0_rep_11_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rbx, rax\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_11_1\n"
"br_cond_func_0_block_0_rep_11_1:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"movsd xmm0, QWORD PTR[r10 + 0]\n"
"call dummy_call_func_0_block_0_rep_11\n"
"add rbx, rbx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_11_2\n"
"br_cond_func_0_block_0_rep_11_2:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_11_3\n"
"br_cond_func_0_block_0_rep_11_3:"
"mov rdx, rdx\n"
"jmp br_uncond_func_0_block_0_rep_11_0\n"
"func_0_block_0_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_11\n"
"dummy_call_func_0_block_0_rep_11:"
"ret\n"
"end_func_0_block_0_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_12_asm_start\n"
"br_uncond_func_0_block_0_rep_12_0:"
"add rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_12_2\n"
"br_cond_func_0_block_0_rep_12_2:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_0_rep_12_asm_end\n"
"func_0_block_0_rep_12_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 0]\n"
"add rbx, rax\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"or QWORD PTR[r10 + 0], rax\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_12_0\n"
"br_cond_func_0_block_0_rep_12_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"or rdx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_0_rep_12_1\n"
"br_cond_func_0_block_0_rep_12_1:"
"mov QWORD PTR[r10 + 0], rsi\n"
"mov rax, rdx\n"
"mov rax, rdx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rcx\n"
"add rax, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_0_rep_12_0\n"
"func_0_block_0_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_12\n"
"dummy_call_func_0_block_0_rep_12:"
"ret\n"
"end_func_0_block_0_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_13_asm_start\n"
"func_0_block_0_rep_13_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_13_0\n"
"br_cond_func_0_block_0_rep_13_0:"
"add rax, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_0_rep_13_0\n"
"br_uncond_func_0_block_0_rep_13_0:"
"mov rax, rax\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_0_rep_13_1\n"
"br_cond_func_0_block_0_rep_13_1:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rbx, rax\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"imul rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_0_rep_13\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"sub rdx, rdx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_13_2\n"
"br_cond_func_0_block_0_rep_13_2:"
"call dummy_call_func_0_block_0_rep_13\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_13_3\n"
"br_cond_func_0_block_0_rep_13_3:"
"jmp func_0_block_0_rep_13_asm_end\n"
"func_0_block_0_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_13\n"
"dummy_call_func_0_block_0_rep_13:"
"ret\n"
"end_func_0_block_0_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_14_asm_start\n"
"func_0_block_0_rep_14_asm_start:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_14_0\n"
"br_cond_func_0_block_0_rep_14_0:"
"sub rax, QWORD PTR[r10 + 0]\n"
"add rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_14_1\n"
"br_cond_func_0_block_0_rep_14_1:"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"and rcx, QWORD PTR[r10 + 0]\n"
"mov rax, rcx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_14_2\n"
"br_cond_func_0_block_0_rep_14_2:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_0_rep_14_3\n"
"br_cond_func_0_block_0_rep_14_3:"
"mov r13, QWORD PTR[r13]\n"
"add rax, rdx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_14_4\n"
"br_cond_func_0_block_0_rep_14_4:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_0_rep_14_5\n"
"br_cond_func_0_block_0_rep_14_5:"
"and rax, rax\n"
"sub rsi, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_14_6\n"
"br_cond_func_0_block_0_rep_14_6:"
"and rsi, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_14_asm_end\n"
"func_0_block_0_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_14\n"
"dummy_call_func_0_block_0_rep_14:"
"ret\n"
"end_func_0_block_0_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_15_asm_start\n"
"br_uncond_func_0_block_0_rep_15_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rbx, rbx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_15_2\n"
"br_cond_func_0_block_0_rep_15_2:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_15_3\n"
"br_cond_func_0_block_0_rep_15_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"add rbx, rcx\n"
"call dummy_call_func_0_block_0_rep_15\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"add rbx, rbx\n"
"jmp func_0_block_0_rep_15_asm_end\n"
"func_0_block_0_rep_15_asm_start:"
"sub rax, rdx\n"
"mov rax, rbx\n"
"jmp br_uncond_func_0_block_0_rep_15_0\n"
"br_uncond_func_0_block_0_rep_15_0:"
"or rbx, rdx\n"
"mov rbx, rdx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_15_0\n"
"br_cond_func_0_block_0_rep_15_0:"
"mul rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_15_1\n"
"br_cond_func_0_block_0_rep_15_1:"
"sub rbx, rax\n"
"jmp br_uncond_func_0_block_0_rep_15_1\n"
"func_0_block_0_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_15\n"
"dummy_call_func_0_block_0_rep_15:"
"ret\n"
"end_func_0_block_0_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 16) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_16_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_16\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_16:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_16_asm_start\n"
"br_uncond_func_0_block_0_rep_16_0:"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_16_1\n"
"br_cond_func_0_block_0_rep_16_1:"
"and rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"sub rcx, rax\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_0_rep_16_2\n"
"br_cond_func_0_block_0_rep_16_2:"
"mov QWORD PTR[r10 + 0], rcx\n"
"or rdx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"and rdx, rcx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_0_rep_16_3\n"
"br_cond_func_0_block_0_rep_16_3:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"call dummy_call_func_0_block_0_rep_16\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_16_asm_end\n"
"func_0_block_0_rep_16_asm_start:"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_0_rep_16_0\n"
"br_cond_func_0_block_0_rep_16_0:"
"mov rbx, rdx\n"
"call dummy_call_func_0_block_0_rep_16\n"
"mov rbx, rbx\n"
"jmp br_uncond_func_0_block_0_rep_16_0\n"
"func_0_block_0_rep_16_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_16_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_16\n"
"dummy_call_func_0_block_0_rep_16:"
"ret\n"
"end_func_0_block_0_rep_16:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 17) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_17_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_17\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_17:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_17_asm_start\n"
"func_0_block_0_rep_17_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_0_rep_17_0\n"
"br_cond_func_0_block_0_rep_17_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_17_1\n"
"br_cond_func_0_block_0_rep_17_1:"
"mov rbx, rax\n"
"sub rbx, rax\n"
"sub rax, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_17_2\n"
"br_cond_func_0_block_0_rep_17_2:"
"add rdx, QWORD PTR[r10 + 0]\n"
"or rax, QWORD PTR[r10 + 0]\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rdx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_17_3\n"
"br_cond_func_0_block_0_rep_17_3:"
"mov rdx, rax\n"
"add rdx, rax\n"
"call dummy_call_func_0_block_0_rep_17\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"or rsi, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"jmp func_0_block_0_rep_17_asm_end\n"
"func_0_block_0_rep_17_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_17_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_17\n"
"dummy_call_func_0_block_0_rep_17:"
"ret\n"
"end_func_0_block_0_rep_17:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 18) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_18_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_18\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_18:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_18_asm_start\n"
"func_0_block_0_rep_18_asm_start:"
"mov rax, rbx\n"
"mov rbx, rcx\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_0_rep_18_0\n"
"br_cond_func_0_block_0_rep_18_0:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_18_1\n"
"br_cond_func_0_block_0_rep_18_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp br_uncond_func_0_block_0_rep_18_0\n"
"br_uncond_func_0_block_0_rep_18_0:"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_18_2\n"
"br_cond_func_0_block_0_rep_18_2:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rcx, rcx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov rcx, rcx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_18_3\n"
"br_cond_func_0_block_0_rep_18_3:"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"add rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_18_asm_end\n"
"func_0_block_0_rep_18_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_18_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_18\n"
"dummy_call_func_0_block_0_rep_18:"
"ret\n"
"end_func_0_block_0_rep_18:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 19) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_19_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_19\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_19:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_19_asm_start\n"
"func_0_block_0_rep_19_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_0_rep_19_0\n"
"br_cond_func_0_block_0_rep_19_0:"
"add rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_19_1\n"
"br_cond_func_0_block_0_rep_19_1:"
"mov rax, rbx\n"
"and rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_0_rep_19_2\n"
"br_cond_func_0_block_0_rep_19_2:"
"mov rax, rbx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_19_3\n"
"br_cond_func_0_block_0_rep_19_3:"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_19_4\n"
"br_cond_func_0_block_0_rep_19_4:"
"jmp br_uncond_func_0_block_0_rep_19_0\n"
"br_uncond_func_0_block_0_rep_19_0:"
"mov r13, QWORD PTR[r13]\n"
"or rax, rax\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_19_5\n"
"br_cond_func_0_block_0_rep_19_5:"
"call dummy_call_func_0_block_0_rep_19\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_19_6\n"
"br_cond_func_0_block_0_rep_19_6:"
"or rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_19_7\n"
"br_cond_func_0_block_0_rep_19_7:"
"jmp func_0_block_0_rep_19_asm_end\n"
"func_0_block_0_rep_19_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_19_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_19\n"
"dummy_call_func_0_block_0_rep_19:"
"ret\n"
"end_func_0_block_0_rep_19:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 20) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_20_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_20\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_20:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_20_asm_start\n"
"func_0_block_0_rep_20_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"or rax, rbx\n"
"jmp br_uncond_func_0_block_0_rep_20_0\n"
"br_uncond_func_0_block_0_rep_20_0:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_20_0\n"
"br_cond_func_0_block_0_rep_20_0:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"add rcx, rbx\n"
"sub rax, rbx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_20_1\n"
"br_cond_func_0_block_0_rep_20_1:"
"mov rbx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_0_rep_20_2\n"
"br_cond_func_0_block_0_rep_20_2:"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_20_3\n"
"br_cond_func_0_block_0_rep_20_3:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_20_4\n"
"br_cond_func_0_block_0_rep_20_4:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_0_rep_20_5\n"
"br_cond_func_0_block_0_rep_20_5:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_20_6\n"
"br_cond_func_0_block_0_rep_20_6:"
"jmp func_0_block_0_rep_20_asm_end\n"
"func_0_block_0_rep_20_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_20_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_20\n"
"dummy_call_func_0_block_0_rep_20:"
"ret\n"
"end_func_0_block_0_rep_20:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 21) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_21_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_21\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_21:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_21_asm_start\n"
"func_0_block_0_rep_21_asm_start:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_0_rep_21_0\n"
"br_cond_func_0_block_0_rep_21_0:"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_0_rep_21_1\n"
"br_cond_func_0_block_0_rep_21_1:"
"sub rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_21_2\n"
"br_cond_func_0_block_0_rep_21_2:"
"add rcx, QWORD PTR[r10 + 0]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_21_3\n"
"br_cond_func_0_block_0_rep_21_3:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_0_rep_21_4\n"
"br_cond_func_0_block_0_rep_21_4:"
"add rcx, QWORD PTR[r10 + 0]\n"
"mov rcx, rcx\n"
"sub rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_0_rep_21_5\n"
"br_cond_func_0_block_0_rep_21_5:"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_0_rep_21_6\n"
"br_cond_func_0_block_0_rep_21_6:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"and rdx, QWORD PTR[r10 + 0]\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rax, rdx\n"
"jmp func_0_block_0_rep_21_asm_end\n"
"func_0_block_0_rep_21_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_21_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_21\n"
"dummy_call_func_0_block_0_rep_21:"
"ret\n"
"end_func_0_block_0_rep_21:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 22) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_22_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_22\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_22:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_22_asm_start\n"
"func_0_block_0_rep_22_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_0_rep_22_0\n"
"br_cond_func_0_block_0_rep_22_0:"
"mov rbx, rcx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_22_1\n"
"br_cond_func_0_block_0_rep_22_1:"
"sub rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_22_2\n"
"br_cond_func_0_block_0_rep_22_2:"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_22_3\n"
"br_cond_func_0_block_0_rep_22_3:"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_22_4\n"
"br_cond_func_0_block_0_rep_22_4:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov rbx, rcx\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"or rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_22_5\n"
"br_cond_func_0_block_0_rep_22_5:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_22_6\n"
"br_cond_func_0_block_0_rep_22_6:"
"jmp func_0_block_0_rep_22_asm_end\n"
"func_0_block_0_rep_22_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_22_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_22\n"
"dummy_call_func_0_block_0_rep_22:"
"ret\n"
"end_func_0_block_0_rep_22:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 23) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_23_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_23\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_23:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_23_asm_start\n"
"br_uncond_func_0_block_0_rep_23_2:"
"mov r13, QWORD PTR[r13]\n"
"and rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_23_1\n"
"br_cond_func_0_block_0_rep_23_1:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"mov rax, rbx\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"and rax, QWORD PTR[r10 + 0]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_23_2\n"
"br_cond_func_0_block_0_rep_23_2:"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_23_3\n"
"br_cond_func_0_block_0_rep_23_3:"
"jmp func_0_block_0_rep_23_asm_end\n"
"br_uncond_func_0_block_0_rep_23_1:"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_23_0\n"
"br_cond_func_0_block_0_rep_23_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"jmp br_uncond_func_0_block_0_rep_23_2\n"
"func_0_block_0_rep_23_asm_start:"
"jmp br_uncond_func_0_block_0_rep_23_0\n"
"br_uncond_func_0_block_0_rep_23_0:"
"jmp br_uncond_func_0_block_0_rep_23_1\n"
"func_0_block_0_rep_23_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_23_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_23\n"
"dummy_call_func_0_block_0_rep_23:"
"ret\n"
"end_func_0_block_0_rep_23:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 24) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_24_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_24\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_24:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_24_asm_start\n"
"func_0_block_0_rep_24_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_24_0\n"
"br_cond_func_0_block_0_rep_24_0:"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_24_1\n"
"br_cond_func_0_block_0_rep_24_1:"
"and rax, QWORD PTR[r10 + 0]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_0_rep_24_0\n"
"br_uncond_func_0_block_0_rep_24_0:"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_24_2\n"
"br_cond_func_0_block_0_rep_24_2:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_0_rep_24\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_24_3\n"
"br_cond_func_0_block_0_rep_24_3:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_24_4\n"
"br_cond_func_0_block_0_rep_24_4:"
"mov rax, rcx\n"
"call dummy_call_func_0_block_0_rep_24\n"
"add rax, rax\n"
"call dummy_call_func_0_block_0_rep_24\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"sub QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_0_rep_24_asm_end\n"
"func_0_block_0_rep_24_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_24_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_24\n"
"dummy_call_func_0_block_0_rep_24:"
"ret\n"
"end_func_0_block_0_rep_24:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 25) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_25_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_25\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_25:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_25_asm_start\n"
"func_0_block_0_rep_25_asm_start:"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_25_0\n"
"br_cond_func_0_block_0_rep_25_0:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_25_1\n"
"br_cond_func_0_block_0_rep_25_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_25_2\n"
"br_cond_func_0_block_0_rep_25_2:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_25_3\n"
"br_cond_func_0_block_0_rep_25_3:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_25_4\n"
"br_cond_func_0_block_0_rep_25_4:"
"mov QWORD PTR[r10 + 0], rbx\n"
"add rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rbx\n"
"jmp br_uncond_func_0_block_0_rep_25_0\n"
"br_uncond_func_0_block_0_rep_25_0:"
"add rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"or rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_0_rep_25\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_25_5\n"
"br_cond_func_0_block_0_rep_25_5:"
"mov rdx, rcx\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_25_asm_end\n"
"func_0_block_0_rep_25_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_25_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_25\n"
"dummy_call_func_0_block_0_rep_25:"
"ret\n"
"end_func_0_block_0_rep_25:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 26) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_26_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_26\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_26:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_26_asm_start\n"
"br_uncond_func_0_block_0_rep_26_0:"
"sub rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mul rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rbx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_26_1\n"
"br_cond_func_0_block_0_rep_26_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"or rax, rax\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_0_rep_26_2\n"
"br_cond_func_0_block_0_rep_26_2:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_0_rep_26\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_26_3\n"
"br_cond_func_0_block_0_rep_26_3:"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_26_4\n"
"br_cond_func_0_block_0_rep_26_4:"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_0_rep_26_asm_end\n"
"func_0_block_0_rep_26_asm_start:"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_26_0\n"
"br_cond_func_0_block_0_rep_26_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp br_uncond_func_0_block_0_rep_26_0\n"
"func_0_block_0_rep_26_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_26_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_26\n"
"dummy_call_func_0_block_0_rep_26:"
"ret\n"
"end_func_0_block_0_rep_26:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 27) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_27_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_27\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_27:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_27_asm_start\n"
"br_uncond_func_0_block_0_rep_27_0:"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_27_3\n"
"br_cond_func_0_block_0_rep_27_3:"
"add rax, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_27_asm_end\n"
"func_0_block_0_rep_27_asm_start:"
"and rax, QWORD PTR[r10 + 0]\n"
"and QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_27_0\n"
"br_cond_func_0_block_0_rep_27_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"movsd xmm0, QWORD PTR[r10 + 0]\n"
"add rbx, rax\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rcx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_27_1\n"
"br_cond_func_0_block_0_rep_27_1:"
"and rdx, rsi\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_27_2\n"
"br_cond_func_0_block_0_rep_27_2:"
"imul rax\n"
"mov rdx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"or rsi, rcx\n"
"mov rax, rdi\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_27_0\n"
"func_0_block_0_rep_27_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_27_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_27\n"
"dummy_call_func_0_block_0_rep_27:"
"ret\n"
"end_func_0_block_0_rep_27:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 28) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_28_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_28\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_28:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_28_asm_start\n"
"func_0_block_0_rep_28_asm_start:"
"jmp br_uncond_func_0_block_0_rep_28_0\n"
"br_uncond_func_0_block_0_rep_28_1:"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_28_asm_end\n"
"br_uncond_func_0_block_0_rep_28_0:"
"mov rax, rax\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"and rcx, rdx\n"
"mov rax, rbx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_28_0\n"
"br_cond_func_0_block_0_rep_28_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_28_1\n"
"br_cond_func_0_block_0_rep_28_1:"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"add rax, rax\n"
"mov rcx, rdx\n"
"mov rdx, rax\n"
"sub rsi, rbx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_28_2\n"
"br_cond_func_0_block_0_rep_28_2:"
"mov r13, QWORD PTR[r13]\n"
"sub rdi, r8\n"
"mov rbx, rcx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_0_rep_28_3\n"
"br_cond_func_0_block_0_rep_28_3:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_0_rep_28_1\n"
"func_0_block_0_rep_28_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_28_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_28\n"
"dummy_call_func_0_block_0_rep_28:"
"ret\n"
"end_func_0_block_0_rep_28:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 29) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_29_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_29\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_29:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_29_asm_start\n"
"br_uncond_func_0_block_0_rep_29_0:"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_29_2\n"
"br_cond_func_0_block_0_rep_29_2:"
"mov rax, rbx\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_29_3\n"
"br_cond_func_0_block_0_rep_29_3:"
"or rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rdx\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_0_rep_29_4\n"
"br_cond_func_0_block_0_rep_29_4:"
"jmp func_0_block_0_rep_29_asm_end\n"
"func_0_block_0_rep_29_asm_start:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_29_0\n"
"br_cond_func_0_block_0_rep_29_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_0_rep_29_1\n"
"br_cond_func_0_block_0_rep_29_1:"
"mov rax, rbx\n"
"call dummy_call_func_0_block_0_rep_29\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_29_0\n"
"func_0_block_0_rep_29_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_29_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_29\n"
"dummy_call_func_0_block_0_rep_29:"
"ret\n"
"end_func_0_block_0_rep_29:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 30) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_30_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_30\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_30:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_30_asm_start\n"
"br_uncond_func_0_block_0_rep_30_0:"
"add rax, rbx\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_0_rep_30_3\n"
"br_cond_func_0_block_0_rep_30_3:"
"and rax, rbx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_30_4\n"
"br_cond_func_0_block_0_rep_30_4:"
"mov QWORD PTR[r10 + 0], rax\n"
"and rcx, QWORD PTR[r10 + 0]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_30_5\n"
"br_cond_func_0_block_0_rep_30_5:"
"test r11d, 64\n"
"jz br_cond_func_0_block_0_rep_30_6\n"
"br_cond_func_0_block_0_rep_30_6:"
"imul rbx\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_30_asm_end\n"
"func_0_block_0_rep_30_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_30_0\n"
"br_cond_func_0_block_0_rep_30_0:"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_0_rep_30_1\n"
"br_cond_func_0_block_0_rep_30_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_30_2\n"
"br_cond_func_0_block_0_rep_30_2:"
"mov r13, QWORD PTR[r13]\n"
"and rbx, rbx\n"
"jmp br_uncond_func_0_block_0_rep_30_0\n"
"func_0_block_0_rep_30_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_30_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_30\n"
"dummy_call_func_0_block_0_rep_30:"
"ret\n"
"end_func_0_block_0_rep_30:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 31) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_31_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_31\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_31:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_31_asm_start\n"
"func_0_block_0_rep_31_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_31_0\n"
"br_cond_func_0_block_0_rep_31_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rbx, rax\n"
"or rcx, rax\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"mov rdx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rsi, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_31_1\n"
"br_cond_func_0_block_0_rep_31_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_31_2\n"
"br_cond_func_0_block_0_rep_31_2:"
"mov QWORD PTR[r10 + 0], rsi\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_0_rep_31\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"sub rsi, rax\n"
"and rax, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rcx\n"
"mov QWORD PTR[r10 + 0], rdi\n"
"jmp func_0_block_0_rep_31_asm_end\n"
"func_0_block_0_rep_31_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_31_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_31\n"
"dummy_call_func_0_block_0_rep_31:"
"ret\n"
"end_func_0_block_0_rep_31:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 32) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_32_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_32\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_32:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_32_asm_start\n"
"func_0_block_0_rep_32_asm_start:"
"add rax, QWORD PTR[r10 + 0]\n"
"or rbx, rcx\n"
"sub QWORD PTR[r10 + 0], rax\n"
"sub rbx, rcx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_32_0\n"
"br_cond_func_0_block_0_rep_32_0:"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mul rcx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_32_1\n"
"br_cond_func_0_block_0_rep_32_1:"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_32_2\n"
"br_cond_func_0_block_0_rep_32_2:"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rbx, rcx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_0_rep_32_3\n"
"br_cond_func_0_block_0_rep_32_3:"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_32_4\n"
"br_cond_func_0_block_0_rep_32_4:"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_32_5\n"
"br_cond_func_0_block_0_rep_32_5:"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_32_6\n"
"br_cond_func_0_block_0_rep_32_6:"
"or rax, QWORD PTR[r10 + 0]\n"
"mov rcx, rax\n"
"call dummy_call_func_0_block_0_rep_32\n"
"jmp func_0_block_0_rep_32_asm_end\n"
"func_0_block_0_rep_32_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_32_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_32\n"
"dummy_call_func_0_block_0_rep_32:"
"ret\n"
"end_func_0_block_0_rep_32:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 33) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_33_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_33\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_33:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_33_asm_start\n"
"br_uncond_func_0_block_0_rep_33_0:"
"mov rax, rbx\n"
"and rax, QWORD PTR[r10 + 0]\n"
"or rax, rbx\n"
"mov rax, rax\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_33_0\n"
"br_cond_func_0_block_0_rep_33_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, rax\n"
"mov rbx, rdx\n"
"jmp br_uncond_func_0_block_0_rep_33_1\n"
"br_uncond_func_0_block_0_rep_33_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rdx, rax\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_0_rep_33_1\n"
"br_cond_func_0_block_0_rep_33_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_33_2\n"
"br_cond_func_0_block_0_rep_33_2:"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_33_asm_end\n"
"func_0_block_0_rep_33_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_33_0\n"
"func_0_block_0_rep_33_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_33_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_33\n"
"dummy_call_func_0_block_0_rep_33:"
"ret\n"
"end_func_0_block_0_rep_33:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 34) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_34_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_34\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_34:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_34_asm_start\n"
"func_0_block_0_rep_34_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_0_rep_34_0\n"
"br_cond_func_0_block_0_rep_34_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_34_1\n"
"br_cond_func_0_block_0_rep_34_1:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_0_rep_34_2\n"
"br_cond_func_0_block_0_rep_34_2:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_34_3\n"
"br_cond_func_0_block_0_rep_34_3:"
"call dummy_call_func_0_block_0_rep_34\n"
"imul rcx\n"
"call dummy_call_func_0_block_0_rep_34\n"
"and rcx, QWORD PTR[r10 + 0]\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, QWORD PTR[r10 + 0]\n"
"sub rsi, QWORD PTR[r10 + 0]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_34_4\n"
"br_cond_func_0_block_0_rep_34_4:"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rdx\n"
"jmp func_0_block_0_rep_34_asm_end\n"
"func_0_block_0_rep_34_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_34_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_34\n"
"dummy_call_func_0_block_0_rep_34:"
"ret\n"
"end_func_0_block_0_rep_34:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 35) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_35_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_35\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_35:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_35_asm_start\n"
"func_0_block_0_rep_35_asm_start:"
"mov rax, rbx\n"
"mov rcx, rax\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_35_0\n"
"br_cond_func_0_block_0_rep_35_0:"
"mov rax, rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_35_1\n"
"br_cond_func_0_block_0_rep_35_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"or rdx, rcx\n"
"and rdx, rbx\n"
"jmp br_uncond_func_0_block_0_rep_35_0\n"
"br_uncond_func_0_block_0_rep_35_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rdx, rdx\n"
"jmp br_uncond_func_0_block_0_rep_35_1\n"
"br_uncond_func_0_block_0_rep_35_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rbx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_35_2\n"
"br_cond_func_0_block_0_rep_35_2:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rsi, rsi\n"
"mov rdx, rsi\n"
"jmp func_0_block_0_rep_35_asm_end\n"
"func_0_block_0_rep_35_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_35_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_35\n"
"dummy_call_func_0_block_0_rep_35:"
"ret\n"
"end_func_0_block_0_rep_35:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 36) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_36_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_36\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_36:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_36_asm_start\n"
"func_0_block_0_rep_36_asm_start:"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_36_0\n"
"br_cond_func_0_block_0_rep_36_0:"
"call dummy_call_func_0_block_0_rep_36\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp br_uncond_func_0_block_0_rep_36_0\n"
"br_uncond_func_0_block_0_rep_36_0:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_0_rep_36_1\n"
"br_cond_func_0_block_0_rep_36_1:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_0_rep_36_2\n"
"br_cond_func_0_block_0_rep_36_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rsi\n"
"mov rbx, rdx\n"
"mov rsi, rdx\n"
"and rcx, rdx\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_36_3\n"
"br_cond_func_0_block_0_rep_36_3:"
"mov QWORD PTR[r10 + 0], rdx\n"
"add rbx, rax\n"
"mov rsi, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_36_asm_end\n"
"func_0_block_0_rep_36_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_36_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_36\n"
"dummy_call_func_0_block_0_rep_36:"
"ret\n"
"end_func_0_block_0_rep_36:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 37) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_37_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_37\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_37:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_37_asm_start\n"
"func_0_block_0_rep_37_asm_start:"
"test r11d, 512\n"
"jz br_cond_func_0_block_0_rep_37_0\n"
"br_cond_func_0_block_0_rep_37_0:"
"or rax, QWORD PTR[r10 + 0]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_37_1\n"
"br_cond_func_0_block_0_rep_37_1:"
"mov rax, rbx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_0_rep_37_2\n"
"br_cond_func_0_block_0_rep_37_2:"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_37_3\n"
"br_cond_func_0_block_0_rep_37_3:"
"and rax, rax\n"
"mov rcx, rbx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_37_4\n"
"br_cond_func_0_block_0_rep_37_4:"
"or rax, rcx\n"
"mov rdx, rax\n"
"call dummy_call_func_0_block_0_rep_37\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_37_5\n"
"br_cond_func_0_block_0_rep_37_5:"
"test r11d, 32\n"
"jz br_cond_func_0_block_0_rep_37_6\n"
"br_cond_func_0_block_0_rep_37_6:"
"test r11d, 64\n"
"jz br_cond_func_0_block_0_rep_37_7\n"
"br_cond_func_0_block_0_rep_37_7:"
"call dummy_call_func_0_block_0_rep_37\n"
"sub rdx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_37_asm_end\n"
"func_0_block_0_rep_37_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_37_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_37\n"
"dummy_call_func_0_block_0_rep_37:"
"ret\n"
"end_func_0_block_0_rep_37:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 38) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_38_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_38\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_38:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_38_asm_start\n"
"br_uncond_func_0_block_0_rep_38_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_38_2\n"
"br_cond_func_0_block_0_rep_38_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_0_rep_38_3\n"
"br_cond_func_0_block_0_rep_38_3:"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_38_4\n"
"br_cond_func_0_block_0_rep_38_4:"
"or rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_0_rep_38_5\n"
"br_cond_func_0_block_0_rep_38_5:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rax, QWORD PTR[r10 + 0]\n"
"call dummy_call_func_0_block_0_rep_38\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_0_rep_38_6\n"
"br_cond_func_0_block_0_rep_38_6:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_38_7\n"
"br_cond_func_0_block_0_rep_38_7:"
"test r11d, 64\n"
"jz br_cond_func_0_block_0_rep_38_8\n"
"br_cond_func_0_block_0_rep_38_8:"
"mov rax, rax\n"
"jmp func_0_block_0_rep_38_asm_end\n"
"func_0_block_0_rep_38_asm_start:"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_38_0\n"
"br_cond_func_0_block_0_rep_38_0:"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_38_1\n"
"br_cond_func_0_block_0_rep_38_1:"
"jmp br_uncond_func_0_block_0_rep_38_0\n"
"func_0_block_0_rep_38_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_38_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_38\n"
"dummy_call_func_0_block_0_rep_38:"
"ret\n"
"end_func_0_block_0_rep_38:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 39) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_39_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_39\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_39:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_39_asm_start\n"
"func_0_block_0_rep_39_asm_start:"
"and rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"call dummy_call_func_0_block_0_rep_39\n"
"sub rax, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_39_0\n"
"br_cond_func_0_block_0_rep_39_0:"
"and rax, rbx\n"
"add rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_39_1\n"
"br_cond_func_0_block_0_rep_39_1:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rbx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_39_2\n"
"br_cond_func_0_block_0_rep_39_2:"
"test r11d, 4\n"
"jz br_cond_func_0_block_0_rep_39_3\n"
"br_cond_func_0_block_0_rep_39_3:"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_39_4\n"
"br_cond_func_0_block_0_rep_39_4:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_0_rep_39_5\n"
"br_cond_func_0_block_0_rep_39_5:"
"and rcx, rcx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_0_rep_39_asm_end\n"
"func_0_block_0_rep_39_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_39_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_39\n"
"dummy_call_func_0_block_0_rep_39:"
"ret\n"
"end_func_0_block_0_rep_39:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 40) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_40_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_40\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_40:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_40_asm_start\n"
"func_0_block_0_rep_40_asm_start:"
"jmp br_uncond_func_0_block_0_rep_40_0\n"
"br_uncond_func_0_block_0_rep_40_0:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_0_rep_40_0\n"
"br_cond_func_0_block_0_rep_40_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_40_1\n"
"br_cond_func_0_block_0_rep_40_1:"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_40_2\n"
"br_cond_func_0_block_0_rep_40_2:"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"and rax, rcx\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_40_3\n"
"br_cond_func_0_block_0_rep_40_3:"
"test r11d, 2\n"
"jz br_cond_func_0_block_0_rep_40_4\n"
"br_cond_func_0_block_0_rep_40_4:"
"jmp func_0_block_0_rep_40_asm_end\n"
"func_0_block_0_rep_40_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_40_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_40\n"
"dummy_call_func_0_block_0_rep_40:"
"ret\n"
"end_func_0_block_0_rep_40:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 41) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_41_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_41\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_41:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_41_asm_start\n"
"func_0_block_0_rep_41_asm_start:"
"call dummy_call_func_0_block_0_rep_41\n"
"mul rax\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_0_rep_41_0\n"
"br_cond_func_0_block_0_rep_41_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_41_0\n"
"br_uncond_func_0_block_0_rep_41_0:"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_0_rep_41_1\n"
"br_cond_func_0_block_0_rep_41_1:"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_41_2\n"
"br_cond_func_0_block_0_rep_41_2:"
"mov rax, rax\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_41_3\n"
"br_cond_func_0_block_0_rep_41_3:"
"jmp br_uncond_func_0_block_0_rep_41_1\n"
"br_uncond_func_0_block_0_rep_41_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"add rax, QWORD PTR[r10 + 0]\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_0_rep_41_4\n"
"br_cond_func_0_block_0_rep_41_4:"
"mul rbx\n"
"add rax, rax\n"
"and QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_41_5\n"
"br_cond_func_0_block_0_rep_41_5:"
"jmp func_0_block_0_rep_41_asm_end\n"
"func_0_block_0_rep_41_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_41_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_41\n"
"dummy_call_func_0_block_0_rep_41:"
"ret\n"
"end_func_0_block_0_rep_41:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 42) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_42_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_42\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_42:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_42_asm_start\n"
"func_0_block_0_rep_42_asm_start:"
"jmp br_uncond_func_0_block_0_rep_42_0\n"
"br_uncond_func_0_block_0_rep_42_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_42_0\n"
"br_cond_func_0_block_0_rep_42_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_42_1\n"
"br_cond_func_0_block_0_rep_42_1:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rbx, rcx\n"
"mov rcx, rax\n"
"mov rdx, rsi\n"
"and rdx, QWORD PTR[r10 + 0]\n"
"or rsi, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"and rsi, rdi\n"
"mov r13, QWORD PTR[r13]\n"
"and rdi, QWORD PTR[r10 + 0]\n"
"mov rbx, rdi\n"
"imul rsi\n"
"mov QWORD PTR[r10 + 0], r8\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_0_rep_42_2\n"
"br_cond_func_0_block_0_rep_42_2:"
"mov QWORD PTR[r10 + 0], rbx\n"
"imul rbx\n"
"mov rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], r8\n"
"jmp func_0_block_0_rep_42_asm_end\n"
"func_0_block_0_rep_42_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_42_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_42\n"
"dummy_call_func_0_block_0_rep_42:"
"ret\n"
"end_func_0_block_0_rep_42:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 43) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_43_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_43\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_43:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_43_asm_start\n"
"func_0_block_0_rep_43_asm_start:"
"jmp br_uncond_func_0_block_0_rep_43_0\n"
"br_uncond_func_0_block_0_rep_43_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_0_rep_43_0\n"
"br_cond_func_0_block_0_rep_43_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_43_1\n"
"br_cond_func_0_block_0_rep_43_1:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_43_2\n"
"br_cond_func_0_block_0_rep_43_2:"
"add rbx, QWORD PTR[r10 + 0]\n"
"mov rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rdx, rbx\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"mov rbx, rax\n"
"jmp br_uncond_func_0_block_0_rep_43_1\n"
"br_uncond_func_0_block_0_rep_43_1:"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"mov rbx, rdx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_43_3\n"
"br_cond_func_0_block_0_rep_43_3:"
"add rbx, rdx\n"
"mov rax, rsi\n"
"and rax, rbx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_0_rep_43_4\n"
"br_cond_func_0_block_0_rep_43_4:"
"mov rsi, rcx\n"
"jmp func_0_block_0_rep_43_asm_end\n"
"func_0_block_0_rep_43_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_43_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_43\n"
"dummy_call_func_0_block_0_rep_43:"
"ret\n"
"end_func_0_block_0_rep_43:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 44) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_44_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_44\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_44:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_44_asm_start\n"
"func_0_block_0_rep_44_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_0_rep_44_0\n"
"br_cond_func_0_block_0_rep_44_0:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_0_rep_44_1\n"
"br_cond_func_0_block_0_rep_44_1:"
"test r11d, 8\n"
"jz br_cond_func_0_block_0_rep_44_2\n"
"br_cond_func_0_block_0_rep_44_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_0_rep_44_3\n"
"br_cond_func_0_block_0_rep_44_3:"
"add rbx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_0_rep_44_0\n"
"br_uncond_func_0_block_0_rep_44_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"and rbx, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_0_rep_44_4\n"
"br_cond_func_0_block_0_rep_44_4:"
"test r11d, 1\n"
"jz br_cond_func_0_block_0_rep_44_5\n"
"br_cond_func_0_block_0_rep_44_5:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_0_rep_44_asm_end\n"
"func_0_block_0_rep_44_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_44_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_44\n"
"dummy_call_func_0_block_0_rep_44:"
"ret\n"
"end_func_0_block_0_rep_44:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 45) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_45_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_45\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_45:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_45_asm_start\n"
"func_0_block_0_rep_45_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"add rbx, rax\n"
"or rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"call dummy_call_func_0_block_0_rep_45\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rcx\n"
"mov rdx, rax\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rdx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"call dummy_call_func_0_block_0_rep_45\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rdx\n"
"mov rax, rsi\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"add rsi, rdi\n"
"add r8, QWORD PTR[r10 + 0]\n"
"add rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_45_0\n"
"br_cond_func_0_block_0_rep_45_0:"
"or rdx, rdx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_45_1\n"
"br_cond_func_0_block_0_rep_45_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdi\n"
"mov QWORD PTR[r10 + 0], rdi\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_45_asm_end\n"
"func_0_block_0_rep_45_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_45_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_45\n"
"dummy_call_func_0_block_0_rep_45:"
"ret\n"
"end_func_0_block_0_rep_45:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 46) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_46_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_46\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_46:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_46_asm_start\n"
"br_uncond_func_0_block_0_rep_46_2:"
"and rax, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_0_rep_46_asm_end\n"
"br_uncond_func_0_block_0_rep_46_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp br_uncond_func_0_block_0_rep_46_1\n"
"br_uncond_func_0_block_0_rep_46_1:"
"mov rbx, rbx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_0_rep_46_1\n"
"br_cond_func_0_block_0_rep_46_1:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_0_rep_46_2\n"
"br_cond_func_0_block_0_rep_46_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_0_rep_46_3\n"
"br_cond_func_0_block_0_rep_46_3:"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"jmp br_uncond_func_0_block_0_rep_46_2\n"
"func_0_block_0_rep_46_asm_start:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_46_0\n"
"br_cond_func_0_block_0_rep_46_0:"
"jmp br_uncond_func_0_block_0_rep_46_0\n"
"func_0_block_0_rep_46_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_46_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_46\n"
"dummy_call_func_0_block_0_rep_46:"
"ret\n"
"end_func_0_block_0_rep_46:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 47) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_47_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_47\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_47:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_47_asm_start\n"
"br_uncond_func_0_block_0_rep_47_0:"
"mov rax, rax\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"sub rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rbx\n"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"and rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"or QWORD PTR[r10 + 0], rsi\n"
"or rsi, rdi\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_0_rep_47_1\n"
"br_cond_func_0_block_0_rep_47_1:"
"imul rdi\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_0_rep_47_2\n"
"br_cond_func_0_block_0_rep_47_2:"
"or rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_47_3\n"
"br_cond_func_0_block_0_rep_47_3:"
"jmp br_uncond_func_0_block_0_rep_47_1\n"
"br_uncond_func_0_block_0_rep_47_1:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_0_rep_47_asm_end\n"
"func_0_block_0_rep_47_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_0_rep_47_0\n"
"br_cond_func_0_block_0_rep_47_0:"
"jmp br_uncond_func_0_block_0_rep_47_0\n"
"func_0_block_0_rep_47_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_47_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_47\n"
"dummy_call_func_0_block_0_rep_47:"
"ret\n"
"end_func_0_block_0_rep_47:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 48) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_48_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_48\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_48:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_48_asm_start\n"
"func_0_block_0_rep_48_asm_start:"
"sub rax, rax\n"
"mov rbx, rcx\n"
"sub rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_0_rep_48_0\n"
"br_uncond_func_0_block_0_rep_48_2:"
"mov r13, QWORD PTR[r13]\n"
"and rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, rbx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_48_3\n"
"br_cond_func_0_block_0_rep_48_3:"
"jmp func_0_block_0_rep_48_asm_end\n"
"br_uncond_func_0_block_0_rep_48_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_0_rep_48_0\n"
"br_cond_func_0_block_0_rep_48_0:"
"and rcx, rcx\n"
"call dummy_call_func_0_block_0_rep_48\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"add rcx, rcx\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_0_rep_48_1\n"
"br_uncond_func_0_block_0_rep_48_1:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_48_1\n"
"br_cond_func_0_block_0_rep_48_1:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_0_rep_48_2\n"
"br_cond_func_0_block_0_rep_48_2:"
"jmp br_uncond_func_0_block_0_rep_48_2\n"
"func_0_block_0_rep_48_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_48_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_48\n"
"dummy_call_func_0_block_0_rep_48:"
"ret\n"
"end_func_0_block_0_rep_48:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 0 && (req_id & 1023) < 354 && (req_id % 50) == 49) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_0_rep_49_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_0_rep_49\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_0_rep_49:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_0_rep_49_asm_start\n"
"func_0_block_0_rep_49_asm_start:"
"jmp br_uncond_func_0_block_0_rep_49_0\n"
"br_uncond_func_0_block_0_rep_49_0:"
"or rax, rbx\n"
"call dummy_call_func_0_block_0_rep_49\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_0_rep_49_0\n"
"br_cond_func_0_block_0_rep_49_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_49_1\n"
"br_cond_func_0_block_0_rep_49_1:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_0_rep_49_2\n"
"br_cond_func_0_block_0_rep_49_2:"
"test r11d, 16\n"
"jz br_cond_func_0_block_0_rep_49_3\n"
"br_cond_func_0_block_0_rep_49_3:"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"and QWORD PTR[r10 + 0], rcx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_0_rep_49_4\n"
"br_cond_func_0_block_0_rep_49_4:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_0_rep_49_5\n"
"br_cond_func_0_block_0_rep_49_5:"
"mov r13, QWORD PTR[r13]\n"
"or rcx, rdx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_0_rep_49_6\n"
"br_cond_func_0_block_0_rep_49_6:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_0_rep_49_7\n"
"br_cond_func_0_block_0_rep_49_7:"
"mov QWORD PTR[r10 + 0], rcx\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"jmp func_0_block_0_rep_49_asm_end\n"
"func_0_block_0_rep_49_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_0_rep_49_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_0_rep_49\n"
"dummy_call_func_0_block_0_rep_49:"
"ret\n"
"end_func_0_block_0_rep_49:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[0]), "r" (curr_pointer_chasing_mem_addrs[0]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[0] = next_mem_addr;
curr_pointer_chasing_mem_addrs[0] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_0_asm_start\n"
"br_uncond_func_0_block_1_rep_0_0:"
"call dummy_call_func_0_block_1_rep_0\n"
"mov r13, QWORD PTR[r13]\n"
"or QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_0_1\n"
"br_uncond_func_0_block_1_rep_0_1:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_0_0\n"
"br_cond_func_0_block_1_rep_0_0:"
"call dummy_call_func_0_block_1_rep_0\n"
"or rbx, rbx\n"
"mov rcx, rdx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_1_rep_0_1\n"
"br_cond_func_0_block_1_rep_0_1:"
"call dummy_call_func_0_block_1_rep_0\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_0_2\n"
"br_cond_func_0_block_1_rep_0_2:"
"jmp func_0_block_1_rep_0_asm_end\n"
"func_0_block_1_rep_0_asm_start:"
"and rdx, rcx\n"
"jmp br_uncond_func_0_block_1_rep_0_0\n"
"func_0_block_1_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_0\n"
"dummy_call_func_0_block_1_rep_0:"
"ret\n"
"end_func_0_block_1_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_1_asm_start\n"
"br_uncond_func_0_block_1_rep_1_0:"
"call dummy_call_func_0_block_1_rep_1\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, rbx\n"
"sub rbx, rax\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_1_4\n"
"br_cond_func_0_block_1_rep_1_4:"
"jmp func_0_block_1_rep_1_asm_end\n"
"func_0_block_1_rep_1_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_1_0\n"
"br_cond_func_0_block_1_rep_1_0:"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_1_rep_1_1\n"
"br_cond_func_0_block_1_rep_1_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_1_2\n"
"br_cond_func_0_block_1_rep_1_2:"
"mov rcx, rcx\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_1_3\n"
"br_cond_func_0_block_1_rep_1_3:"
"mov rcx, rax\n"
"jmp br_uncond_func_0_block_1_rep_1_0\n"
"func_0_block_1_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_1\n"
"dummy_call_func_0_block_1_rep_1:"
"ret\n"
"end_func_0_block_1_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_2_asm_start\n"
"br_uncond_func_0_block_1_rep_2_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_1_rep_2_3\n"
"br_cond_func_0_block_1_rep_2_3:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_1_rep_2_4\n"
"br_cond_func_0_block_1_rep_2_4:"
"mov QWORD PTR[r10 + 64], rdx\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"add rdx, rdx\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"jmp func_0_block_1_rep_2_asm_end\n"
"func_0_block_1_rep_2_asm_start:"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_2_0\n"
"br_cond_func_0_block_1_rep_2_0:"
"add QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, QWORD PTR[r10 + 64]\n"
"mov rbx, rdx\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_2_1\n"
"br_cond_func_0_block_1_rep_2_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rax, rsi\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_1_rep_2_2\n"
"br_cond_func_0_block_1_rep_2_2:"
"jmp br_uncond_func_0_block_1_rep_2_0\n"
"func_0_block_1_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_2\n"
"dummy_call_func_0_block_1_rep_2:"
"ret\n"
"end_func_0_block_1_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_3_asm_start\n"
"func_0_block_1_rep_3_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_1_rep_3_0\n"
"br_cond_func_0_block_1_rep_3_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_3_1\n"
"br_cond_func_0_block_1_rep_3_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_3_2\n"
"br_cond_func_0_block_1_rep_3_2:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rbx\n"
"call dummy_call_func_0_block_1_rep_3\n"
"jmp br_uncond_func_0_block_1_rep_3_0\n"
"br_uncond_func_0_block_1_rep_3_1:"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rax, rcx\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_3_4\n"
"br_cond_func_0_block_1_rep_3_4:"
"jmp func_0_block_1_rep_3_asm_end\n"
"br_uncond_func_0_block_1_rep_3_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"add rdx, QWORD PTR[r10 + 64]\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_1_rep_3_3\n"
"br_cond_func_0_block_1_rep_3_3:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"jmp br_uncond_func_0_block_1_rep_3_1\n"
"func_0_block_1_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_3\n"
"dummy_call_func_0_block_1_rep_3:"
"ret\n"
"end_func_0_block_1_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_4_asm_start\n"
"br_uncond_func_0_block_1_rep_4_0:"
"add rax, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"add rbx, rcx\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_4_2\n"
"br_cond_func_0_block_1_rep_4_2:"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_4_3\n"
"br_cond_func_0_block_1_rep_4_3:"
"jmp func_0_block_1_rep_4_asm_end\n"
"func_0_block_1_rep_4_asm_start:"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rbx\n"
"mov rcx, rbx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_4_0\n"
"br_cond_func_0_block_1_rep_4_0:"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_4_1\n"
"br_cond_func_0_block_1_rep_4_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, rcx\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rbx, rax\n"
"mov rbx, rbx\n"
"jmp br_uncond_func_0_block_1_rep_4_0\n"
"func_0_block_1_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_4\n"
"dummy_call_func_0_block_1_rep_4:"
"ret\n"
"end_func_0_block_1_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_5_asm_start\n"
"br_uncond_func_0_block_1_rep_5_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_5_1\n"
"br_uncond_func_0_block_1_rep_5_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_5_4\n"
"br_cond_func_0_block_1_rep_5_4:"
"or rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rdx\n"
"jmp func_0_block_1_rep_5_asm_end\n"
"func_0_block_1_rep_5_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, rax\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_1_rep_5_0\n"
"br_cond_func_0_block_1_rep_5_0:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_1_rep_5_1\n"
"br_cond_func_0_block_1_rep_5_1:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_5_2\n"
"br_cond_func_0_block_1_rep_5_2:"
"call dummy_call_func_0_block_1_rep_5\n"
"and rdx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rsi, QWORD PTR[r10 + 64]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_1_rep_5_3\n"
"br_cond_func_0_block_1_rep_5_3:"
"jmp br_uncond_func_0_block_1_rep_5_0\n"
"func_0_block_1_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_5\n"
"dummy_call_func_0_block_1_rep_5:"
"ret\n"
"end_func_0_block_1_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_6_asm_start\n"
"func_0_block_1_rep_6_asm_start:"
"jmp br_uncond_func_0_block_1_rep_6_0\n"
"br_uncond_func_0_block_1_rep_6_0:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_6_0\n"
"br_cond_func_0_block_1_rep_6_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"and rbx, QWORD PTR[r10 + 64]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"call dummy_call_func_0_block_1_rep_6\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_1_rep_6_1\n"
"br_cond_func_0_block_1_rep_6_1:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_6_2\n"
"br_cond_func_0_block_1_rep_6_2:"
"add rcx, rcx\n"
"and rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_1_rep_6_3\n"
"br_cond_func_0_block_1_rep_6_3:"
"sub rcx, rcx\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_6_4\n"
"br_cond_func_0_block_1_rep_6_4:"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_6_5\n"
"br_cond_func_0_block_1_rep_6_5:"
"mov rcx, rcx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_6_6\n"
"br_cond_func_0_block_1_rep_6_6:"
"mov rdx, rcx\n"
"jmp func_0_block_1_rep_6_asm_end\n"
"func_0_block_1_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_6\n"
"dummy_call_func_0_block_1_rep_6:"
"ret\n"
"end_func_0_block_1_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_7_asm_start\n"
"func_0_block_1_rep_7_asm_start:"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_7_0\n"
"br_cond_func_0_block_1_rep_7_0:"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov rcx, rbx\n"
"add rax, rcx\n"
"mov rdx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_1_rep_7_1\n"
"br_cond_func_0_block_1_rep_7_1:"
"jmp br_uncond_func_0_block_1_rep_7_0\n"
"br_uncond_func_0_block_1_rep_7_0:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_1_rep_7_2\n"
"br_cond_func_0_block_1_rep_7_2:"
"and rax, rdx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_1_rep_7_3\n"
"br_cond_func_0_block_1_rep_7_3:"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_7_4\n"
"br_cond_func_0_block_1_rep_7_4:"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, rdx\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_7_5\n"
"br_cond_func_0_block_1_rep_7_5:"
"movsd xmm0, QWORD PTR[r10 + 0]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_7_6\n"
"br_cond_func_0_block_1_rep_7_6:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_1_rep_7_asm_end\n"
"func_0_block_1_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_7\n"
"dummy_call_func_0_block_1_rep_7:"
"ret\n"
"end_func_0_block_1_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_8_asm_start\n"
"func_0_block_1_rep_8_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_8_0\n"
"br_cond_func_0_block_1_rep_8_0:"
"sub rbx, QWORD PTR[r10 + 64]\n"
"movsd xmm0, QWORD PTR[r10 + 0]\n"
"and rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rbx, rax\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_1_rep_8_1\n"
"br_cond_func_0_block_1_rep_8_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_8_2\n"
"br_cond_func_0_block_1_rep_8_2:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_8_3\n"
"br_cond_func_0_block_1_rep_8_3:"
"add rcx, QWORD PTR[r10 + 0]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"mov rax, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_8_4\n"
"br_cond_func_0_block_1_rep_8_4:"
"test r11d, 256\n"
"jz br_cond_func_0_block_1_rep_8_5\n"
"br_cond_func_0_block_1_rep_8_5:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_8_6\n"
"br_cond_func_0_block_1_rep_8_6:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_1_rep_8_asm_end\n"
"func_0_block_1_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_8\n"
"dummy_call_func_0_block_1_rep_8:"
"ret\n"
"end_func_0_block_1_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_9_asm_start\n"
"func_0_block_1_rep_9_asm_start:"
"mov rax, rbx\n"
"or rax, QWORD PTR[r10 + 0]\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_9_0\n"
"br_cond_func_0_block_1_rep_9_0:"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_9_1\n"
"br_cond_func_0_block_1_rep_9_1:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_9_2\n"
"br_cond_func_0_block_1_rep_9_2:"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"add rdx, rcx\n"
"add rdx, QWORD PTR[r10 + 64]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_9_3\n"
"br_cond_func_0_block_1_rep_9_3:"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_9_4\n"
"br_cond_func_0_block_1_rep_9_4:"
"mov r13, QWORD PTR[r13]\n"
"sub rdx, rcx\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"mov rdx, rcx\n"
"call dummy_call_func_0_block_1_rep_9\n"
"add rbx, rdx\n"
"mov rcx, rdx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"sub rdx, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_1_rep_9_asm_end\n"
"func_0_block_1_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_9\n"
"dummy_call_func_0_block_1_rep_9:"
"ret\n"
"end_func_0_block_1_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_10_asm_start\n"
"br_uncond_func_0_block_1_rep_10_0:"
"add rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"sub rax, rbx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_10_3\n"
"br_cond_func_0_block_1_rep_10_3:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_10_4\n"
"br_cond_func_0_block_1_rep_10_4:"
"mov rbx, rdx\n"
"mov rdx, rbx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_1_rep_10_5\n"
"br_cond_func_0_block_1_rep_10_5:"
"jmp func_0_block_1_rep_10_asm_end\n"
"func_0_block_1_rep_10_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"mov r13, QWORD PTR[r13]\n"
"sub rdx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"add rdx, rbx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_10_0\n"
"br_cond_func_0_block_1_rep_10_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_10_1\n"
"br_cond_func_0_block_1_rep_10_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_10_2\n"
"br_cond_func_0_block_1_rep_10_2:"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_10_0\n"
"func_0_block_1_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_10\n"
"dummy_call_func_0_block_1_rep_10:"
"ret\n"
"end_func_0_block_1_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_11_asm_start\n"
"func_0_block_1_rep_11_asm_start:"
"or QWORD PTR[r10 + 64], rax\n"
"mov rax, rbx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_11_0\n"
"br_cond_func_0_block_1_rep_11_0:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_1_rep_11_1\n"
"br_cond_func_0_block_1_rep_11_1:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_11_2\n"
"br_cond_func_0_block_1_rep_11_2:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_11_3\n"
"br_cond_func_0_block_1_rep_11_3:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_1_rep_11\n"
"mov rbx, rcx\n"
"call dummy_call_func_0_block_1_rep_11\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_11_4\n"
"br_cond_func_0_block_1_rep_11_4:"
"call dummy_call_func_0_block_1_rep_11\n"
"imul rcx\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rax, QWORD PTR[r10 + 64]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_11_5\n"
"br_cond_func_0_block_1_rep_11_5:"
"mov rax, rbx\n"
"and rax, rcx\n"
"jmp func_0_block_1_rep_11_asm_end\n"
"func_0_block_1_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_11\n"
"dummy_call_func_0_block_1_rep_11:"
"ret\n"
"end_func_0_block_1_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_12_asm_start\n"
"func_0_block_1_rep_12_asm_start:"
"and rax, rbx\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"and rax, QWORD PTR[r10 + 64]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_12_0\n"
"br_cond_func_0_block_1_rep_12_0:"
"mov rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"or rdx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rdx, QWORD PTR[r10 + 0]\n"
"and rsi, rdx\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_12_1\n"
"br_cond_func_0_block_1_rep_12_1:"
"mov rdx, rsi\n"
"jmp br_uncond_func_0_block_1_rep_12_0\n"
"br_uncond_func_0_block_1_rep_12_0:"
"and rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_12_2\n"
"br_cond_func_0_block_1_rep_12_2:"
"mov QWORD PTR[r10 + 0], rdi\n"
"sub rsi, rdi\n"
"mov QWORD PTR[r10 + 64], rsi\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rsi, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_12_asm_end\n"
"func_0_block_1_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_12\n"
"dummy_call_func_0_block_1_rep_12:"
"ret\n"
"end_func_0_block_1_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_13_asm_start\n"
"func_0_block_1_rep_13_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"jmp br_uncond_func_0_block_1_rep_13_0\n"
"br_uncond_func_0_block_1_rep_13_0:"
"or rax, rbx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_13_0\n"
"br_cond_func_0_block_1_rep_13_0:"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_1_rep_13_1\n"
"br_cond_func_0_block_1_rep_13_1:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 64]\n"
"mov rax, rbx\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 64]\n"
"call dummy_call_func_0_block_1_rep_13\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_1_rep_13_2\n"
"br_cond_func_0_block_1_rep_13_2:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_13_3\n"
"br_cond_func_0_block_1_rep_13_3:"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_13_4\n"
"br_cond_func_0_block_1_rep_13_4:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_13_5\n"
"br_cond_func_0_block_1_rep_13_5:"
"mov rbx, rbx\n"
"jmp func_0_block_1_rep_13_asm_end\n"
"func_0_block_1_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_13\n"
"dummy_call_func_0_block_1_rep_13:"
"ret\n"
"end_func_0_block_1_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_14_asm_start\n"
"func_0_block_1_rep_14_asm_start:"
"mov rax, rbx\n"
"mov rbx, rax\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"mov rdx, rcx\n"
"mov rdx, rsi\n"
"jmp br_uncond_func_0_block_1_rep_14_0\n"
"br_uncond_func_0_block_1_rep_14_2:"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_14_asm_end\n"
"br_uncond_func_0_block_1_rep_14_1:"
"imul rdx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_14_1\n"
"br_cond_func_0_block_1_rep_14_1:"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov rsi, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_1_rep_14_2\n"
"br_cond_func_0_block_1_rep_14_2:"
"jmp br_uncond_func_0_block_1_rep_14_2\n"
"br_uncond_func_0_block_1_rep_14_0:"
"mov rsi, rdx\n"
"mov QWORD PTR[r10 + 0], rdi\n"
"mov QWORD PTR[r10 + 64], rsi\n"
"mov rdx, rcx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"sub rsi, rdi\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_14_0\n"
"br_cond_func_0_block_1_rep_14_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_14_1\n"
"func_0_block_1_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_14\n"
"dummy_call_func_0_block_1_rep_14:"
"ret\n"
"end_func_0_block_1_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_15_asm_start\n"
"br_uncond_func_0_block_1_rep_15_1:"
"mov QWORD PTR[r10 + 0], rax\n"
"call dummy_call_func_0_block_1_rep_15\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_15_3\n"
"br_cond_func_0_block_1_rep_15_3:"
"jmp func_0_block_1_rep_15_asm_end\n"
"br_uncond_func_0_block_1_rep_15_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rax\n"
"mov rbx, rcx\n"
"add rax, rbx\n"
"add rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"sub rax, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"or QWORD PTR[r10 + 0], rcx\n"
"mov rcx, rdx\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_15_1\n"
"br_cond_func_0_block_1_rep_15_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_1_rep_15_2\n"
"br_cond_func_0_block_1_rep_15_2:"
"jmp br_uncond_func_0_block_1_rep_15_1\n"
"func_0_block_1_rep_15_asm_start:"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_15_0\n"
"br_cond_func_0_block_1_rep_15_0:"
"jmp br_uncond_func_0_block_1_rep_15_0\n"
"func_0_block_1_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_15\n"
"dummy_call_func_0_block_1_rep_15:"
"ret\n"
"end_func_0_block_1_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 16) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_16_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_16\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_16:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_16_asm_start\n"
"br_uncond_func_0_block_1_rep_16_0:"
"mov r13, QWORD PTR[r13]\n"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_1_rep_16_4\n"
"br_cond_func_0_block_1_rep_16_4:"
"mov rcx, rax\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"sub rdx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_16_5\n"
"br_cond_func_0_block_1_rep_16_5:"
"or rax, rsi\n"
"jmp func_0_block_1_rep_16_asm_end\n"
"func_0_block_1_rep_16_asm_start:"
"or rax, rcx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_16_0\n"
"br_cond_func_0_block_1_rep_16_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_16_1\n"
"br_cond_func_0_block_1_rep_16_1:"
"test r11d, 16\n"
"jz br_cond_func_0_block_1_rep_16_2\n"
"br_cond_func_0_block_1_rep_16_2:"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_16_3\n"
"br_cond_func_0_block_1_rep_16_3:"
"mov rax, rax\n"
"imul rax\n"
"mov rcx, rax\n"
"and rcx, rbx\n"
"jmp br_uncond_func_0_block_1_rep_16_0\n"
"func_0_block_1_rep_16_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_16_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_16\n"
"dummy_call_func_0_block_1_rep_16:"
"ret\n"
"end_func_0_block_1_rep_16:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 17) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_17_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_17\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_17:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_17_asm_start\n"
"func_0_block_1_rep_17_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_17_0\n"
"br_cond_func_0_block_1_rep_17_0:"
"mov rax, rbx\n"
"mov rcx, rbx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_17_1\n"
"br_cond_func_0_block_1_rep_17_1:"
"or rdx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rsi\n"
"and rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"and rdi, QWORD PTR[r10 + 64]\n"
"mov rbx, rcx\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rdx\n"
"add rbx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, rbx\n"
"mov rax, r8\n"
"mov rdx, r8\n"
"jmp func_0_block_1_rep_17_asm_end\n"
"func_0_block_1_rep_17_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_17_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_17\n"
"dummy_call_func_0_block_1_rep_17:"
"ret\n"
"end_func_0_block_1_rep_17:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 18) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_18_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_18\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_18:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_18_asm_start\n"
"func_0_block_1_rep_18_asm_start:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_18_0\n"
"br_cond_func_0_block_1_rep_18_0:"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"and rax, rax\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_1_rep_18_1\n"
"br_cond_func_0_block_1_rep_18_1:"
"and rax, rax\n"
"mov rcx, rbx\n"
"mov rbx, rdx\n"
"mov rbx, rdx\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_1_rep_18_0\n"
"br_uncond_func_0_block_1_rep_18_1:"
"mov rbx, rdx\n"
"mov rcx, rdx\n"
"mov rax, rbx\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_18_asm_end\n"
"br_uncond_func_0_block_1_rep_18_0:"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_18_2\n"
"br_cond_func_0_block_1_rep_18_2:"
"add rbx, rbx\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 64]\n"
"mov rbx, rax\n"
"sub rcx, rbx\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_18_3\n"
"br_cond_func_0_block_1_rep_18_3:"
"mov QWORD PTR[r10 + 0], rcx\n"
"or rcx, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_1_rep_18_1\n"
"func_0_block_1_rep_18_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_18_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_18\n"
"dummy_call_func_0_block_1_rep_18:"
"ret\n"
"end_func_0_block_1_rep_18:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 19) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_19_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_19\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_19:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_19_asm_start\n"
"br_uncond_func_0_block_1_rep_19_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_19_5\n"
"br_cond_func_0_block_1_rep_19_5:"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_19_6\n"
"br_cond_func_0_block_1_rep_19_6:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_19_7\n"
"br_cond_func_0_block_1_rep_19_7:"
"jmp func_0_block_1_rep_19_asm_end\n"
"func_0_block_1_rep_19_asm_start:"
"sub rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_19_0\n"
"br_cond_func_0_block_1_rep_19_0:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_19_1\n"
"br_cond_func_0_block_1_rep_19_1:"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_19_2\n"
"br_cond_func_0_block_1_rep_19_2:"
"and rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, rdx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_19_3\n"
"br_cond_func_0_block_1_rep_19_3:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_1_rep_19_4\n"
"br_cond_func_0_block_1_rep_19_4:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_19_0\n"
"br_uncond_func_0_block_1_rep_19_0:"
"jmp br_uncond_func_0_block_1_rep_19_1\n"
"func_0_block_1_rep_19_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_19_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_19\n"
"dummy_call_func_0_block_1_rep_19:"
"ret\n"
"end_func_0_block_1_rep_19:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 20) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_20_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_20\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_20:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_20_asm_start\n"
"br_uncond_func_0_block_1_rep_20_0:"
"mov rax, rbx\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_1_rep_20_1\n"
"br_uncond_func_0_block_1_rep_20_1:"
"test r11d, 1\n"
"jz br_cond_func_0_block_1_rep_20_3\n"
"br_cond_func_0_block_1_rep_20_3:"
"jmp func_0_block_1_rep_20_asm_end\n"
"func_0_block_1_rep_20_asm_start:"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_1_rep_20_0\n"
"br_cond_func_0_block_1_rep_20_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rbx, rbx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_1_rep_20_1\n"
"br_cond_func_0_block_1_rep_20_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"or QWORD PTR[r10 + 64], rbx\n"
"mov rbx, rcx\n"
"sub rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rax\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"add rbx, rdx\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_20_2\n"
"br_cond_func_0_block_1_rep_20_2:"
"jmp br_uncond_func_0_block_1_rep_20_0\n"
"func_0_block_1_rep_20_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_20_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_20\n"
"dummy_call_func_0_block_1_rep_20:"
"ret\n"
"end_func_0_block_1_rep_20:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 21) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_21_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_21\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_21:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_21_asm_start\n"
"func_0_block_1_rep_21_asm_start:"
"mov rax, rax\n"
"add rax, QWORD PTR[r10 + 64]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_21_0\n"
"br_cond_func_0_block_1_rep_21_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_21_1\n"
"br_cond_func_0_block_1_rep_21_1:"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_21_2\n"
"br_cond_func_0_block_1_rep_21_2:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_1_rep_21_3\n"
"br_cond_func_0_block_1_rep_21_3:"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_1_rep_21_4\n"
"br_cond_func_0_block_1_rep_21_4:"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_21_5\n"
"br_cond_func_0_block_1_rep_21_5:"
"mov rax, rax\n"
"or rax, QWORD PTR[r10 + 0]\n"
"mov rax, rax\n"
"mov rax, rax\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_21_6\n"
"br_cond_func_0_block_1_rep_21_6:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"jmp func_0_block_1_rep_21_asm_end\n"
"func_0_block_1_rep_21_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_21_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_21\n"
"dummy_call_func_0_block_1_rep_21:"
"ret\n"
"end_func_0_block_1_rep_21:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 22) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_22_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_22\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_22:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_22_asm_start\n"
"br_uncond_func_0_block_1_rep_22_1:"
"mov rax, rbx\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_22_3\n"
"br_cond_func_0_block_1_rep_22_3:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_22_4\n"
"br_cond_func_0_block_1_rep_22_4:"
"sub rax, QWORD PTR[r10 + 64]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_22_5\n"
"br_cond_func_0_block_1_rep_22_5:"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_1_rep_22_asm_end\n"
"func_0_block_1_rep_22_asm_start:"
"add rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_1_rep_22\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_1_rep_22_0\n"
"br_cond_func_0_block_1_rep_22_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_22_0\n"
"br_uncond_func_0_block_1_rep_22_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_1_rep_22_1\n"
"br_cond_func_0_block_1_rep_22_1:"
"mov rax, rax\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_22_2\n"
"br_cond_func_0_block_1_rep_22_2:"
"and rbx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_22_1\n"
"func_0_block_1_rep_22_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_22_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_22\n"
"dummy_call_func_0_block_1_rep_22:"
"ret\n"
"end_func_0_block_1_rep_22:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 23) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_23_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_23\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_23:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_23_asm_start\n"
"br_uncond_func_0_block_1_rep_23_0:"
"or rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_23_0\n"
"br_cond_func_0_block_1_rep_23_0:"
"jmp br_uncond_func_0_block_1_rep_23_1\n"
"br_uncond_func_0_block_1_rep_23_1:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_23_1\n"
"br_cond_func_0_block_1_rep_23_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_23_2\n"
"br_cond_func_0_block_1_rep_23_2:"
"or rax, QWORD PTR[r10 + 0]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_23_3\n"
"br_cond_func_0_block_1_rep_23_3:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rbx, rbx\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_1_rep_23_4\n"
"br_cond_func_0_block_1_rep_23_4:"
"and rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"and rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_23_asm_end\n"
"func_0_block_1_rep_23_asm_start:"
"mov QWORD PTR[r10 + 64], rcx\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"jmp br_uncond_func_0_block_1_rep_23_0\n"
"func_0_block_1_rep_23_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_23_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_23\n"
"dummy_call_func_0_block_1_rep_23:"
"ret\n"
"end_func_0_block_1_rep_23:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 24) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_24_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_24\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_24:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_24_asm_start\n"
"func_0_block_1_rep_24_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"call dummy_call_func_0_block_1_rep_24\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_1_rep_24\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"and rcx, rax\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_24_0\n"
"br_cond_func_0_block_1_rep_24_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"jmp br_uncond_func_0_block_1_rep_24_0\n"
"br_uncond_func_0_block_1_rep_24_0:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"add rax, rcx\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_1_rep_24_1\n"
"br_cond_func_0_block_1_rep_24_1:"
"mov rax, rax\n"
"add rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_24_2\n"
"br_cond_func_0_block_1_rep_24_2:"
"mov QWORD PTR[r10 + 64], rax\n"
"add rax, QWORD PTR[r10 + 0]\n"
"mov rax, rax\n"
"jmp func_0_block_1_rep_24_asm_end\n"
"func_0_block_1_rep_24_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_24_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_24\n"
"dummy_call_func_0_block_1_rep_24:"
"ret\n"
"end_func_0_block_1_rep_24:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 25) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_25_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_25\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_25:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_25_asm_start\n"
"func_0_block_1_rep_25_asm_start:"
"call dummy_call_func_0_block_1_rep_25\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"sub rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 64]\n"
"mov rax, rcx\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_25_0\n"
"br_cond_func_0_block_1_rep_25_0:"
"or rdx, rsi\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"and rsi, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_1_rep_25_0\n"
"br_uncond_func_0_block_1_rep_25_0:"
"mov rcx, rax\n"
"mov rsi, rdi\n"
"sub rdx, rbx\n"
"or rbx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rax, QWORD PTR[r10 + 64]\n"
"add r8, rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rsi, rcx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_25_1\n"
"br_cond_func_0_block_1_rep_25_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_25_2\n"
"br_cond_func_0_block_1_rep_25_2:"
"mov rsi, rsi\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_25_3\n"
"br_cond_func_0_block_1_rep_25_3:"
"jmp func_0_block_1_rep_25_asm_end\n"
"func_0_block_1_rep_25_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_25_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_25\n"
"dummy_call_func_0_block_1_rep_25:"
"ret\n"
"end_func_0_block_1_rep_25:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 26) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_26_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_26\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_26:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_26_asm_start\n"
"br_uncond_func_0_block_1_rep_26_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 64]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov rcx, rax\n"
"sub rdx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdi, rsi\n"
"sub rdx, rbx\n"
"jmp br_uncond_func_0_block_1_rep_26_1\n"
"func_0_block_1_rep_26_asm_start:"
"jmp br_uncond_func_0_block_1_rep_26_0\n"
"br_uncond_func_0_block_1_rep_26_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rdx\n"
"mov rbx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_1_rep_26_0\n"
"br_cond_func_0_block_1_rep_26_0:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_26_1\n"
"br_cond_func_0_block_1_rep_26_1:"
"call dummy_call_func_0_block_1_rep_26\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_26_2\n"
"br_cond_func_0_block_1_rep_26_2:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_26_3\n"
"br_cond_func_0_block_1_rep_26_3:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_1_rep_26_4\n"
"br_cond_func_0_block_1_rep_26_4:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_26_asm_end\n"
"br_uncond_func_0_block_1_rep_26_1:"
"mov rbx, rbx\n"
"jmp br_uncond_func_0_block_1_rep_26_2\n"
"func_0_block_1_rep_26_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_26_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_26\n"
"dummy_call_func_0_block_1_rep_26:"
"ret\n"
"end_func_0_block_1_rep_26:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 27) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_27_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_27\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_27:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_27_asm_start\n"
"func_0_block_1_rep_27_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_27_0\n"
"br_cond_func_0_block_1_rep_27_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"or rbx, rbx\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_27_1\n"
"br_cond_func_0_block_1_rep_27_1:"
"mov QWORD PTR[r10 + 64], rbx\n"
"add rax, QWORD PTR[r10 + 0]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_1_rep_27_2\n"
"br_cond_func_0_block_1_rep_27_2:"
"add rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_27_3\n"
"br_cond_func_0_block_1_rep_27_3:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_27_4\n"
"br_cond_func_0_block_1_rep_27_4:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_27_5\n"
"br_cond_func_0_block_1_rep_27_5:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rcx, rcx\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_1_rep_27_6\n"
"br_cond_func_0_block_1_rep_27_6:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_27_asm_end\n"
"func_0_block_1_rep_27_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_27_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_27\n"
"dummy_call_func_0_block_1_rep_27:"
"ret\n"
"end_func_0_block_1_rep_27:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 28) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_28_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_28\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_28:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_28_asm_start\n"
"func_0_block_1_rep_28_asm_start:"
"mov rax, rbx\n"
"add rcx, rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_28_0\n"
"br_cond_func_0_block_1_rep_28_0:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_1_rep_28_1\n"
"br_cond_func_0_block_1_rep_28_1:"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov rcx, rcx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_28_2\n"
"br_cond_func_0_block_1_rep_28_2:"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_28_3\n"
"br_cond_func_0_block_1_rep_28_3:"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_28_4\n"
"br_cond_func_0_block_1_rep_28_4:"
"or rcx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, rbx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_1_rep_28_5\n"
"br_cond_func_0_block_1_rep_28_5:"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rax, rcx\n"
"and rbx, rcx\n"
"and rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_28_6\n"
"br_cond_func_0_block_1_rep_28_6:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_28_asm_end\n"
"func_0_block_1_rep_28_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_28_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_28\n"
"dummy_call_func_0_block_1_rep_28:"
"ret\n"
"end_func_0_block_1_rep_28:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 29) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_29_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_29\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_29:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_29_asm_start\n"
"br_uncond_func_0_block_1_rep_29_1:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rax\n"
"add rbx, rcx\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_1_rep_29_2\n"
"br_cond_func_0_block_1_rep_29_2:"
"mov rdx, rcx\n"
"jmp br_uncond_func_0_block_1_rep_29_2\n"
"br_uncond_func_0_block_1_rep_29_2:"
"and rdx, QWORD PTR[r10 + 0]\n"
"mov rcx, rsi\n"
"or rdx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, rcx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"or rdx, rdx\n"
"add rsi, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_29_3\n"
"br_uncond_func_0_block_1_rep_29_3:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_29_3\n"
"br_cond_func_0_block_1_rep_29_3:"
"jmp func_0_block_1_rep_29_asm_end\n"
"br_uncond_func_0_block_1_rep_29_0:"
"mov rcx, rsi\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_1_rep_29_1\n"
"br_cond_func_0_block_1_rep_29_1:"
"jmp br_uncond_func_0_block_1_rep_29_1\n"
"func_0_block_1_rep_29_asm_start:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_29_0\n"
"br_cond_func_0_block_1_rep_29_0:"
"call dummy_call_func_0_block_1_rep_29\n"
"or rsi, rdx\n"
"mov QWORD PTR[r10 + 0], rdi\n"
"mov rsi, rsi\n"
"jmp br_uncond_func_0_block_1_rep_29_0\n"
"func_0_block_1_rep_29_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_29_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_29\n"
"dummy_call_func_0_block_1_rep_29:"
"ret\n"
"end_func_0_block_1_rep_29:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 30) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_30_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_30\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_30:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_30_asm_start\n"
"func_0_block_1_rep_30_asm_start:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_30_0\n"
"br_cond_func_0_block_1_rep_30_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"and rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"add rax, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rsi\n"
"jmp br_uncond_func_0_block_1_rep_30_0\n"
"br_uncond_func_0_block_1_rep_30_0:"
"add rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"or rsi, rsi\n"
"or rsi, QWORD PTR[r10 + 64]\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_30_1\n"
"br_cond_func_0_block_1_rep_30_1:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_30_2\n"
"br_cond_func_0_block_1_rep_30_2:"
"call dummy_call_func_0_block_1_rep_30\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_30_3\n"
"br_cond_func_0_block_1_rep_30_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_30_4\n"
"br_cond_func_0_block_1_rep_30_4:"
"jmp func_0_block_1_rep_30_asm_end\n"
"func_0_block_1_rep_30_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_30_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_30\n"
"dummy_call_func_0_block_1_rep_30:"
"ret\n"
"end_func_0_block_1_rep_30:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 31) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_31_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_31\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_31:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_31_asm_start\n"
"br_uncond_func_0_block_1_rep_31_3:"
"mov QWORD PTR[r10 + 64], rax\n"
"or rax, rbx\n"
"or rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, rax\n"
"jmp func_0_block_1_rep_31_asm_end\n"
"br_uncond_func_0_block_1_rep_31_0:"
"or rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_1_rep_31_1\n"
"func_0_block_1_rep_31_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_1_rep_31_0\n"
"br_cond_func_0_block_1_rep_31_0:"
"and rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rbx\n"
"jmp br_uncond_func_0_block_1_rep_31_0\n"
"br_uncond_func_0_block_1_rep_31_2:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_1_rep_31_3\n"
"br_uncond_func_0_block_1_rep_31_1:"
"add rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rcx\n"
"mov rdx, rax\n"
"jmp br_uncond_func_0_block_1_rep_31_2\n"
"func_0_block_1_rep_31_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_31_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_31\n"
"dummy_call_func_0_block_1_rep_31:"
"ret\n"
"end_func_0_block_1_rep_31:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 32) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_32_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_32\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_32:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_32_asm_start\n"
"br_uncond_func_0_block_1_rep_32_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_32_1\n"
"br_cond_func_0_block_1_rep_32_1:"
"mov rax, rbx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_1_rep_32_2\n"
"br_cond_func_0_block_1_rep_32_2:"
"sub rax, QWORD PTR[r10 + 0]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_32_3\n"
"br_cond_func_0_block_1_rep_32_3:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, rcx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_32_4\n"
"br_cond_func_0_block_1_rep_32_4:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_32_5\n"
"br_cond_func_0_block_1_rep_32_5:"
"call dummy_call_func_0_block_1_rep_32\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_32_6\n"
"br_cond_func_0_block_1_rep_32_6:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rbx, rbx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_1_rep_32_7\n"
"br_cond_func_0_block_1_rep_32_7:"
"jmp func_0_block_1_rep_32_asm_end\n"
"func_0_block_1_rep_32_asm_start:"
"or rcx, rbx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_32_0\n"
"br_cond_func_0_block_1_rep_32_0:"
"jmp br_uncond_func_0_block_1_rep_32_0\n"
"func_0_block_1_rep_32_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_32_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_32\n"
"dummy_call_func_0_block_1_rep_32:"
"ret\n"
"end_func_0_block_1_rep_32:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 33) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_33_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_33\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_33:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_33_asm_start\n"
"br_uncond_func_0_block_1_rep_33_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_33_1\n"
"br_cond_func_0_block_1_rep_33_1:"
"or rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_1_rep_33\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_33_2\n"
"br_cond_func_0_block_1_rep_33_2:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_1_rep_33_3\n"
"br_cond_func_0_block_1_rep_33_3:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_1_rep_33_4\n"
"br_cond_func_0_block_1_rep_33_4:"
"call dummy_call_func_0_block_1_rep_33\n"
"jmp br_uncond_func_0_block_1_rep_33_1\n"
"func_0_block_1_rep_33_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_1_rep_33_0\n"
"br_cond_func_0_block_1_rep_33_0:"
"add rbx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_1_rep_33_0\n"
"br_uncond_func_0_block_1_rep_33_1:"
"jmp func_0_block_1_rep_33_asm_end\n"
"func_0_block_1_rep_33_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_33_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_33\n"
"dummy_call_func_0_block_1_rep_33:"
"ret\n"
"end_func_0_block_1_rep_33:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 34) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_34_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_34\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_34:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_34_asm_start\n"
"br_uncond_func_0_block_1_rep_34_1:"
"add rax, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_1_rep_34_2\n"
"br_cond_func_0_block_1_rep_34_2:"
"jmp func_0_block_1_rep_34_asm_end\n"
"br_uncond_func_0_block_1_rep_34_0:"
"sub rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_34_1\n"
"br_cond_func_0_block_1_rep_34_1:"
"jmp br_uncond_func_0_block_1_rep_34_1\n"
"func_0_block_1_rep_34_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rdx, rbx\n"
"call dummy_call_func_0_block_1_rep_34\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_34_0\n"
"br_cond_func_0_block_1_rep_34_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_34_0\n"
"func_0_block_1_rep_34_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_34_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_34\n"
"dummy_call_func_0_block_1_rep_34:"
"ret\n"
"end_func_0_block_1_rep_34:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 35) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_35_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_35\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_35:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_35_asm_start\n"
"func_0_block_1_rep_35_asm_start:"
"add QWORD PTR[r10 + 64], rax\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_1_rep_35_0\n"
"br_uncond_func_0_block_1_rep_35_0:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_35_0\n"
"br_cond_func_0_block_1_rep_35_0:"
"test r11d, 128\n"
"jz br_cond_func_0_block_1_rep_35_1\n"
"br_cond_func_0_block_1_rep_35_1:"
"sub rbx, rbx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_35_2\n"
"br_cond_func_0_block_1_rep_35_2:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_35_3\n"
"br_cond_func_0_block_1_rep_35_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov rcx, rdx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"mov rsi, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_1_rep_35_4\n"
"br_cond_func_0_block_1_rep_35_4:"
"jmp func_0_block_1_rep_35_asm_end\n"
"func_0_block_1_rep_35_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_35_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_35\n"
"dummy_call_func_0_block_1_rep_35:"
"ret\n"
"end_func_0_block_1_rep_35:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 36) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_36_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_36\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_36:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_36_asm_start\n"
"func_0_block_1_rep_36_asm_start:"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_36_0\n"
"br_cond_func_0_block_1_rep_36_0:"
"mov r13, QWORD PTR[r13]\n"
"add rax, rax\n"
"jmp br_uncond_func_0_block_1_rep_36_0\n"
"br_uncond_func_0_block_1_rep_36_0:"
"or rax, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_36_1\n"
"br_cond_func_0_block_1_rep_36_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rdx, rcx\n"
"mov rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_36_2\n"
"br_cond_func_0_block_1_rep_36_2:"
"mov rbx, rax\n"
"and rax, QWORD PTR[r10 + 64]\n"
"and rcx, QWORD PTR[r10 + 0]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"or rdx, QWORD PTR[r10 + 0]\n"
"and rdx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rsi\n"
"mov rsi, rbx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_36_3\n"
"br_cond_func_0_block_1_rep_36_3:"
"jmp func_0_block_1_rep_36_asm_end\n"
"func_0_block_1_rep_36_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_36_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_36\n"
"dummy_call_func_0_block_1_rep_36:"
"ret\n"
"end_func_0_block_1_rep_36:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 37) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_37_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_37\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_37:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_37_asm_start\n"
"br_uncond_func_0_block_1_rep_37_0:"
"and rax, rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_1_rep_37_1\n"
"br_cond_func_0_block_1_rep_37_1:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_37_2\n"
"br_cond_func_0_block_1_rep_37_2:"
"and rbx, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov rcx, rdx\n"
"sub rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, rbx\n"
"mov rcx, rax\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_1_rep_37_1\n"
"br_uncond_func_0_block_1_rep_37_1:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_1_rep_37_3\n"
"br_cond_func_0_block_1_rep_37_3:"
"jmp func_0_block_1_rep_37_asm_end\n"
"func_0_block_1_rep_37_asm_start:"
"or rcx, QWORD PTR[r10 + 64]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_1_rep_37_0\n"
"br_cond_func_0_block_1_rep_37_0:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp br_uncond_func_0_block_1_rep_37_0\n"
"func_0_block_1_rep_37_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_37_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_37\n"
"dummy_call_func_0_block_1_rep_37:"
"ret\n"
"end_func_0_block_1_rep_37:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 38) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_38_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_38\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_38:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_38_asm_start\n"
"func_0_block_1_rep_38_asm_start:"
"sub QWORD PTR[r10 + 64], rax\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_38_0\n"
"br_cond_func_0_block_1_rep_38_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_38_1\n"
"br_cond_func_0_block_1_rep_38_1:"
"add rax, rax\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_1_rep_38_2\n"
"br_cond_func_0_block_1_rep_38_2:"
"imul rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, rcx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rcx, rax\n"
"mov rdx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_1_rep_38\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, QWORD PTR[r10 + 64]\n"
"call dummy_call_func_0_block_1_rep_38\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_38_3\n"
"br_cond_func_0_block_1_rep_38_3:"
"mov QWORD PTR[r10 + 0], rdx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"and rbx, QWORD PTR[r10 + 64]\n"
"and rdx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, rdx\n"
"jmp func_0_block_1_rep_38_asm_end\n"
"func_0_block_1_rep_38_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_38_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_38\n"
"dummy_call_func_0_block_1_rep_38:"
"ret\n"
"end_func_0_block_1_rep_38:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 39) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_39_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_39\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_39:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_39_asm_start\n"
"func_0_block_1_rep_39_asm_start:"
"or rax, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_39_0\n"
"br_cond_func_0_block_1_rep_39_0:"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 64]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_39_1\n"
"br_cond_func_0_block_1_rep_39_1:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_1_rep_39_2\n"
"br_cond_func_0_block_1_rep_39_2:"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_39_3\n"
"br_cond_func_0_block_1_rep_39_3:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_1_rep_39_4\n"
"br_cond_func_0_block_1_rep_39_4:"
"call dummy_call_func_0_block_1_rep_39\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_39_5\n"
"br_cond_func_0_block_1_rep_39_5:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_1_rep_39_asm_end\n"
"func_0_block_1_rep_39_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_39_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_39\n"
"dummy_call_func_0_block_1_rep_39:"
"ret\n"
"end_func_0_block_1_rep_39:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 40) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_40_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_40\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_40:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_40_asm_start\n"
"func_0_block_1_rep_40_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_40_0\n"
"br_cond_func_0_block_1_rep_40_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_40_1\n"
"br_cond_func_0_block_1_rep_40_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"mov rcx, rcx\n"
"call dummy_call_func_0_block_1_rep_40\n"
"mov rax, rdx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_1_rep_40_2\n"
"br_cond_func_0_block_1_rep_40_2:"
"mov QWORD PTR[r10 + 64], rdx\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_1_rep_40_3\n"
"br_cond_func_0_block_1_rep_40_3:"
"mov QWORD PTR[r10 + 0], rdx\n"
"jmp func_0_block_1_rep_40_asm_end\n"
"func_0_block_1_rep_40_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_40_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_40\n"
"dummy_call_func_0_block_1_rep_40:"
"ret\n"
"end_func_0_block_1_rep_40:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 41) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_41_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_41\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_41:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_41_asm_start\n"
"br_uncond_func_0_block_1_rep_41_0:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_1_rep_41_2\n"
"br_cond_func_0_block_1_rep_41_2:"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_41_3\n"
"br_cond_func_0_block_1_rep_41_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_41_4\n"
"br_cond_func_0_block_1_rep_41_4:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_41_5\n"
"br_cond_func_0_block_1_rep_41_5:"
"or rax, rbx\n"
"mov rcx, rax\n"
"jmp br_uncond_func_0_block_1_rep_41_1\n"
"br_uncond_func_0_block_1_rep_41_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_41_6\n"
"br_cond_func_0_block_1_rep_41_6:"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_1_rep_41_asm_end\n"
"func_0_block_1_rep_41_asm_start:"
"mov rbx, rbx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_1_rep_41_0\n"
"br_cond_func_0_block_1_rep_41_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_41_1\n"
"br_cond_func_0_block_1_rep_41_1:"
"jmp br_uncond_func_0_block_1_rep_41_0\n"
"func_0_block_1_rep_41_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_41_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_41\n"
"dummy_call_func_0_block_1_rep_41:"
"ret\n"
"end_func_0_block_1_rep_41:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 42) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_42_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_42\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_42:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_42_asm_start\n"
"func_0_block_1_rep_42_asm_start:"
"mov rax, rbx\n"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_42_0\n"
"br_uncond_func_0_block_1_rep_42_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_1_rep_42_1\n"
"br_uncond_func_0_block_1_rep_42_1:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_1_rep_42_0\n"
"br_cond_func_0_block_1_rep_42_0:"
"mov rbx, rax\n"
"mov rcx, rbx\n"
"mov rbx, rdx\n"
"add QWORD PTR[r10 + 0], rcx\n"
"and rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_42_1\n"
"br_cond_func_0_block_1_rep_42_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"mov rax, rdx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_42_2\n"
"br_cond_func_0_block_1_rep_42_2:"
"sub rax, rax\n"
"mov rax, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_42_3\n"
"br_cond_func_0_block_1_rep_42_3:"
"jmp func_0_block_1_rep_42_asm_end\n"
"func_0_block_1_rep_42_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_42_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_42\n"
"dummy_call_func_0_block_1_rep_42:"
"ret\n"
"end_func_0_block_1_rep_42:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 43) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_43_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_43\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_43:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_43_asm_start\n"
"br_uncond_func_0_block_1_rep_43_0:"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_43_2\n"
"br_cond_func_0_block_1_rep_43_2:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"and QWORD PTR[r10 + 0], rbx\n"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"and rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_1_rep_43_3\n"
"br_cond_func_0_block_1_rep_43_3:"
"jmp func_0_block_1_rep_43_asm_end\n"
"func_0_block_1_rep_43_asm_start:"
"mov rcx, rdx\n"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rsi, rax\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"add rsi, rsi\n"
"add rsi, rcx\n"
"or QWORD PTR[r10 + 64], rsi\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov rsi, rbx\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_1_rep_43_0\n"
"br_cond_func_0_block_1_rep_43_0:"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_43_1\n"
"br_cond_func_0_block_1_rep_43_1:"
"jmp br_uncond_func_0_block_1_rep_43_0\n"
"func_0_block_1_rep_43_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_43_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_43\n"
"dummy_call_func_0_block_1_rep_43:"
"ret\n"
"end_func_0_block_1_rep_43:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 44) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_44_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_44\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_44:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_44_asm_start\n"
"func_0_block_1_rep_44_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_1_rep_44_0\n"
"br_cond_func_0_block_1_rep_44_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rbx, QWORD PTR[r10 + 64]\n"
"mov rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_1_rep_44_1\n"
"br_cond_func_0_block_1_rep_44_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rcx\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rbx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rcx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_1_rep_44_2\n"
"br_cond_func_0_block_1_rep_44_2:"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_1_rep_44_3\n"
"br_cond_func_0_block_1_rep_44_3:"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rdx, rdx\n"
"jmp func_0_block_1_rep_44_asm_end\n"
"func_0_block_1_rep_44_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_44_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_44\n"
"dummy_call_func_0_block_1_rep_44:"
"ret\n"
"end_func_0_block_1_rep_44:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 45) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_45_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_45\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_45:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_45_asm_start\n"
"br_uncond_func_0_block_1_rep_45_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_1_rep_45_1\n"
"br_cond_func_0_block_1_rep_45_1:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rcx, rbx\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_1_rep_45_2\n"
"br_cond_func_0_block_1_rep_45_2:"
"mov rbx, rdx\n"
"mov rax, rbx\n"
"add rdx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rsi\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_1_rep_45_3\n"
"br_cond_func_0_block_1_rep_45_3:"
"jmp func_0_block_1_rep_45_asm_end\n"
"func_0_block_1_rep_45_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"or rcx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_1_rep_45_0\n"
"br_cond_func_0_block_1_rep_45_0:"
"sub rcx, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_1_rep_45_0\n"
"func_0_block_1_rep_45_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_45_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_45\n"
"dummy_call_func_0_block_1_rep_45:"
"ret\n"
"end_func_0_block_1_rep_45:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 46) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_46_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_46\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_46:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_46_asm_start\n"
"func_0_block_1_rep_46_asm_start:"
"mov rax, rbx\n"
"and rax, rax\n"
"mov rax, rbx\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"mov rax, rcx\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"add rax, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"mov rax, rcx\n"
"or rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"sub rcx, rbx\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_46_0\n"
"br_cond_func_0_block_1_rep_46_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_1_rep_46_1\n"
"br_cond_func_0_block_1_rep_46_1:"
"test r11d, 8\n"
"jz br_cond_func_0_block_1_rep_46_2\n"
"br_cond_func_0_block_1_rep_46_2:"
"mov QWORD PTR[r10 + 0], rdx\n"
"sub rdx, rbx\n"
"mov QWORD PTR[r10 + 64], rsi\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_1_rep_46_3\n"
"br_cond_func_0_block_1_rep_46_3:"
"jmp func_0_block_1_rep_46_asm_end\n"
"func_0_block_1_rep_46_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_46_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_46\n"
"dummy_call_func_0_block_1_rep_46:"
"ret\n"
"end_func_0_block_1_rep_46:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 47) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_47_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_47\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_47:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_47_asm_start\n"
"func_0_block_1_rep_47_asm_start:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_47_0\n"
"br_cond_func_0_block_1_rep_47_0:"
"mov rax, rbx\n"
"and rbx, rcx\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_1_rep_47_1\n"
"br_cond_func_0_block_1_rep_47_1:"
"sub rdx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_1_rep_47_0\n"
"br_uncond_func_0_block_1_rep_47_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_47_6\n"
"br_cond_func_0_block_1_rep_47_6:"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rbx\n"
"add rdx, rdx\n"
"or rdx, rcx\n"
"mov rax, rdx\n"
"jmp func_0_block_1_rep_47_asm_end\n"
"br_uncond_func_0_block_1_rep_47_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_1_rep_47_2\n"
"br_cond_func_0_block_1_rep_47_2:"
"call dummy_call_func_0_block_1_rep_47\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_1_rep_47_3\n"
"br_cond_func_0_block_1_rep_47_3:"
"mov rcx, rsi\n"
"mov rsi, rcx\n"
"mov rsi, rdi\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_47_4\n"
"br_cond_func_0_block_1_rep_47_4:"
"call dummy_call_func_0_block_1_rep_47\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_1_rep_47_5\n"
"br_cond_func_0_block_1_rep_47_5:"
"jmp br_uncond_func_0_block_1_rep_47_1\n"
"func_0_block_1_rep_47_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_47_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_47\n"
"dummy_call_func_0_block_1_rep_47:"
"ret\n"
"end_func_0_block_1_rep_47:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 48) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_48_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_48\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_48:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_48_asm_start\n"
"func_0_block_1_rep_48_asm_start:"
"mov rax, rbx\n"
"add rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rdx\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_1_rep_48_0\n"
"br_cond_func_0_block_1_rep_48_0:"
"mov rbx, rdx\n"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, QWORD PTR[r10 + 0]\n"
"mov rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_1_rep_48\n"
"and rdx, rbx\n"
"and rdx, QWORD PTR[r10 + 64]\n"
"sub rdx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"or rdx, rax\n"
"mov rdx, rax\n"
"and rdx, rax\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"sub rbx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rsi\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_48_1\n"
"br_cond_func_0_block_1_rep_48_1:"
"mov QWORD PTR[r10 + 64], rsi\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_1_rep_48_2\n"
"br_cond_func_0_block_1_rep_48_2:"
"jmp func_0_block_1_rep_48_asm_end\n"
"func_0_block_1_rep_48_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_48_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_48\n"
"dummy_call_func_0_block_1_rep_48:"
"ret\n"
"end_func_0_block_1_rep_48:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 354 && (req_id & 1023) < 451 && (req_id % 50) == 49) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_1_rep_49_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_1_rep_49\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_1_rep_49:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_1_rep_49_asm_start\n"
"func_0_block_1_rep_49_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"sub rbx, rcx\n"
"mov rcx, rdx\n"
"add rsi, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_1_rep_49_0\n"
"br_cond_func_0_block_1_rep_49_0:"
"and rsi, QWORD PTR[r10 + 64]\n"
"sub rsi, rdx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_1_rep_49_1\n"
"br_cond_func_0_block_1_rep_49_1:"
"mov rdi, rsi\n"
"and rdi, QWORD PTR[r10 + 0]\n"
"sub rdi, QWORD PTR[r10 + 64]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_49_2\n"
"br_cond_func_0_block_1_rep_49_2:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_1_rep_49_3\n"
"br_cond_func_0_block_1_rep_49_3:"
"call dummy_call_func_0_block_1_rep_49\n"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"or rdx, QWORD PTR[r10 + 0]\n"
"or r8, rcx\n"
"mov QWORD PTR[r10 + 64], rsi\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_1_rep_49_4\n"
"br_cond_func_0_block_1_rep_49_4:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_1_rep_49_5\n"
"br_cond_func_0_block_1_rep_49_5:"
"or r9, QWORD PTR[r10 + 0]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_1_rep_49_6\n"
"br_cond_func_0_block_1_rep_49_6:"
"jmp func_0_block_1_rep_49_asm_end\n"
"func_0_block_1_rep_49_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_1_rep_49_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_1_rep_49\n"
"dummy_call_func_0_block_1_rep_49:"
"ret\n"
"end_func_0_block_1_rep_49:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[1]), "r" (curr_pointer_chasing_mem_addrs[1]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[1] = next_mem_addr;
curr_pointer_chasing_mem_addrs[1] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_0_asm_start\n"
"func_0_block_2_rep_0_asm_start:"
"or rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rax, rax\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"sub rdx, rbx\n"
"mov rcx, rsi\n"
"mov rdi, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_2_rep_0\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_2_rep_0_0\n"
"br_cond_func_0_block_2_rep_0_0:"
"add rcx, QWORD PTR[r10 + 192]\n"
"mov rbx, rsi\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_0_1\n"
"br_cond_func_0_block_2_rep_0_1:"
"call dummy_call_func_0_block_2_rep_0\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"mov r13, QWORD PTR[r13]\n"
"imul rbx\n"
"call dummy_call_func_0_block_2_rep_0\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_0_2\n"
"br_cond_func_0_block_2_rep_0_2:"
"mov rdi, rbx\n"
"sub QWORD PTR[r10 + 192], rdi\n"
"jmp func_0_block_2_rep_0_asm_end\n"
"func_0_block_2_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_0\n"
"dummy_call_func_0_block_2_rep_0:"
"ret\n"
"end_func_0_block_2_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_1_asm_start\n"
"func_0_block_2_rep_1_asm_start:"
"and rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_2_rep_1_0\n"
"br_cond_func_0_block_2_rep_1_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_1_1\n"
"br_cond_func_0_block_2_rep_1_1:"
"mov rbx, rbx\n"
"sub rax, QWORD PTR[r10 + 192]\n"
"or rbx, rax\n"
"mov rcx, rdx\n"
"or rax, rdx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_1_2\n"
"br_cond_func_0_block_2_rep_1_2:"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, QWORD PTR[r10 + 128]\n"
"mov rsi, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_2_rep_1_3\n"
"br_cond_func_0_block_2_rep_1_3:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_1_asm_end\n"
"func_0_block_2_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_1\n"
"dummy_call_func_0_block_2_rep_1:"
"ret\n"
"end_func_0_block_2_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_2_asm_start\n"
"func_0_block_2_rep_2_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_2_rep_2_0\n"
"br_cond_func_0_block_2_rep_2_0:"
"or rcx, QWORD PTR[r10 + 192]\n"
"mov rdx, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_2_rep_2_1\n"
"br_cond_func_0_block_2_rep_2_1:"
"test r11d, 131072\n"
"jz br_cond_func_0_block_2_rep_2_2\n"
"br_cond_func_0_block_2_rep_2_2:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_2_3\n"
"br_cond_func_0_block_2_rep_2_3:"
"mov QWORD PTR[r10 + 128], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"and rbx, rsi\n"
"sub rbx, rbx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_2_rep_2_4\n"
"br_cond_func_0_block_2_rep_2_4:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_2_rep_2_5\n"
"br_cond_func_0_block_2_rep_2_5:"
"and rax, QWORD PTR[r10 + 0]\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_2_rep_2_6\n"
"br_cond_func_0_block_2_rep_2_6:"
"and rax, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 192], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_2_asm_end\n"
"func_0_block_2_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_2\n"
"dummy_call_func_0_block_2_rep_2:"
"ret\n"
"end_func_0_block_2_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_3_asm_start\n"
"func_0_block_2_rep_3_asm_start:"
"mov rax, rbx\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_2_rep_3_0\n"
"br_cond_func_0_block_2_rep_3_0:"
"mov QWORD PTR[r10 + 128], rbx\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_2_rep_3_1\n"
"br_cond_func_0_block_2_rep_3_1:"
"mov rax, rax\n"
"call dummy_call_func_0_block_2_rep_3\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_2_rep_3_2\n"
"br_cond_func_0_block_2_rep_3_2:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, rbx\n"
"add rax, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rax, rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_3_3\n"
"br_cond_func_0_block_2_rep_3_3:"
"and rax, QWORD PTR[r10 + 192]\n"
"mov rbx, rcx\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"add rdx, rbx\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"add rcx, rax\n"
"or rdx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_2_rep_3_asm_end\n"
"func_0_block_2_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_3\n"
"dummy_call_func_0_block_2_rep_3:"
"ret\n"
"end_func_0_block_2_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_4_asm_start\n"
"br_uncond_func_0_block_2_rep_4_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_2_rep_4_2\n"
"br_cond_func_0_block_2_rep_4_2:"
"test r11d, 16\n"
"jz br_cond_func_0_block_2_rep_4_3\n"
"br_cond_func_0_block_2_rep_4_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"jmp func_0_block_2_rep_4_asm_end\n"
"func_0_block_2_rep_4_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"movsd xmm0, QWORD PTR[r10 + 192]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rcx, rbx\n"
"mov rcx, rcx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_4_0\n"
"br_cond_func_0_block_2_rep_4_0:"
"and rcx, QWORD PTR[r10 + 0]\n"
"mov rbx, rcx\n"
"and rbx, QWORD PTR[r10 + 192]\n"
"mov rax, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_4_1\n"
"br_cond_func_0_block_2_rep_4_1:"
"mov r13, QWORD PTR[r13]\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_2_rep_4_0\n"
"func_0_block_2_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_4\n"
"dummy_call_func_0_block_2_rep_4:"
"ret\n"
"end_func_0_block_2_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_5_asm_start\n"
"br_uncond_func_0_block_2_rep_5_1:"
"jmp br_uncond_func_0_block_2_rep_5_2\n"
"func_0_block_2_rep_5_asm_start:"
"jmp br_uncond_func_0_block_2_rep_5_0\n"
"br_uncond_func_0_block_2_rep_5_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_5_1\n"
"br_uncond_func_0_block_2_rep_5_2:"
"mov QWORD PTR[r10 + 192], rax\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_5_0\n"
"br_cond_func_0_block_2_rep_5_0:"
"add rax, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"or rax, QWORD PTR[r10 + 0]\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"or rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_5_1\n"
"br_cond_func_0_block_2_rep_5_1:"
"mov QWORD PTR[r10 + 192], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_2_rep_5\n"
"add rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov rax, rax\n"
"sub rcx, rbx\n"
"jmp func_0_block_2_rep_5_asm_end\n"
"func_0_block_2_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_5\n"
"dummy_call_func_0_block_2_rep_5:"
"ret\n"
"end_func_0_block_2_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_6_asm_start\n"
"br_uncond_func_0_block_2_rep_6_0:"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_6_1\n"
"br_cond_func_0_block_2_rep_6_1:"
"jmp func_0_block_2_rep_6_asm_end\n"
"func_0_block_2_rep_6_asm_start:"
"add rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rbx\n"
"mov rbx, rdx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mul rcx\n"
"sub rdx, rdx\n"
"mov rbx, rdx\n"
"add rsi, rcx\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rsi, QWORD PTR[r10 + 64]\n"
"mov rsi, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 128]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_2_rep_6_0\n"
"br_cond_func_0_block_2_rep_6_0:"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"or rdi, r8\n"
"mov QWORD PTR[r10 + 64], rdi\n"
"mov rcx, rdi\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_6_0\n"
"func_0_block_2_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_6\n"
"dummy_call_func_0_block_2_rep_6:"
"ret\n"
"end_func_0_block_2_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_7_asm_start\n"
"func_0_block_2_rep_7_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_7_0\n"
"br_uncond_func_0_block_2_rep_7_1:"
"and rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 192]\n"
"mov rcx, rdx\n"
"or rax, rbx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_7_3\n"
"br_cond_func_0_block_2_rep_7_3:"
"jmp br_uncond_func_0_block_2_rep_7_2\n"
"br_uncond_func_0_block_2_rep_7_2:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_7_4\n"
"br_cond_func_0_block_2_rep_7_4:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"jmp func_0_block_2_rep_7_asm_end\n"
"br_uncond_func_0_block_2_rep_7_0:"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_7_0\n"
"br_cond_func_0_block_2_rep_7_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"and QWORD PTR[r10 + 192], rdx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rcx\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_2_rep_7_1\n"
"br_cond_func_0_block_2_rep_7_1:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_2_rep_7_2\n"
"br_cond_func_0_block_2_rep_7_2:"
"and rcx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_7_1\n"
"func_0_block_2_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_7\n"
"dummy_call_func_0_block_2_rep_7:"
"ret\n"
"end_func_0_block_2_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_8_asm_start\n"
"br_uncond_func_0_block_2_rep_8_0:"
"and rax, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"jmp func_0_block_2_rep_8_asm_end\n"
"func_0_block_2_rep_8_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, rbx\n"
"call dummy_call_func_0_block_2_rep_8\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 192], rdx\n"
"add rbx, rcx\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rdx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_8_0\n"
"func_0_block_2_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_8\n"
"dummy_call_func_0_block_2_rep_8:"
"ret\n"
"end_func_0_block_2_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_9_asm_start\n"
"func_0_block_2_rep_9_asm_start:"
"mov rax, rbx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_2_rep_9_0\n"
"br_cond_func_0_block_2_rep_9_0:"
"or rax, rax\n"
"mov rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"or rdx, QWORD PTR[r10 + 0]\n"
"call dummy_call_func_0_block_2_rep_9\n"
"sub rdx, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"or rbx, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_9_1\n"
"br_cond_func_0_block_2_rep_9_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_9_2\n"
"br_cond_func_0_block_2_rep_9_2:"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_9_3\n"
"br_cond_func_0_block_2_rep_9_3:"
"call dummy_call_func_0_block_2_rep_9\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_9_4\n"
"br_cond_func_0_block_2_rep_9_4:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_9_5\n"
"br_cond_func_0_block_2_rep_9_5:"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_9_6\n"
"br_cond_func_0_block_2_rep_9_6:"
"jmp func_0_block_2_rep_9_asm_end\n"
"func_0_block_2_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_9\n"
"dummy_call_func_0_block_2_rep_9:"
"ret\n"
"end_func_0_block_2_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_10_asm_start\n"
"func_0_block_2_rep_10_asm_start:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_10_0\n"
"br_cond_func_0_block_2_rep_10_0:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 64]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_10_1\n"
"br_cond_func_0_block_2_rep_10_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_2_rep_10_2\n"
"br_cond_func_0_block_2_rep_10_2:"
"and rax, QWORD PTR[r10 + 192]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_10_3\n"
"br_cond_func_0_block_2_rep_10_3:"
"sub rax, QWORD PTR[r10 + 0]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_2_rep_10_4\n"
"br_cond_func_0_block_2_rep_10_4:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_10_5\n"
"br_cond_func_0_block_2_rep_10_5:"
"mov rax, rax\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_10_6\n"
"br_cond_func_0_block_2_rep_10_6:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_2_rep_10_7\n"
"br_cond_func_0_block_2_rep_10_7:"
"add rbx, rcx\n"
"and rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rdx\n"
"jmp func_0_block_2_rep_10_asm_end\n"
"func_0_block_2_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_10\n"
"dummy_call_func_0_block_2_rep_10:"
"ret\n"
"end_func_0_block_2_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_11_asm_start\n"
"func_0_block_2_rep_11_asm_start:"
"test r11d, 16\n"
"jz br_cond_func_0_block_2_rep_11_0\n"
"br_cond_func_0_block_2_rep_11_0:"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_11_1\n"
"br_cond_func_0_block_2_rep_11_1:"
"mov rax, rax\n"
"mov rbx, rcx\n"
"mov rax, rcx\n"
"mov rax, rcx\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_11_2\n"
"br_cond_func_0_block_2_rep_11_2:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_11_3\n"
"br_cond_func_0_block_2_rep_11_3:"
"test r11d, 4096\n"
"jz br_cond_func_0_block_2_rep_11_4\n"
"br_cond_func_0_block_2_rep_11_4:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_11_5\n"
"br_cond_func_0_block_2_rep_11_5:"
"add rcx, rdx\n"
"add QWORD PTR[r10 + 64], rcx\n"
"call dummy_call_func_0_block_2_rep_11\n"
"sub rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rcx\n"
"mov rcx, rax\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"mov rcx, rcx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_11_6\n"
"br_cond_func_0_block_2_rep_11_6:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_11_7\n"
"br_cond_func_0_block_2_rep_11_7:"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_2_rep_11_8\n"
"br_cond_func_0_block_2_rep_11_8:"
"jmp func_0_block_2_rep_11_asm_end\n"
"func_0_block_2_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_11\n"
"dummy_call_func_0_block_2_rep_11:"
"ret\n"
"end_func_0_block_2_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_12_asm_start\n"
"func_0_block_2_rep_12_asm_start:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"call dummy_call_func_0_block_2_rep_12\n"
"jmp br_uncond_func_0_block_2_rep_12_0\n"
"br_uncond_func_0_block_2_rep_12_1:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_12_asm_end\n"
"br_uncond_func_0_block_2_rep_12_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rcx\n"
"mov rcx, rbx\n"
"mov rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_12_0\n"
"br_cond_func_0_block_2_rep_12_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_12_1\n"
"br_cond_func_0_block_2_rep_12_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 64]\n"
"add rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_2_rep_12_1\n"
"func_0_block_2_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_12\n"
"dummy_call_func_0_block_2_rep_12:"
"ret\n"
"end_func_0_block_2_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_13_asm_start\n"
"func_0_block_2_rep_13_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_2_rep_13_0\n"
"br_cond_func_0_block_2_rep_13_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"mov rdx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rdx\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov rbx, rdx\n"
"mov rdx, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rdx, rdx\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"sub rsi, rbx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_2_rep_13_1\n"
"br_cond_func_0_block_2_rep_13_1:"
"mov r13, QWORD PTR[r13]\n"
"or rsi, rsi\n"
"mov QWORD PTR[r10 + 192], rsi\n"
"mov rax, rsi\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"add rsi, QWORD PTR[r10 + 0]\n"
"sub rsi, rax\n"
"mov QWORD PTR[r10 + 128], rsi\n"
"jmp func_0_block_2_rep_13_asm_end\n"
"func_0_block_2_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_13\n"
"dummy_call_func_0_block_2_rep_13:"
"ret\n"
"end_func_0_block_2_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_14_asm_start\n"
"br_uncond_func_0_block_2_rep_14_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_2_rep_14_3\n"
"br_cond_func_0_block_2_rep_14_3:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_14_1\n"
"func_0_block_2_rep_14_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_14_0\n"
"br_cond_func_0_block_2_rep_14_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_14_1\n"
"br_cond_func_0_block_2_rep_14_1:"
"test r11d, 1\n"
"jz br_cond_func_0_block_2_rep_14_2\n"
"br_cond_func_0_block_2_rep_14_2:"
"jmp br_uncond_func_0_block_2_rep_14_0\n"
"br_uncond_func_0_block_2_rep_14_1:"
"sub rax, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"jmp func_0_block_2_rep_14_asm_end\n"
"func_0_block_2_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_14\n"
"dummy_call_func_0_block_2_rep_14:"
"ret\n"
"end_func_0_block_2_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_15_asm_start\n"
"func_0_block_2_rep_15_asm_start:"
"sub rax, QWORD PTR[r10 + 64]\n"
"sub rax, rax\n"
"mov rbx, rcx\n"
"add rbx, rcx\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_15_0\n"
"br_cond_func_0_block_2_rep_15_0:"
"or rcx, QWORD PTR[r10 + 0]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_2_rep_15_1\n"
"br_cond_func_0_block_2_rep_15_1:"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_2_rep_15_2\n"
"br_cond_func_0_block_2_rep_15_2:"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rax\n"
"mov rax, rcx\n"
"mov rax, rax\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_2_rep_15_3\n"
"br_cond_func_0_block_2_rep_15_3:"
"mov rcx, rax\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_15_4\n"
"br_cond_func_0_block_2_rep_15_4:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_2_rep_15_5\n"
"br_cond_func_0_block_2_rep_15_5:"
"jmp func_0_block_2_rep_15_asm_end\n"
"func_0_block_2_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_15\n"
"dummy_call_func_0_block_2_rep_15:"
"ret\n"
"end_func_0_block_2_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 16) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_16_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_16\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_16:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_16_asm_start\n"
"func_0_block_2_rep_16_asm_start:"
"mov rax, rbx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_16_0\n"
"br_cond_func_0_block_2_rep_16_0:"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_16_1\n"
"br_cond_func_0_block_2_rep_16_1:"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_16_2\n"
"br_cond_func_0_block_2_rep_16_2:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, rbx\n"
"and rax, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"or rcx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_16_3\n"
"br_cond_func_0_block_2_rep_16_3:"
"jmp func_0_block_2_rep_16_asm_end\n"
"func_0_block_2_rep_16_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_16_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_16\n"
"dummy_call_func_0_block_2_rep_16:"
"ret\n"
"end_func_0_block_2_rep_16:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 17) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_17_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 64]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_17\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_17:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_17_asm_start\n"
"br_uncond_func_0_block_2_rep_17_0:"
"mov r13, QWORD PTR[r13]\n"
"and rax, rbx\n"
"jmp func_0_block_2_rep_17_asm_end\n"
"func_0_block_2_rep_17_asm_start:"
"mov QWORD PTR[r10 + 64], rbx\n"
"add rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, rbx\n"
"or rdx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rsi\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_2_rep_17_0\n"
"br_cond_func_0_block_2_rep_17_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_17_1\n"
"br_cond_func_0_block_2_rep_17_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_2_rep_17_2\n"
"br_cond_func_0_block_2_rep_17_2:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_2_rep_17_3\n"
"br_cond_func_0_block_2_rep_17_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdi, rax\n"
"mov r13, QWORD PTR[r13]\n"
"and QWORD PTR[r10 + 0], rsi\n"
"call dummy_call_func_0_block_2_rep_17\n"
"jmp br_uncond_func_0_block_2_rep_17_0\n"
"func_0_block_2_rep_17_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_17_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_17\n"
"dummy_call_func_0_block_2_rep_17:"
"ret\n"
"end_func_0_block_2_rep_17:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 18) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_18_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_18\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_18:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_18_asm_start\n"
"func_0_block_2_rep_18_asm_start:"
"mov rax, rbx\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_2_rep_18_0\n"
"br_cond_func_0_block_2_rep_18_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_18_0\n"
"br_uncond_func_0_block_2_rep_18_0:"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"or rbx, rax\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_2_rep_18\n"
"mov rdx, rcx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_2_rep_18_1\n"
"br_cond_func_0_block_2_rep_18_1:"
"add rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_18_2\n"
"br_cond_func_0_block_2_rep_18_2:"
"or rcx, rdx\n"
"mov rax, rbx\n"
"or QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_18_asm_end\n"
"func_0_block_2_rep_18_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_18_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_18\n"
"dummy_call_func_0_block_2_rep_18:"
"ret\n"
"end_func_0_block_2_rep_18:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 19) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_19_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_19\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_19:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_19_asm_start\n"
"func_0_block_2_rep_19_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_19_0\n"
"br_uncond_func_0_block_2_rep_19_0:"
"mov rbx, rax\n"
"call dummy_call_func_0_block_2_rep_19\n"
"call dummy_call_func_0_block_2_rep_19\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_19_0\n"
"br_cond_func_0_block_2_rep_19_0:"
"call dummy_call_func_0_block_2_rep_19\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_2_rep_19_1\n"
"br_cond_func_0_block_2_rep_19_1:"
"mov rbx, rax\n"
"jmp br_uncond_func_0_block_2_rep_19_1\n"
"br_uncond_func_0_block_2_rep_19_1:"
"sub rbx, QWORD PTR[r10 + 128]\n"
"mov rbx, rbx\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov rcx, rcx\n"
"add rsi, QWORD PTR[r10 + 128]\n"
"sub rcx, rbx\n"
"jmp func_0_block_2_rep_19_asm_end\n"
"func_0_block_2_rep_19_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_19_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_19\n"
"dummy_call_func_0_block_2_rep_19:"
"ret\n"
"end_func_0_block_2_rep_19:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 20) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_20_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_20\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_20:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_20_asm_start\n"
"func_0_block_2_rep_20_asm_start:"
"mov rax, rbx\n"
"mov rax, rax\n"
"mov rcx, rbx\n"
"mul rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_2_rep_20_0\n"
"br_cond_func_0_block_2_rep_20_0:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_2_rep_20_1\n"
"br_cond_func_0_block_2_rep_20_1:"
"call dummy_call_func_0_block_2_rep_20\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"add rcx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_20_2\n"
"br_cond_func_0_block_2_rep_20_2:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_20_3\n"
"br_cond_func_0_block_2_rep_20_3:"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, rcx\n"
"mov rcx, rcx\n"
"mov rbx, rdx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_20_4\n"
"br_cond_func_0_block_2_rep_20_4:"
"and rbx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_2_rep_20_5\n"
"br_cond_func_0_block_2_rep_20_5:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_2_rep_20_6\n"
"br_cond_func_0_block_2_rep_20_6:"
"jmp func_0_block_2_rep_20_asm_end\n"
"func_0_block_2_rep_20_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_20_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_20\n"
"dummy_call_func_0_block_2_rep_20:"
"ret\n"
"end_func_0_block_2_rep_20:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 21) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_21_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_21\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_21:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_21_asm_start\n"
"br_uncond_func_0_block_2_rep_21_0:"
"mov rax, rbx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_21_4\n"
"br_cond_func_0_block_2_rep_21_4:"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"add rax, QWORD PTR[r10 + 64]\n"
"and rbx, rax\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_21_asm_end\n"
"func_0_block_2_rep_21_asm_start:"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_21_0\n"
"br_cond_func_0_block_2_rep_21_0:"
"mov r13, QWORD PTR[r13]\n"
"mul rcx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_2_rep_21_1\n"
"br_cond_func_0_block_2_rep_21_1:"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_2_rep_21_2\n"
"br_cond_func_0_block_2_rep_21_2:"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_21_3\n"
"br_cond_func_0_block_2_rep_21_3:"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"jmp br_uncond_func_0_block_2_rep_21_0\n"
"func_0_block_2_rep_21_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_21_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_21\n"
"dummy_call_func_0_block_2_rep_21:"
"ret\n"
"end_func_0_block_2_rep_21:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 22) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_22_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_22\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_22:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_22_asm_start\n"
"br_uncond_func_0_block_2_rep_22_0:"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov rax, rax\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"add QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov rcx, rdx\n"
"or rsi, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_22_asm_end\n"
"func_0_block_2_rep_22_asm_start:"
"call dummy_call_func_0_block_2_rep_22\n"
"mov rsi, rsi\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_2_rep_22_0\n"
"br_cond_func_0_block_2_rep_22_0:"
"mov rbx, rbx\n"
"sub rsi, rbx\n"
"and rsi, rbx\n"
"sub rdx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_2_rep_22_1\n"
"br_cond_func_0_block_2_rep_22_1:"
"add rdi, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov QWORD PTR[r10 + 0], r8\n"
"mov rdi, r8\n"
"add rdi, r8\n"
"and rdi, QWORD PTR[r10 + 128]\n"
"and r8, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_2_rep_22_0\n"
"func_0_block_2_rep_22_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_22_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_22\n"
"dummy_call_func_0_block_2_rep_22:"
"ret\n"
"end_func_0_block_2_rep_22:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 23) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_23_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 64]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_23\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_23:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_23_asm_start\n"
"func_0_block_2_rep_23_asm_start:"
"call dummy_call_func_0_block_2_rep_23\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_2_rep_23_0\n"
"br_cond_func_0_block_2_rep_23_0:"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_2_rep_23_1\n"
"br_cond_func_0_block_2_rep_23_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_2_rep_23_2\n"
"br_cond_func_0_block_2_rep_23_2:"
"or rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_23_0\n"
"br_uncond_func_0_block_2_rep_23_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_2_rep_23_3\n"
"br_cond_func_0_block_2_rep_23_3:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_23_4\n"
"br_cond_func_0_block_2_rep_23_4:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_2_rep_23\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_23_5\n"
"br_cond_func_0_block_2_rep_23_5:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_2_rep_23_6\n"
"br_cond_func_0_block_2_rep_23_6:"
"jmp func_0_block_2_rep_23_asm_end\n"
"func_0_block_2_rep_23_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_23_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_23\n"
"dummy_call_func_0_block_2_rep_23:"
"ret\n"
"end_func_0_block_2_rep_23:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 24) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_24_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_24\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_24:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_24_asm_start\n"
"br_uncond_func_0_block_2_rep_24_0:"
"and rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_2_rep_24_4\n"
"br_cond_func_0_block_2_rep_24_4:"
"add rax, rbx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_2_rep_24_5\n"
"br_cond_func_0_block_2_rep_24_5:"
"and rcx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"jmp func_0_block_2_rep_24_asm_end\n"
"func_0_block_2_rep_24_asm_start:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_24_0\n"
"br_cond_func_0_block_2_rep_24_0:"
"call dummy_call_func_0_block_2_rep_24\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_24_1\n"
"br_cond_func_0_block_2_rep_24_1:"
"mov rcx, rcx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mul rax\n"
"mov rbx, rcx\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_24_2\n"
"br_cond_func_0_block_2_rep_24_2:"
"add rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_2_rep_24_3\n"
"br_cond_func_0_block_2_rep_24_3:"
"jmp br_uncond_func_0_block_2_rep_24_0\n"
"func_0_block_2_rep_24_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_24_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_24\n"
"dummy_call_func_0_block_2_rep_24:"
"ret\n"
"end_func_0_block_2_rep_24:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 25) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_25_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_25\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_25:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_25_asm_start\n"
"br_uncond_func_0_block_2_rep_25_4:"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_25_4\n"
"br_cond_func_0_block_2_rep_25_4:"
"jmp func_0_block_2_rep_25_asm_end\n"
"br_uncond_func_0_block_2_rep_25_1:"
"mov rax, rbx\n"
"or rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 64]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_25_0\n"
"br_cond_func_0_block_2_rep_25_0:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"add rbx, rax\n"
"or rcx, QWORD PTR[r10 + 128]\n"
"or rdx, rax\n"
"mov rdx, rcx\n"
"mov rsi, rcx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_25_1\n"
"br_cond_func_0_block_2_rep_25_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_25_2\n"
"br_cond_func_0_block_2_rep_25_2:"
"jmp br_uncond_func_0_block_2_rep_25_2\n"
"br_uncond_func_0_block_2_rep_25_3:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_25_3\n"
"br_cond_func_0_block_2_rep_25_3:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rsi\n"
"jmp br_uncond_func_0_block_2_rep_25_4\n"
"br_uncond_func_0_block_2_rep_25_0:"
"jmp br_uncond_func_0_block_2_rep_25_1\n"
"func_0_block_2_rep_25_asm_start:"
"call dummy_call_func_0_block_2_rep_25\n"
"jmp br_uncond_func_0_block_2_rep_25_0\n"
"br_uncond_func_0_block_2_rep_25_2:"
"or rdx, rsi\n"
"jmp br_uncond_func_0_block_2_rep_25_3\n"
"func_0_block_2_rep_25_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_25_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_25\n"
"dummy_call_func_0_block_2_rep_25:"
"ret\n"
"end_func_0_block_2_rep_25:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 26) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_26_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_26\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_26:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_26_asm_start\n"
"br_uncond_func_0_block_2_rep_26_1:"
"mov QWORD PTR[r10 + 192], rax\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"add rcx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rcx\n"
"add rbx, rbx\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp br_uncond_func_0_block_2_rep_26_2\n"
"br_uncond_func_0_block_2_rep_26_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rbx\n"
"and rcx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"jmp br_uncond_func_0_block_2_rep_26_1\n"
"br_uncond_func_0_block_2_rep_26_2:"
"or rcx, rax\n"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"jmp br_uncond_func_0_block_2_rep_26_3\n"
"br_uncond_func_0_block_2_rep_26_3:"
"mov rcx, rax\n"
"jmp func_0_block_2_rep_26_asm_end\n"
"func_0_block_2_rep_26_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_26_0\n"
"br_cond_func_0_block_2_rep_26_0:"
"or rdx, rcx\n"
"jmp br_uncond_func_0_block_2_rep_26_0\n"
"func_0_block_2_rep_26_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_26_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_26\n"
"dummy_call_func_0_block_2_rep_26:"
"ret\n"
"end_func_0_block_2_rep_26:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 27) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_27_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_27\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_27:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_27_asm_start\n"
"func_0_block_2_rep_27_asm_start:"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov rax, rbx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_27_0\n"
"br_cond_func_0_block_2_rep_27_0:"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rcx\n"
"sub rbx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, rbx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_27_1\n"
"br_cond_func_0_block_2_rep_27_1:"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"and rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_2_rep_27_2\n"
"br_cond_func_0_block_2_rep_27_2:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_2_rep_27_3\n"
"br_cond_func_0_block_2_rep_27_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_2_rep_27_4\n"
"br_cond_func_0_block_2_rep_27_4:"
"and rax, QWORD PTR[r10 + 0]\n"
"sub rcx, QWORD PTR[r10 + 192]\n"
"and rcx, rax\n"
"jmp func_0_block_2_rep_27_asm_end\n"
"func_0_block_2_rep_27_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_27_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_27\n"
"dummy_call_func_0_block_2_rep_27:"
"ret\n"
"end_func_0_block_2_rep_27:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 28) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_28_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_28\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_28:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_28_asm_start\n"
"func_0_block_2_rep_28_asm_start:"
"add rax, QWORD PTR[r10 + 192]\n"
"jmp br_uncond_func_0_block_2_rep_28_0\n"
"br_uncond_func_0_block_2_rep_28_0:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_28_0\n"
"br_cond_func_0_block_2_rep_28_0:"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_2_rep_28_1\n"
"br_cond_func_0_block_2_rep_28_1:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_2_rep_28_2\n"
"br_cond_func_0_block_2_rep_28_2:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_28_3\n"
"br_cond_func_0_block_2_rep_28_3:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_2_rep_28_4\n"
"br_cond_func_0_block_2_rep_28_4:"
"mov rbx, rcx\n"
"sub rbx, rbx\n"
"jmp br_uncond_func_0_block_2_rep_28_1\n"
"br_uncond_func_0_block_2_rep_28_1:"
"mov rbx, rbx\n"
"call dummy_call_func_0_block_2_rep_28\n"
"and rcx, rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_2_rep_28_5\n"
"br_cond_func_0_block_2_rep_28_5:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 192]\n"
"jmp func_0_block_2_rep_28_asm_end\n"
"func_0_block_2_rep_28_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_28_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_28\n"
"dummy_call_func_0_block_2_rep_28:"
"ret\n"
"end_func_0_block_2_rep_28:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 29) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_29_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_29\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_29:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_29_asm_start\n"
"br_uncond_func_0_block_2_rep_29_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_29_1\n"
"br_uncond_func_0_block_2_rep_29_1:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rcx, rax\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_2_rep_29_1\n"
"br_cond_func_0_block_2_rep_29_1:"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 192]\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"add rcx, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"and rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_29_2\n"
"br_uncond_func_0_block_2_rep_29_2:"
"or rbx, QWORD PTR[r10 + 128]\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_29_2\n"
"br_cond_func_0_block_2_rep_29_2:"
"mov QWORD PTR[r10 + 192], rcx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_2_rep_29_3\n"
"br_cond_func_0_block_2_rep_29_3:"
"mov rax, rax\n"
"jmp func_0_block_2_rep_29_asm_end\n"
"func_0_block_2_rep_29_asm_start:"
"or rbx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_2_rep_29_0\n"
"br_cond_func_0_block_2_rep_29_0:"
"mov QWORD PTR[r10 + 64], rdx\n"
"jmp br_uncond_func_0_block_2_rep_29_0\n"
"func_0_block_2_rep_29_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_29_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_29\n"
"dummy_call_func_0_block_2_rep_29:"
"ret\n"
"end_func_0_block_2_rep_29:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 30) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_30_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_30\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_30:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_30_asm_start\n"
"func_0_block_2_rep_30_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_2_rep_30_0\n"
"br_cond_func_0_block_2_rep_30_0:"
"sub rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_2_rep_30\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_2_rep_30_1\n"
"br_cond_func_0_block_2_rep_30_1:"
"and rbx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_30_2\n"
"br_cond_func_0_block_2_rep_30_2:"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_30_3\n"
"br_cond_func_0_block_2_rep_30_3:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rdx, rax\n"
"mov rdx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_30_4\n"
"br_cond_func_0_block_2_rep_30_4:"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rcx\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"jmp func_0_block_2_rep_30_asm_end\n"
"func_0_block_2_rep_30_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_30_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_30\n"
"dummy_call_func_0_block_2_rep_30:"
"ret\n"
"end_func_0_block_2_rep_30:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 31) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_31_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_31\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_31:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_31_asm_start\n"
"br_uncond_func_0_block_2_rep_31_0:"
"mov rax, rbx\n"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"or rdx, QWORD PTR[r10 + 128]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_31_1\n"
"br_cond_func_0_block_2_rep_31_1:"
"mov QWORD PTR[r10 + 192], rdx\n"
"jmp br_uncond_func_0_block_2_rep_31_1\n"
"br_uncond_func_0_block_2_rep_31_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rsi\n"
"and rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rdi\n"
"and QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"call dummy_call_func_0_block_2_rep_31\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_31_2\n"
"br_cond_func_0_block_2_rep_31_2:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_31_asm_end\n"
"br_uncond_func_0_block_2_rep_31_1:"
"sub rbx, rbx\n"
"jmp br_uncond_func_0_block_2_rep_31_2\n"
"func_0_block_2_rep_31_asm_start:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_31_0\n"
"br_cond_func_0_block_2_rep_31_0:"
"mov rbx, rbx\n"
"or rbx, rbx\n"
"mov QWORD PTR[r10 + 192], rdi\n"
"jmp br_uncond_func_0_block_2_rep_31_0\n"
"func_0_block_2_rep_31_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_31_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_31\n"
"dummy_call_func_0_block_2_rep_31:"
"ret\n"
"end_func_0_block_2_rep_31:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 32) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_32_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_32\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_32:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_32_asm_start\n"
"br_uncond_func_0_block_2_rep_32_1:"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_32_4\n"
"br_cond_func_0_block_2_rep_32_4:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_2_rep_32_5\n"
"br_cond_func_0_block_2_rep_32_5:"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_2_rep_32_6\n"
"br_cond_func_0_block_2_rep_32_6:"
"jmp func_0_block_2_rep_32_asm_end\n"
"br_uncond_func_0_block_2_rep_32_0:"
"or rax, rax\n"
"or rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_2_rep_32_0\n"
"br_cond_func_0_block_2_rep_32_0:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_32_1\n"
"br_cond_func_0_block_2_rep_32_1:"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rcx, rdx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_32_2\n"
"br_cond_func_0_block_2_rep_32_2:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_2_rep_32_3\n"
"br_cond_func_0_block_2_rep_32_3:"
"jmp br_uncond_func_0_block_2_rep_32_1\n"
"func_0_block_2_rep_32_asm_start:"
"mov QWORD PTR[r10 + 192], rcx\n"
"jmp br_uncond_func_0_block_2_rep_32_0\n"
"func_0_block_2_rep_32_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_32_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_32\n"
"dummy_call_func_0_block_2_rep_32:"
"ret\n"
"end_func_0_block_2_rep_32:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 33) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_33_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_33\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_33:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_33_asm_start\n"
"func_0_block_2_rep_33_asm_start:"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_33_0\n"
"br_cond_func_0_block_2_rep_33_0:"
"mov rax, rax\n"
"jmp br_uncond_func_0_block_2_rep_33_0\n"
"br_uncond_func_0_block_2_rep_33_1:"
"and rax, QWORD PTR[r10 + 192]\n"
"and rax, rax\n"
"call dummy_call_func_0_block_2_rep_33\n"
"call dummy_call_func_0_block_2_rep_33\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_2_rep_33_4\n"
"br_cond_func_0_block_2_rep_33_4:"
"jmp func_0_block_2_rep_33_asm_end\n"
"br_uncond_func_0_block_2_rep_33_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_2_rep_33_1\n"
"br_cond_func_0_block_2_rep_33_1:"
"mov QWORD PTR[r10 + 128], rbx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_33_2\n"
"br_cond_func_0_block_2_rep_33_2:"
"mov rbx, rbx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_33_3\n"
"br_cond_func_0_block_2_rep_33_3:"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov rdx, rdx\n"
"jmp br_uncond_func_0_block_2_rep_33_1\n"
"func_0_block_2_rep_33_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_33_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_33\n"
"dummy_call_func_0_block_2_rep_33:"
"ret\n"
"end_func_0_block_2_rep_33:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 34) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_34_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_34\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_34:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_34_asm_start\n"
"func_0_block_2_rep_34_asm_start:"
"or rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"sub rax, rbx\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_2_rep_34_0\n"
"br_cond_func_0_block_2_rep_34_0:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_2_rep_34_1\n"
"br_cond_func_0_block_2_rep_34_1:"
"sub rcx, QWORD PTR[r10 + 128]\n"
"mov rdx, rbx\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"mov rax, rax\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_2_rep_34_2\n"
"br_cond_func_0_block_2_rep_34_2:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"jmp br_uncond_func_0_block_2_rep_34_0\n"
"br_uncond_func_0_block_2_rep_34_0:"
"and rsi, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov rbx, rsi\n"
"sub rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_34_3\n"
"br_cond_func_0_block_2_rep_34_3:"
"jmp func_0_block_2_rep_34_asm_end\n"
"func_0_block_2_rep_34_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_34_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_34\n"
"dummy_call_func_0_block_2_rep_34:"
"ret\n"
"end_func_0_block_2_rep_34:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 35) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_35_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_35\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_35:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_35_asm_start\n"
"func_0_block_2_rep_35_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_2_rep_35_0\n"
"br_cond_func_0_block_2_rep_35_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"mov rbx, rbx\n"
"mov rbx, rcx\n"
"mov rdx, rcx\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"and rax, rdx\n"
"sub rcx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_2_rep_35_1\n"
"br_cond_func_0_block_2_rep_35_1:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_35_2\n"
"br_cond_func_0_block_2_rep_35_2:"
"mov rax, rcx\n"
"mov QWORD PTR[r10 + 128], rsi\n"
"mov rcx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_35_asm_end\n"
"func_0_block_2_rep_35_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_35_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_35\n"
"dummy_call_func_0_block_2_rep_35:"
"ret\n"
"end_func_0_block_2_rep_35:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 36) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_36_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_36\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_36:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_36_asm_start\n"
"br_uncond_func_0_block_2_rep_36_0:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_36_1\n"
"br_uncond_func_0_block_2_rep_36_2:"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_2_rep_36_asm_end\n"
"func_0_block_2_rep_36_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"and rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rbx, rax\n"
"mul rcx\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, rdx\n"
"jmp br_uncond_func_0_block_2_rep_36_0\n"
"br_uncond_func_0_block_2_rep_36_1:"
"mov QWORD PTR[r10 + 64], rdx\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_2_rep_36_0\n"
"br_cond_func_0_block_2_rep_36_0:"
"mov rcx, rax\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_2_rep_36_1\n"
"br_cond_func_0_block_2_rep_36_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"call dummy_call_func_0_block_2_rep_36\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_2_rep_36_2\n"
"br_cond_func_0_block_2_rep_36_2:"
"jmp br_uncond_func_0_block_2_rep_36_2\n"
"func_0_block_2_rep_36_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_36_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_36\n"
"dummy_call_func_0_block_2_rep_36:"
"ret\n"
"end_func_0_block_2_rep_36:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 37) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_37_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_37\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_37:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_37_asm_start\n"
"br_uncond_func_0_block_2_rep_37_0:"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rax\n"
"mov rsi, rax\n"
"jmp func_0_block_2_rep_37_asm_end\n"
"func_0_block_2_rep_37_asm_start:"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rsi, QWORD PTR[r10 + 64]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_2_rep_37_0\n"
"br_cond_func_0_block_2_rep_37_0:"
"mov rsi, rbx\n"
"add rsi, QWORD PTR[r10 + 192]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"or rsi, rsi\n"
"mov QWORD PTR[r10 + 128], rsi\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_37_1\n"
"br_cond_func_0_block_2_rep_37_1:"
"mov r13, QWORD PTR[r13]\n"
"and rsi, QWORD PTR[r10 + 64]\n"
"mov rdx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rdx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_2_rep_37_2\n"
"br_cond_func_0_block_2_rep_37_2:"
"jmp br_uncond_func_0_block_2_rep_37_0\n"
"func_0_block_2_rep_37_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_37_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_37\n"
"dummy_call_func_0_block_2_rep_37:"
"ret\n"
"end_func_0_block_2_rep_37:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 38) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_38_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_38\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_38:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_38_asm_start\n"
"func_0_block_2_rep_38_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"mov rax, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"and rbx, QWORD PTR[r10 + 192]\n"
"mov rdx, rsi\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_2_rep_38_0\n"
"br_cond_func_0_block_2_rep_38_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rdx\n"
"mov rsi, rdi\n"
"mov QWORD PTR[r10 + 128], rdx\n"
"sub rdi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"sub r8, r9\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_2_rep_38_1\n"
"br_cond_func_0_block_2_rep_38_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], r9\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], r8\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_2_rep_38_2\n"
"br_cond_func_0_block_2_rep_38_2:"
"add r9, r14\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_38_3\n"
"br_cond_func_0_block_2_rep_38_3:"
"jmp func_0_block_2_rep_38_asm_end\n"
"func_0_block_2_rep_38_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_38_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_38\n"
"dummy_call_func_0_block_2_rep_38:"
"ret\n"
"end_func_0_block_2_rep_38:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 39) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_39_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_39\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_39:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_39_asm_start\n"
"func_0_block_2_rep_39_asm_start:"
"call dummy_call_func_0_block_2_rep_39\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, QWORD PTR[r10 + 192]\n"
"or rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_2_rep_39_0\n"
"br_cond_func_0_block_2_rep_39_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_2_rep_39_1\n"
"br_cond_func_0_block_2_rep_39_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov QWORD PTR[r10 + 192], rax\n"
"or rcx, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_39_2\n"
"br_cond_func_0_block_2_rep_39_2:"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_39_asm_end\n"
"func_0_block_2_rep_39_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_39_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_39\n"
"dummy_call_func_0_block_2_rep_39:"
"ret\n"
"end_func_0_block_2_rep_39:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 40) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_40_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_40\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_40:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_40_asm_start\n"
"func_0_block_2_rep_40_asm_start:"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_40_0\n"
"br_cond_func_0_block_2_rep_40_0:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_2_rep_40_1\n"
"br_cond_func_0_block_2_rep_40_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_2_rep_40_2\n"
"br_cond_func_0_block_2_rep_40_2:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"sub rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 64]\n"
"mov rbx, rcx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_40_3\n"
"br_cond_func_0_block_2_rep_40_3:"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"call dummy_call_func_0_block_2_rep_40\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, rdx\n"
"mov rsi, rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_40_4\n"
"br_cond_func_0_block_2_rep_40_4:"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov rsi, rax\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, rsi\n"
"call dummy_call_func_0_block_2_rep_40\n"
"sub rbx, rdx\n"
"jmp func_0_block_2_rep_40_asm_end\n"
"func_0_block_2_rep_40_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_40_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_40\n"
"dummy_call_func_0_block_2_rep_40:"
"ret\n"
"end_func_0_block_2_rep_40:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 41) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_41_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_41\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_41:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_41_asm_start\n"
"func_0_block_2_rep_41_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rax, rbx\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_2_rep_41_0\n"
"br_cond_func_0_block_2_rep_41_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_41_1\n"
"br_cond_func_0_block_2_rep_41_1:"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov rbx, rbx\n"
"mov rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 192]\n"
"and rbx, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rbx, rcx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_41_2\n"
"br_cond_func_0_block_2_rep_41_2:"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov rbx, rbx\n"
"sub rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"sub rbx, rbx\n"
"add rbx, rbx\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_41_3\n"
"br_cond_func_0_block_2_rep_41_3:"
"jmp func_0_block_2_rep_41_asm_end\n"
"func_0_block_2_rep_41_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_41_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_41\n"
"dummy_call_func_0_block_2_rep_41:"
"ret\n"
"end_func_0_block_2_rep_41:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 42) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_42_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_42\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_42:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_42_asm_start\n"
"br_uncond_func_0_block_2_rep_42_0:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_2_rep_42_0\n"
"br_cond_func_0_block_2_rep_42_0:"
"sub rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_2_rep_42_1\n"
"br_cond_func_0_block_2_rep_42_1:"
"mov rax, rbx\n"
"mul rbx\n"
"or rcx, QWORD PTR[r10 + 192]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"call dummy_call_func_0_block_2_rep_42\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"mov rbx, rax\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rdx, rcx\n"
"add rsi, rdx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_2_rep_42_2\n"
"br_cond_func_0_block_2_rep_42_2:"
"and rdi, rcx\n"
"add rsi, r8\n"
"sub rdi, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_2_rep_42_3\n"
"br_cond_func_0_block_2_rep_42_3:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_42_asm_end\n"
"func_0_block_2_rep_42_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_42_0\n"
"func_0_block_2_rep_42_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_42_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_42\n"
"dummy_call_func_0_block_2_rep_42:"
"ret\n"
"end_func_0_block_2_rep_42:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 43) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_43_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_43\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_43:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_43_asm_start\n"
"br_uncond_func_0_block_2_rep_43_1:"
"or rax, rbx\n"
"sub rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"jmp br_uncond_func_0_block_2_rep_43_2\n"
"br_uncond_func_0_block_2_rep_43_0:"
"jmp br_uncond_func_0_block_2_rep_43_1\n"
"func_0_block_2_rep_43_asm_start:"
"add rax, rbx\n"
"add QWORD PTR[r10 + 64], rax\n"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rcx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_2_rep_43_0\n"
"br_cond_func_0_block_2_rep_43_0:"
"or rcx, rax\n"
"mov rax, rcx\n"
"mov rbx, rdx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_43_1\n"
"br_cond_func_0_block_2_rep_43_1:"
"and rcx, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"sub rbx, rbx\n"
"jmp br_uncond_func_0_block_2_rep_43_0\n"
"br_uncond_func_0_block_2_rep_43_2:"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov rdx, rdx\n"
"jmp func_0_block_2_rep_43_asm_end\n"
"func_0_block_2_rep_43_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_43_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_43\n"
"dummy_call_func_0_block_2_rep_43:"
"ret\n"
"end_func_0_block_2_rep_43:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 44) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_44_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_44\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_44:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_44_asm_start\n"
"br_uncond_func_0_block_2_rep_44_1:"
"mov rax, rbx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_2_rep_44_4\n"
"br_cond_func_0_block_2_rep_44_4:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_44_5\n"
"br_cond_func_0_block_2_rep_44_5:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_44_6\n"
"br_cond_func_0_block_2_rep_44_6:"
"jmp func_0_block_2_rep_44_asm_end\n"
"func_0_block_2_rep_44_asm_start:"
"mov rcx, rbx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_44_0\n"
"br_cond_func_0_block_2_rep_44_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_2_rep_44_1\n"
"br_cond_func_0_block_2_rep_44_1:"
"mov rbx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_44_0\n"
"br_uncond_func_0_block_2_rep_44_0:"
"mov QWORD PTR[r10 + 64], rcx\n"
"or rbx, QWORD PTR[r10 + 128]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_2_rep_44_2\n"
"br_cond_func_0_block_2_rep_44_2:"
"add rbx, rdx\n"
"or rbx, QWORD PTR[r10 + 192]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"sub rdx, rsi\n"
"sub rbx, rsi\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_2_rep_44_3\n"
"br_cond_func_0_block_2_rep_44_3:"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_44_1\n"
"func_0_block_2_rep_44_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_44_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_44\n"
"dummy_call_func_0_block_2_rep_44:"
"ret\n"
"end_func_0_block_2_rep_44:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 45) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_45_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_45\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_45:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_45_asm_start\n"
"br_uncond_func_0_block_2_rep_45_0:"
"or rax, QWORD PTR[r10 + 128]\n"
"call dummy_call_func_0_block_2_rep_45\n"
"mov QWORD PTR[r10 + 64], rax\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"add rbx, QWORD PTR[r10 + 192]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_45_1\n"
"br_cond_func_0_block_2_rep_45_1:"
"mov QWORD PTR[r10 + 128], rax\n"
"call dummy_call_func_0_block_2_rep_45\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_2_rep_45_2\n"
"br_cond_func_0_block_2_rep_45_2:"
"mov rax, rbx\n"
"mov rax, rax\n"
"jmp br_uncond_func_0_block_2_rep_45_1\n"
"br_uncond_func_0_block_2_rep_45_1:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_2_rep_45_asm_end\n"
"func_0_block_2_rep_45_asm_start:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rdx\n"
"or rdx, QWORD PTR[r10 + 64]\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_2_rep_45_0\n"
"br_cond_func_0_block_2_rep_45_0:"
"mov QWORD PTR[r10 + 0], rdx\n"
"call dummy_call_func_0_block_2_rep_45\n"
"jmp br_uncond_func_0_block_2_rep_45_0\n"
"func_0_block_2_rep_45_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_45_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_45\n"
"dummy_call_func_0_block_2_rep_45:"
"ret\n"
"end_func_0_block_2_rep_45:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 46) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_46_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_46\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_46:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_46_asm_start\n"
"br_uncond_func_0_block_2_rep_46_0:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_2_rep_46_4\n"
"br_cond_func_0_block_2_rep_46_4:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, rax\n"
"and rcx, rax\n"
"and rcx, QWORD PTR[r10 + 192]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"add QWORD PTR[r10 + 64], rax\n"
"sub rcx, QWORD PTR[r10 + 128]\n"
"or rcx, rax\n"
"and rcx, rax\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_2_rep_46_5\n"
"br_cond_func_0_block_2_rep_46_5:"
"or rcx, QWORD PTR[r10 + 192]\n"
"jmp func_0_block_2_rep_46_asm_end\n"
"func_0_block_2_rep_46_asm_start:"
"test r11d, 4096\n"
"jz br_cond_func_0_block_2_rep_46_0\n"
"br_cond_func_0_block_2_rep_46_0:"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_2_rep_46_1\n"
"br_cond_func_0_block_2_rep_46_1:"
"and rax, QWORD PTR[r10 + 64]\n"
"or rdx, QWORD PTR[r10 + 128]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_46_2\n"
"br_cond_func_0_block_2_rep_46_2:"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_2_rep_46_3\n"
"br_cond_func_0_block_2_rep_46_3:"
"and rax, QWORD PTR[r10 + 192]\n"
"call dummy_call_func_0_block_2_rep_46\n"
"jmp br_uncond_func_0_block_2_rep_46_0\n"
"func_0_block_2_rep_46_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_46_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_46\n"
"dummy_call_func_0_block_2_rep_46:"
"ret\n"
"end_func_0_block_2_rep_46:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 47) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_47_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_47\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_47:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_47_asm_start\n"
"br_uncond_func_0_block_2_rep_47_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"and rax, QWORD PTR[r10 + 64]\n"
"call dummy_call_func_0_block_2_rep_47\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_2_rep_47_1\n"
"br_cond_func_0_block_2_rep_47_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rbx\n"
"sub rax, rax\n"
"or rcx, rax\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_47_2\n"
"br_cond_func_0_block_2_rep_47_2:"
"test r11d, 64\n"
"jz br_cond_func_0_block_2_rep_47_3\n"
"br_cond_func_0_block_2_rep_47_3:"
"mov rax, rcx\n"
"jmp func_0_block_2_rep_47_asm_end\n"
"br_uncond_func_0_block_2_rep_47_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_47_1\n"
"func_0_block_2_rep_47_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_47_0\n"
"br_cond_func_0_block_2_rep_47_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_2_rep_47_0\n"
"func_0_block_2_rep_47_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_47_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_47\n"
"dummy_call_func_0_block_2_rep_47:"
"ret\n"
"end_func_0_block_2_rep_47:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 48) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_48_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_48\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_48:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_48_asm_start\n"
"br_uncond_func_0_block_2_rep_48_1:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_2_rep_48\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_48_2\n"
"br_cond_func_0_block_2_rep_48_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"call dummy_call_func_0_block_2_rep_48\n"
"call dummy_call_func_0_block_2_rep_48\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"sub rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"sub rax, QWORD PTR[r10 + 192]\n"
"jmp func_0_block_2_rep_48_asm_end\n"
"func_0_block_2_rep_48_asm_start:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_2_rep_48_0\n"
"br_cond_func_0_block_2_rep_48_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, rax\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_2_rep_48_1\n"
"br_cond_func_0_block_2_rep_48_1:"
"jmp br_uncond_func_0_block_2_rep_48_0\n"
"br_uncond_func_0_block_2_rep_48_0:"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"jmp br_uncond_func_0_block_2_rep_48_1\n"
"func_0_block_2_rep_48_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_48_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_48\n"
"dummy_call_func_0_block_2_rep_48:"
"ret\n"
"end_func_0_block_2_rep_48:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 451 && (req_id & 1023) < 512 && (req_id % 50) == 49) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_2_rep_49_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_2_rep_49\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_2_rep_49:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_2_rep_49_asm_start\n"
"func_0_block_2_rep_49_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rbx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_2_rep_49_0\n"
"br_cond_func_0_block_2_rep_49_0:"
"and rcx, QWORD PTR[r10 + 64]\n"
"sub rdx, rbx\n"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rsi\n"
"add rdi, rcx\n"
"movsd xmm0, QWORD PTR[r10 + 192]\n"
"mov QWORD PTR[r10 + 128], rsi\n"
"mov rdi, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, rsi\n"
"mov QWORD PTR[r10 + 192], rsi\n"
"mov QWORD PTR[r10 + 128], rsi\n"
"mov QWORD PTR[r10 + 0], rdi\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, QWORD PTR[r10 + 64]\n"
"mov rsi, rax\n"
"call dummy_call_func_0_block_2_rep_49\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_2_rep_49_1\n"
"br_cond_func_0_block_2_rep_49_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rsi\n"
"sub rsi, rcx\n"
"jmp func_0_block_2_rep_49_asm_end\n"
"func_0_block_2_rep_49_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 219\n"
"cmp r11, rdi\n"
"jl func_0_block_2_rep_49_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_2_rep_49\n"
"dummy_call_func_0_block_2_rep_49:"
"ret\n"
"end_func_0_block_2_rep_49:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_0_asm_start\n"
"func_0_block_3_rep_0_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_3_rep_0_0\n"
"br_cond_func_0_block_3_rep_0_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 128]\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"sub rcx, rdx\n"
"add rdx, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_3_rep_0_asm_end\n"
"func_0_block_3_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_0\n"
"dummy_call_func_0_block_3_rep_0:"
"ret\n"
"end_func_0_block_3_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 192]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_1_asm_start\n"
"func_0_block_3_rep_1_asm_start:"
"mov rax, rbx\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_3_rep_1_0\n"
"br_cond_func_0_block_3_rep_1_0:"
"add rbx, rax\n"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_3_rep_1_1\n"
"br_cond_func_0_block_3_rep_1_1:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rcx, rcx\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_3_rep_1_2\n"
"br_cond_func_0_block_3_rep_1_2:"
"call dummy_call_func_0_block_3_rep_1\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_3_rep_1_3\n"
"br_cond_func_0_block_3_rep_1_3:"
"sub rcx, rcx\n"
"jmp func_0_block_3_rep_1_asm_end\n"
"func_0_block_3_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_1\n"
"dummy_call_func_0_block_3_rep_1:"
"ret\n"
"end_func_0_block_3_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_2_asm_start\n"
"func_0_block_3_rep_2_asm_start:"
"call dummy_call_func_0_block_3_rep_2\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_3_rep_2_0\n"
"br_cond_func_0_block_3_rep_2_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_3_rep_2_1\n"
"br_cond_func_0_block_3_rep_2_1:"
"test r11d, 32\n"
"jz br_cond_func_0_block_3_rep_2_2\n"
"br_cond_func_0_block_3_rep_2_2:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"call dummy_call_func_0_block_3_rep_2\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_3_rep_2_asm_end\n"
"func_0_block_3_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_2\n"
"dummy_call_func_0_block_3_rep_2:"
"ret\n"
"end_func_0_block_3_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 64]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_3_asm_start\n"
"func_0_block_3_rep_3_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_3_rep_3_0\n"
"br_cond_func_0_block_3_rep_3_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp br_uncond_func_0_block_3_rep_3_0\n"
"br_uncond_func_0_block_3_rep_3_0:"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov rbx, rax\n"
"and rbx, rax\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_3_rep_3_1\n"
"br_cond_func_0_block_3_rep_3_1:"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"jmp func_0_block_3_rep_3_asm_end\n"
"func_0_block_3_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_3\n"
"dummy_call_func_0_block_3_rep_3:"
"ret\n"
"end_func_0_block_3_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_4_asm_start\n"
"func_0_block_3_rep_4_asm_start:"
"mov rax, rbx\n"
"mov rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rdx\n"
"sub rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_3_rep_4_0\n"
"br_cond_func_0_block_3_rep_4_0:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_3_rep_4_1\n"
"br_cond_func_0_block_3_rep_4_1:"
"mov rcx, rsi\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_3_rep_4_2\n"
"br_cond_func_0_block_3_rep_4_2:"
"mov QWORD PTR[r10 + 64], rcx\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_3_rep_4_3\n"
"br_cond_func_0_block_3_rep_4_3:"
"jmp func_0_block_3_rep_4_asm_end\n"
"func_0_block_3_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_4\n"
"dummy_call_func_0_block_3_rep_4:"
"ret\n"
"end_func_0_block_3_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 64]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_5_asm_start\n"
"func_0_block_3_rep_5_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_3_rep_5_0\n"
"br_cond_func_0_block_3_rep_5_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rax, rax\n"
"add rax, rax\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_3_rep_5_1\n"
"br_cond_func_0_block_3_rep_5_1:"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_3_rep_5_2\n"
"br_cond_func_0_block_3_rep_5_2:"
"mov rbx, rcx\n"
"jmp func_0_block_3_rep_5_asm_end\n"
"func_0_block_3_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_5\n"
"dummy_call_func_0_block_3_rep_5:"
"ret\n"
"end_func_0_block_3_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_6_asm_start\n"
"func_0_block_3_rep_6_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_3_rep_6\n"
"mov QWORD PTR[r10 + 64], rax\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_3_rep_6_0\n"
"br_cond_func_0_block_3_rep_6_0:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_3_rep_6\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_3_rep_6_1\n"
"br_cond_func_0_block_3_rep_6_1:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_3_rep_6_2\n"
"br_cond_func_0_block_3_rep_6_2:"
"sub rcx, rcx\n"
"sub rax, rcx\n"
"mov rax, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_3_rep_6_asm_end\n"
"func_0_block_3_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_6\n"
"dummy_call_func_0_block_3_rep_6:"
"ret\n"
"end_func_0_block_3_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_7_asm_start\n"
"br_uncond_func_0_block_3_rep_7_0:"
"and rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"jmp func_0_block_3_rep_7_asm_end\n"
"func_0_block_3_rep_7_asm_start:"
"mov QWORD PTR[r10 + 192], rbx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_3_rep_7_0\n"
"br_cond_func_0_block_3_rep_7_0:"
"add rbx, rax\n"
"sub rbx, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"and rdx, rcx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_3_rep_7_1\n"
"br_cond_func_0_block_3_rep_7_1:"
"add rcx, rax\n"
"call dummy_call_func_0_block_3_rep_7\n"
"jmp br_uncond_func_0_block_3_rep_7_0\n"
"func_0_block_3_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_7\n"
"dummy_call_func_0_block_3_rep_7:"
"ret\n"
"end_func_0_block_3_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_8_asm_start\n"
"func_0_block_3_rep_8_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rax, QWORD PTR[r10 + 192]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_3_rep_8_0\n"
"br_cond_func_0_block_3_rep_8_0:"
"mov rax, rax\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_3_rep_8_1\n"
"br_cond_func_0_block_3_rep_8_1:"
"sub rbx, QWORD PTR[r10 + 128]\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_3_rep_8_2\n"
"br_cond_func_0_block_3_rep_8_2:"
"sub rcx, QWORD PTR[r10 + 64]\n"
"mov rcx, rdx\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_3_rep_8_3\n"
"br_cond_func_0_block_3_rep_8_3:"
"test r11d, 512\n"
"jz br_cond_func_0_block_3_rep_8_4\n"
"br_cond_func_0_block_3_rep_8_4:"
"jmp func_0_block_3_rep_8_asm_end\n"
"func_0_block_3_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_8\n"
"dummy_call_func_0_block_3_rep_8:"
"ret\n"
"end_func_0_block_3_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_9_asm_start\n"
"func_0_block_3_rep_9_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"add rbx, rax\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"or rcx, QWORD PTR[r10 + 64]\n"
"sub rax, rbx\n"
"jmp br_uncond_func_0_block_3_rep_9_0\n"
"br_uncond_func_0_block_3_rep_9_0:"
"mov rax, rdx\n"
"and rdx, QWORD PTR[r10 + 128]\n"
"mov rbx, rcx\n"
"mov rdx, rax\n"
"mov rbx, rax\n"
"or rax, rdx\n"
"sub rdx, QWORD PTR[r10 + 0]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_3_rep_9_0\n"
"br_cond_func_0_block_3_rep_9_0:"
"jmp func_0_block_3_rep_9_asm_end\n"
"func_0_block_3_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_9\n"
"dummy_call_func_0_block_3_rep_9:"
"ret\n"
"end_func_0_block_3_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 192]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_10_asm_start\n"
"func_0_block_3_rep_10_asm_start:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_3_rep_10_0\n"
"br_cond_func_0_block_3_rep_10_0:"
"mov rax, rbx\n"
"sub rcx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_3_rep_10_1\n"
"br_cond_func_0_block_3_rep_10_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_3_rep_10_2\n"
"br_cond_func_0_block_3_rep_10_2:"
"test r11d, 8192\n"
"jz br_cond_func_0_block_3_rep_10_3\n"
"br_cond_func_0_block_3_rep_10_3:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_3_rep_10_4\n"
"br_cond_func_0_block_3_rep_10_4:"
"jmp func_0_block_3_rep_10_asm_end\n"
"func_0_block_3_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_10\n"
"dummy_call_func_0_block_3_rep_10:"
"ret\n"
"end_func_0_block_3_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_11_asm_start\n"
"func_0_block_3_rep_11_asm_start:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_3_rep_11_0\n"
"br_cond_func_0_block_3_rep_11_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_3_rep_11_1\n"
"br_cond_func_0_block_3_rep_11_1:"
"sub rbx, rbx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_3_rep_11_2\n"
"br_cond_func_0_block_3_rep_11_2:"
"or rax, QWORD PTR[r10 + 128]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_3_rep_11_3\n"
"br_cond_func_0_block_3_rep_11_3:"
"jmp func_0_block_3_rep_11_asm_end\n"
"func_0_block_3_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_11\n"
"dummy_call_func_0_block_3_rep_11:"
"ret\n"
"end_func_0_block_3_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_12_asm_start\n"
"func_0_block_3_rep_12_asm_start:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rax, rbx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_3_rep_12_0\n"
"br_cond_func_0_block_3_rep_12_0:"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rbx, QWORD PTR[r10 + 192]\n"
"sub rbx, rbx\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_3_rep_12_1\n"
"br_cond_func_0_block_3_rep_12_1:"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_3_rep_12_2\n"
"br_cond_func_0_block_3_rep_12_2:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_3_rep_12_3\n"
"br_cond_func_0_block_3_rep_12_3:"
"mov r13, QWORD PTR[r13]\n"
"and rdx, rsi\n"
"jmp func_0_block_3_rep_12_asm_end\n"
"func_0_block_3_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_12\n"
"dummy_call_func_0_block_3_rep_12:"
"ret\n"
"end_func_0_block_3_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_13_asm_start\n"
"func_0_block_3_rep_13_asm_start:"
"mov rax, rbx\n"
"sub rcx, rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_3_rep_13_0\n"
"br_cond_func_0_block_3_rep_13_0:"
"sub rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_3_rep_13_asm_end\n"
"func_0_block_3_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_13\n"
"dummy_call_func_0_block_3_rep_13:"
"ret\n"
"end_func_0_block_3_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 64]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_14_asm_start\n"
"func_0_block_3_rep_14_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rax, QWORD PTR[r10 + 64]\n"
"call dummy_call_func_0_block_3_rep_14\n"
"jmp br_uncond_func_0_block_3_rep_14_0\n"
"br_uncond_func_0_block_3_rep_14_0:"
"add rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"mul rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_3_rep_14_0\n"
"br_cond_func_0_block_3_rep_14_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_3_rep_14_asm_end\n"
"func_0_block_3_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_14\n"
"dummy_call_func_0_block_3_rep_14:"
"ret\n"
"end_func_0_block_3_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 512 && (req_id & 1023) < 569 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_3_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 0]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_3_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_3_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_3_rep_15_asm_start\n"
"func_0_block_3_rep_15_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_3_rep_15_0\n"
"br_cond_func_0_block_3_rep_15_0:"
"test r11d, 1\n"
"jz br_cond_func_0_block_3_rep_15_1\n"
"br_cond_func_0_block_3_rep_15_1:"
"and rcx, QWORD PTR[r10 + 0]\n"
"and rdx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rax, rbx\n"
"sub rbx, rdx\n"
"jmp func_0_block_3_rep_15_asm_end\n"
"func_0_block_3_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_3_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_3_rep_15\n"
"dummy_call_func_0_block_3_rep_15:"
"ret\n"
"end_func_0_block_3_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[2]), "r" (curr_pointer_chasing_mem_addrs[2]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[2] = next_mem_addr;
curr_pointer_chasing_mem_addrs[2] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 320]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_0_asm_start\n"
"func_0_block_4_rep_0_asm_start:"
"and rax, rax\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_4_rep_0\n"
"mov rbx, rcx\n"
"or rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_4_rep_0_0\n"
"br_cond_func_0_block_4_rep_0_0:"
"mov QWORD PTR[r10 + 64], rdx\n"
"mov rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_4_rep_0_asm_end\n"
"func_0_block_4_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_0\n"
"dummy_call_func_0_block_4_rep_0:"
"ret\n"
"end_func_0_block_4_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 320]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_1_asm_start\n"
"func_0_block_4_rep_1_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"sub rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_4_rep_1_0\n"
"br_cond_func_0_block_4_rep_1_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_4_rep_1_1\n"
"br_cond_func_0_block_4_rep_1_1:"
"test r11d, 16\n"
"jz br_cond_func_0_block_4_rep_1_2\n"
"br_cond_func_0_block_4_rep_1_2:"
"sub rcx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_4_rep_1\n"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_4_rep_1_asm_end\n"
"func_0_block_4_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_1\n"
"dummy_call_func_0_block_4_rep_1:"
"ret\n"
"end_func_0_block_4_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 256]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_2_asm_start\n"
"func_0_block_4_rep_2_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"call dummy_call_func_0_block_4_rep_2\n"
"mov QWORD PTR[r10 + 192], rax\n"
"sub QWORD PTR[r10 + 128], rax\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_4_rep_2_0\n"
"br_cond_func_0_block_4_rep_2_0:"
"jmp br_uncond_func_0_block_4_rep_2_0\n"
"br_uncond_func_0_block_4_rep_2_0:"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_4_rep_2_1\n"
"br_cond_func_0_block_4_rep_2_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_4_rep_2_2\n"
"br_cond_func_0_block_4_rep_2_2:"
"jmp func_0_block_4_rep_2_asm_end\n"
"func_0_block_4_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_2\n"
"dummy_call_func_0_block_4_rep_2:"
"ret\n"
"end_func_0_block_4_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 384]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_3_asm_start\n"
"br_uncond_func_0_block_4_rep_3_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_4_rep_3_0\n"
"br_cond_func_0_block_4_rep_3_0:"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"sub rbx, rax\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_4_rep_3_1\n"
"br_cond_func_0_block_4_rep_3_1:"
"mov rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_4_rep_3_2\n"
"br_cond_func_0_block_4_rep_3_2:"
"jmp func_0_block_4_rep_3_asm_end\n"
"func_0_block_4_rep_3_asm_start:"
"mov rax, rax\n"
"jmp br_uncond_func_0_block_4_rep_3_0\n"
"func_0_block_4_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_3\n"
"dummy_call_func_0_block_4_rep_3:"
"ret\n"
"end_func_0_block_4_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 320]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_4_asm_start\n"
"br_uncond_func_0_block_4_rep_4_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"and rax, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_4_rep_4_asm_end\n"
"func_0_block_4_rep_4_asm_start:"
"mov rax, rax\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_4_rep_4_0\n"
"br_cond_func_0_block_4_rep_4_0:"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov rax, rax\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_4_rep_4_1\n"
"br_cond_func_0_block_4_rep_4_1:"
"call dummy_call_func_0_block_4_rep_4\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_4_rep_4_2\n"
"br_cond_func_0_block_4_rep_4_2:"
"or rax, rax\n"
"add rbx, rax\n"
"jmp br_uncond_func_0_block_4_rep_4_0\n"
"func_0_block_4_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_4\n"
"dummy_call_func_0_block_4_rep_4:"
"ret\n"
"end_func_0_block_4_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 192]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_5_asm_start\n"
"func_0_block_4_rep_5_asm_start:"
"and QWORD PTR[r10 + 192], rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov QWORD PTR[r10 + 256], rax\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_4_rep_5_0\n"
"br_cond_func_0_block_4_rep_5_0:"
"and rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 64]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_4_rep_5_1\n"
"br_cond_func_0_block_4_rep_5_1:"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rcx\n"
"add rax, rax\n"
"jmp func_0_block_4_rep_5_asm_end\n"
"func_0_block_4_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_5\n"
"dummy_call_func_0_block_4_rep_5:"
"ret\n"
"end_func_0_block_4_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 256]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_6_asm_start\n"
"func_0_block_4_rep_6_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_4_rep_6_0\n"
"br_cond_func_0_block_4_rep_6_0:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_4_rep_6_1\n"
"br_cond_func_0_block_4_rep_6_1:"
"call dummy_call_func_0_block_4_rep_6\n"
"or rax, QWORD PTR[r10 + 128]\n"
"or rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov rdx, rdx\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"call dummy_call_func_0_block_4_rep_6\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_4_rep_6_asm_end\n"
"func_0_block_4_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_6\n"
"dummy_call_func_0_block_4_rep_6:"
"ret\n"
"end_func_0_block_4_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_7_asm_start\n"
"func_0_block_4_rep_7_asm_start:"
"or rax, rbx\n"
"mov rcx, rbx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov QWORD PTR[r10 + 320], rbx\n"
"call dummy_call_func_0_block_4_rep_7\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_4_rep_7_0\n"
"br_cond_func_0_block_4_rep_7_0:"
"jmp br_uncond_func_0_block_4_rep_7_0\n"
"br_uncond_func_0_block_4_rep_7_0:"
"mov QWORD PTR[r10 + 256], rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rdx, rax\n"
"jmp func_0_block_4_rep_7_asm_end\n"
"func_0_block_4_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_7\n"
"dummy_call_func_0_block_4_rep_7:"
"ret\n"
"end_func_0_block_4_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 384]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_8_asm_start\n"
"func_0_block_4_rep_8_asm_start:"
"mov rax, rax\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_4_rep_8_0\n"
"br_cond_func_0_block_4_rep_8_0:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_4_rep_8_1\n"
"br_cond_func_0_block_4_rep_8_1:"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_4_rep_8_2\n"
"br_cond_func_0_block_4_rep_8_2:"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_4_rep_8_3\n"
"br_cond_func_0_block_4_rep_8_3:"
"imul rax\n"
"sub rbx, rcx\n"
"jmp func_0_block_4_rep_8_asm_end\n"
"func_0_block_4_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_8\n"
"dummy_call_func_0_block_4_rep_8:"
"ret\n"
"end_func_0_block_4_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 448]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_9_asm_start\n"
"br_uncond_func_0_block_4_rep_9_0:"
"sub rax, rbx\n"
"jmp func_0_block_4_rep_9_asm_end\n"
"func_0_block_4_rep_9_asm_start:"
"mov rax, rbx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_4_rep_9_0\n"
"br_cond_func_0_block_4_rep_9_0:"
"test r11d, 2\n"
"jz br_cond_func_0_block_4_rep_9_1\n"
"br_cond_func_0_block_4_rep_9_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rbx\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_4_rep_9_2\n"
"br_cond_func_0_block_4_rep_9_2:"
"test r11d, 256\n"
"jz br_cond_func_0_block_4_rep_9_3\n"
"br_cond_func_0_block_4_rep_9_3:"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_4_rep_9_4\n"
"br_cond_func_0_block_4_rep_9_4:"
"jmp br_uncond_func_0_block_4_rep_9_0\n"
"func_0_block_4_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_9\n"
"dummy_call_func_0_block_4_rep_9:"
"ret\n"
"end_func_0_block_4_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 448]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_10_asm_start\n"
"br_uncond_func_0_block_4_rep_10_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_4_rep_10_1\n"
"br_cond_func_0_block_4_rep_10_1:"
"mov r13, QWORD PTR[r13]\n"
"add rax, rbx\n"
"add rax, QWORD PTR[r10 + 0]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_4_rep_10_2\n"
"br_cond_func_0_block_4_rep_10_2:"
"call dummy_call_func_0_block_4_rep_10\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_4_rep_10_3\n"
"br_cond_func_0_block_4_rep_10_3:"
"call dummy_call_func_0_block_4_rep_10\n"
"jmp func_0_block_4_rep_10_asm_end\n"
"func_0_block_4_rep_10_asm_start:"
"mov rax, rbx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_4_rep_10_0\n"
"br_cond_func_0_block_4_rep_10_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_4_rep_10_0\n"
"func_0_block_4_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_10\n"
"dummy_call_func_0_block_4_rep_10:"
"ret\n"
"end_func_0_block_4_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 64]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_11_asm_start\n"
"func_0_block_4_rep_11_asm_start:"
"sub rax, rbx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_4_rep_11_0\n"
"br_cond_func_0_block_4_rep_11_0:"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"add rax, QWORD PTR[r10 + 320]\n"
"mov QWORD PTR[r10 + 256], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rcx, rax\n"
"mov rbx, rdx\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_4_rep_11_1\n"
"br_cond_func_0_block_4_rep_11_1:"
"mov QWORD PTR[r10 + 384], rbx\n"
"or rcx, QWORD PTR[r10 + 128]\n"
"jmp func_0_block_4_rep_11_asm_end\n"
"func_0_block_4_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 448\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_11\n"
"dummy_call_func_0_block_4_rep_11:"
"ret\n"
"end_func_0_block_4_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 192]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_12_asm_start\n"
"func_0_block_4_rep_12_asm_start:"
"sub QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 256], rax\n"
"add rbx, rbx\n"
"mov rcx, rax\n"
"sub rcx, rax\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_4_rep_12_0\n"
"br_cond_func_0_block_4_rep_12_0:"
"or rbx, QWORD PTR[r10 + 192]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_4_rep_12_1\n"
"br_cond_func_0_block_4_rep_12_1:"
"sub rdx, QWORD PTR[r10 + 0]\n"
"call dummy_call_func_0_block_4_rep_12\n"
"call dummy_call_func_0_block_4_rep_12\n"
"mov QWORD PTR[r10 + 64], rdx\n"
"jmp func_0_block_4_rep_12_asm_end\n"
"func_0_block_4_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_12\n"
"dummy_call_func_0_block_4_rep_12:"
"ret\n"
"end_func_0_block_4_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 384]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_13_asm_start\n"
"func_0_block_4_rep_13_asm_start:"
"call dummy_call_func_0_block_4_rep_13\n"
"mov rax, rbx\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_4_rep_13_0\n"
"br_cond_func_0_block_4_rep_13_0:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"jmp br_uncond_func_0_block_4_rep_13_0\n"
"br_uncond_func_0_block_4_rep_13_0:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_4_rep_13_1\n"
"br_cond_func_0_block_4_rep_13_1:"
"sub rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_4_rep_13_asm_end\n"
"func_0_block_4_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_13\n"
"dummy_call_func_0_block_4_rep_13:"
"ret\n"
"end_func_0_block_4_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 320]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_14_asm_start\n"
"br_uncond_func_0_block_4_rep_14_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"call dummy_call_func_0_block_4_rep_14\n"
"and rbx, rbx\n"
"mov rcx, rbx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_4_rep_14_0\n"
"br_cond_func_0_block_4_rep_14_0:"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_4_rep_14_1\n"
"br_cond_func_0_block_4_rep_14_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_4_rep_14_2\n"
"br_cond_func_0_block_4_rep_14_2:"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_4_rep_14_asm_end\n"
"func_0_block_4_rep_14_asm_start:"
"jmp br_uncond_func_0_block_4_rep_14_0\n"
"func_0_block_4_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_14\n"
"dummy_call_func_0_block_4_rep_14:"
"ret\n"
"end_func_0_block_4_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 569 && (req_id & 1023) < 711 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_4_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 384]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_4_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_4_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_4_rep_15_asm_start\n"
"func_0_block_4_rep_15_asm_start:"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_4_rep_15_0\n"
"br_cond_func_0_block_4_rep_15_0:"
"add rax, rax\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_4_rep_15_1\n"
"br_cond_func_0_block_4_rep_15_1:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_4_rep_15_2\n"
"br_cond_func_0_block_4_rep_15_2:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_4_rep_15_3\n"
"br_cond_func_0_block_4_rep_15_3:"
"jmp func_0_block_4_rep_15_asm_end\n"
"func_0_block_4_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_4_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_4_rep_15\n"
"dummy_call_func_0_block_4_rep_15:"
"ret\n"
"end_func_0_block_4_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[3]), "r" (curr_pointer_chasing_mem_addrs[3]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[3] = next_mem_addr;
curr_pointer_chasing_mem_addrs[3] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 768]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_0_asm_start\n"
"func_0_block_5_rep_0_asm_start:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_5_rep_0_0\n"
"br_cond_func_0_block_5_rep_0_0:"
"test r11d, 512\n"
"jz br_cond_func_0_block_5_rep_0_1\n"
"br_cond_func_0_block_5_rep_0_1:"
"mov QWORD PTR[r10 + 64], rax\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"jmp br_uncond_func_0_block_5_rep_0_0\n"
"br_uncond_func_0_block_5_rep_0_0:"
"add rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_5_rep_0_2\n"
"br_cond_func_0_block_5_rep_0_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_5_rep_0_3\n"
"br_cond_func_0_block_5_rep_0_3:"
"jmp func_0_block_5_rep_0_asm_end\n"
"func_0_block_5_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_0\n"
"dummy_call_func_0_block_5_rep_0:"
"ret\n"
"end_func_0_block_5_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 896]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_1_asm_start\n"
"func_0_block_5_rep_1_asm_start:"
"test r11d, 64\n"
"jz br_cond_func_0_block_5_rep_1_0\n"
"br_cond_func_0_block_5_rep_1_0:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_5_rep_1_1\n"
"br_cond_func_0_block_5_rep_1_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_5_rep_1_2\n"
"br_cond_func_0_block_5_rep_1_2:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_5_rep_1_3\n"
"br_cond_func_0_block_5_rep_1_3:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_5_rep_1_4\n"
"br_cond_func_0_block_5_rep_1_4:"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp br_uncond_func_0_block_5_rep_1_0\n"
"br_uncond_func_0_block_5_rep_1_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_5_rep_1_asm_end\n"
"func_0_block_5_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_1\n"
"dummy_call_func_0_block_5_rep_1:"
"ret\n"
"end_func_0_block_5_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 832]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_2_asm_start\n"
"br_uncond_func_0_block_5_rep_2_0:"
"add rax, QWORD PTR[r10 + 128]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_5_rep_2_0\n"
"br_cond_func_0_block_5_rep_2_0:"
"jmp br_uncond_func_0_block_5_rep_2_1\n"
"br_uncond_func_0_block_5_rep_2_1:"
"test r11d, 32\n"
"jz br_cond_func_0_block_5_rep_2_1\n"
"br_cond_func_0_block_5_rep_2_1:"
"add rax, QWORD PTR[r10 + 64]\n"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rcx\n"
"sub rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_5_rep_2_2\n"
"br_cond_func_0_block_5_rep_2_2:"
"jmp func_0_block_5_rep_2_asm_end\n"
"func_0_block_5_rep_2_asm_start:"
"and rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_5_rep_2_0\n"
"func_0_block_5_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_2\n"
"dummy_call_func_0_block_5_rep_2:"
"ret\n"
"end_func_0_block_5_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 832]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_3_asm_start\n"
"func_0_block_5_rep_3_asm_start:"
"add rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_5_rep_3_0\n"
"br_cond_func_0_block_5_rep_3_0:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_5_rep_3_1\n"
"br_cond_func_0_block_5_rep_3_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rbx, QWORD PTR[r10 + 64]\n"
"and rbx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_5_rep_3_2\n"
"br_cond_func_0_block_5_rep_3_2:"
"jmp func_0_block_5_rep_3_asm_end\n"
"func_0_block_5_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_3\n"
"dummy_call_func_0_block_5_rep_3:"
"ret\n"
"end_func_0_block_5_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 832]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_4_asm_start\n"
"func_0_block_5_rep_4_asm_start:"
"add QWORD PTR[r10 + 64], rax\n"
"mov rbx, rax\n"
"sub rcx, rax\n"
"mov rbx, rax\n"
"imul rbx\n"
"jmp br_uncond_func_0_block_5_rep_4_0\n"
"br_uncond_func_0_block_5_rep_4_0:"
"test r11d, 64\n"
"jz br_cond_func_0_block_5_rep_4_0\n"
"br_cond_func_0_block_5_rep_4_0:"
"mov QWORD PTR[r10 + 0], rbx\n"
"or rbx, rbx\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_5_rep_4_1\n"
"br_cond_func_0_block_5_rep_4_1:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov rax, rax\n"
"jmp func_0_block_5_rep_4_asm_end\n"
"func_0_block_5_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_4\n"
"dummy_call_func_0_block_5_rep_4:"
"ret\n"
"end_func_0_block_5_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 704]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_5_asm_start\n"
"br_uncond_func_0_block_5_rep_5_0:"
"mov QWORD PTR[r10 + 192], rax\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_5_rep_5_0\n"
"br_cond_func_0_block_5_rep_5_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_5_rep_5_1\n"
"br_cond_func_0_block_5_rep_5_1:"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_5_rep_5_asm_end\n"
"func_0_block_5_rep_5_asm_start:"
"sub QWORD PTR[r10 + 0], rax\n"
"and rcx, rcx\n"
"mov QWORD PTR[r10 + 256], rcx\n"
"mov QWORD PTR[r10 + 128], rax\n"
"jmp br_uncond_func_0_block_5_rep_5_0\n"
"func_0_block_5_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_5\n"
"dummy_call_func_0_block_5_rep_5:"
"ret\n"
"end_func_0_block_5_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 768]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_6_asm_start\n"
"br_uncond_func_0_block_5_rep_6_0:"
"test r11d, 4096\n"
"jz br_cond_func_0_block_5_rep_6_1\n"
"br_cond_func_0_block_5_rep_6_1:"
"mov r13, QWORD PTR[r13]\n"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_5_rep_6_1\n"
"func_0_block_5_rep_6_asm_start:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_5_rep_6_0\n"
"br_cond_func_0_block_5_rep_6_0:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 192], rax\n"
"or rax, QWORD PTR[r10 + 64]\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rax, rax\n"
"jmp br_uncond_func_0_block_5_rep_6_0\n"
"br_uncond_func_0_block_5_rep_6_1:"
"jmp func_0_block_5_rep_6_asm_end\n"
"func_0_block_5_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_6\n"
"dummy_call_func_0_block_5_rep_6:"
"ret\n"
"end_func_0_block_5_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 960]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_7_asm_start\n"
"func_0_block_5_rep_7_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_5_rep_7_0\n"
"br_cond_func_0_block_5_rep_7_0:"
"mov rbx, rax\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_5_rep_7_1\n"
"br_cond_func_0_block_5_rep_7_1:"
"call dummy_call_func_0_block_5_rep_7\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_5_rep_7_2\n"
"br_cond_func_0_block_5_rep_7_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_5_rep_7_3\n"
"br_cond_func_0_block_5_rep_7_3:"
"jmp func_0_block_5_rep_7_asm_end\n"
"func_0_block_5_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_7\n"
"dummy_call_func_0_block_5_rep_7:"
"ret\n"
"end_func_0_block_5_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}


if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 704]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_9_asm_start\n"
"func_0_block_5_rep_9_asm_start:"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_5_rep_9_0\n"
"br_cond_func_0_block_5_rep_9_0:"
"or rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 256]\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, rax\n"
"and rax, QWORD PTR[r10 + 64]\n"
"mov rax, rbx\n"
"mov rcx, rdx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 192], rax\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_5_rep_9_1\n"
"br_cond_func_0_block_5_rep_9_1:"
"jmp func_0_block_5_rep_9_asm_end\n"
"func_0_block_5_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_9\n"
"dummy_call_func_0_block_5_rep_9:"
"ret\n"
"end_func_0_block_5_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 704]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_10_asm_start\n"
"func_0_block_5_rep_10_asm_start:"
"and QWORD PTR[r10 + 128], rax\n"
"add rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 256], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_5_rep_10_0\n"
"br_cond_func_0_block_5_rep_10_0:"
"or rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_5_rep_10_asm_end\n"
"func_0_block_5_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_10\n"
"dummy_call_func_0_block_5_rep_10:"
"ret\n"
"end_func_0_block_5_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 896]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_11_asm_start\n"
"func_0_block_5_rep_11_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 64]\n"
"and rcx, rdx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_5_rep_11_0\n"
"br_cond_func_0_block_5_rep_11_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, rbx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_5_rep_11_1\n"
"br_cond_func_0_block_5_rep_11_1:"
"mov rbx, rcx\n"
"or rdx, QWORD PTR[r10 + 0]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_5_rep_11_2\n"
"br_cond_func_0_block_5_rep_11_2:"
"sub rdx, rbx\n"
"jmp func_0_block_5_rep_11_asm_end\n"
"func_0_block_5_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_11\n"
"dummy_call_func_0_block_5_rep_11:"
"ret\n"
"end_func_0_block_5_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 768]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_12_asm_start\n"
"func_0_block_5_rep_12_asm_start:"
"add rax, rbx\n"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"and QWORD PTR[r10 + 192], rcx\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_5_rep_12_0\n"
"br_cond_func_0_block_5_rep_12_0:"
"mov rax, rcx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_5_rep_12_0\n"
"br_uncond_func_0_block_5_rep_12_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_5_rep_12_1\n"
"br_cond_func_0_block_5_rep_12_1:"
"jmp func_0_block_5_rep_12_asm_end\n"
"func_0_block_5_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_12\n"
"dummy_call_func_0_block_5_rep_12:"
"ret\n"
"end_func_0_block_5_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 960]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_13_asm_start\n"
"func_0_block_5_rep_13_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"imul rax\n"
"and rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_5_rep_13_0\n"
"br_cond_func_0_block_5_rep_13_0:"
"test r11d, 8\n"
"jz br_cond_func_0_block_5_rep_13_1\n"
"br_cond_func_0_block_5_rep_13_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_5_rep_13_2\n"
"br_cond_func_0_block_5_rep_13_2:"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, rbx\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_5_rep_13_asm_end\n"
"func_0_block_5_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_13\n"
"dummy_call_func_0_block_5_rep_13:"
"ret\n"
"end_func_0_block_5_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 896]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_14_asm_start\n"
"br_uncond_func_0_block_5_rep_14_0:"
"or rax, rbx\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_5_rep_14_0\n"
"br_cond_func_0_block_5_rep_14_0:"
"test r11d, 2\n"
"jz br_cond_func_0_block_5_rep_14_1\n"
"br_cond_func_0_block_5_rep_14_1:"
"and rbx, rax\n"
"mov rcx, rbx\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_5_rep_14_2\n"
"br_cond_func_0_block_5_rep_14_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_5_rep_14_asm_end\n"
"func_0_block_5_rep_14_asm_start:"
"and rbx, QWORD PTR[r10 + 64]\n"
"mov rbx, rbx\n"
"jmp br_uncond_func_0_block_5_rep_14_0\n"
"func_0_block_5_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_14\n"
"dummy_call_func_0_block_5_rep_14:"
"ret\n"
"end_func_0_block_5_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 711 && (req_id & 1023) < 654 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_5_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 832]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_5_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_5_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_5_rep_15_asm_start\n"
"func_0_block_5_rep_15_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_5_rep_15_0\n"
"br_cond_func_0_block_5_rep_15_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_5_rep_15_1\n"
"br_cond_func_0_block_5_rep_15_1:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_5_rep_15_0\n"
"br_uncond_func_0_block_5_rep_15_1:"
"sub rbx, QWORD PTR[r10 + 128]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_5_rep_15_2\n"
"br_cond_func_0_block_5_rep_15_2:"
"and rbx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_5_rep_15_asm_end\n"
"br_uncond_func_0_block_5_rep_15_0:"
"jmp br_uncond_func_0_block_5_rep_15_1\n"
"func_0_block_5_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_5_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_5_rep_15\n"
"dummy_call_func_0_block_5_rep_15:"
"ret\n"
"end_func_0_block_5_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[4]), "r" (curr_pointer_chasing_mem_addrs[4]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[4] = next_mem_addr;
curr_pointer_chasing_mem_addrs[4] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1728]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_0_asm_start\n"
"func_0_block_6_rep_0_asm_start:"
"call dummy_call_func_0_block_6_rep_0\n"
"mov QWORD PTR[r10 + 128], rax\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_6_rep_0_0\n"
"br_cond_func_0_block_6_rep_0_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rbx, rcx\n"
"mov QWORD PTR[r10 + 256], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_6_rep_0_1\n"
"br_cond_func_0_block_6_rep_0_1:"
"mov rbx, rcx\n"
"or rax, QWORD PTR[r10 + 192]\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_6_rep_0_2\n"
"br_cond_func_0_block_6_rep_0_2:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_6_rep_0_3\n"
"br_cond_func_0_block_6_rep_0_3:"
"jmp func_0_block_6_rep_0_asm_end\n"
"func_0_block_6_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_0\n"
"dummy_call_func_0_block_6_rep_0:"
"ret\n"
"end_func_0_block_6_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1856]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_1_asm_start\n"
"func_0_block_6_rep_1_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_6_rep_1_0\n"
"br_cond_func_0_block_6_rep_1_0:"
"test r11d, 1\n"
"jz br_cond_func_0_block_6_rep_1_1\n"
"br_cond_func_0_block_6_rep_1_1:"
"mov rax, rax\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_6_rep_1_2\n"
"br_cond_func_0_block_6_rep_1_2:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"jmp func_0_block_6_rep_1_asm_end\n"
"func_0_block_6_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_1\n"
"dummy_call_func_0_block_6_rep_1:"
"ret\n"
"end_func_0_block_6_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1792]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_2_asm_start\n"
"func_0_block_6_rep_2_asm_start:"
"test r11d, 512\n"
"jz br_cond_func_0_block_6_rep_2_0\n"
"br_cond_func_0_block_6_rep_2_0:"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_6_rep_2_1\n"
"br_cond_func_0_block_6_rep_2_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 192]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_6_rep_2_2\n"
"br_cond_func_0_block_6_rep_2_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"add rax, rbx\n"
"sub rbx, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_6_rep_2_asm_end\n"
"func_0_block_6_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_2\n"
"dummy_call_func_0_block_6_rep_2:"
"ret\n"
"end_func_0_block_6_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1792]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_3_asm_start\n"
"br_uncond_func_0_block_6_rep_3_0:"
"jmp func_0_block_6_rep_3_asm_end\n"
"func_0_block_6_rep_3_asm_start:"
"mov rax, rax\n"
"add rbx, QWORD PTR[r10 + 192]\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_6_rep_3_0\n"
"br_cond_func_0_block_6_rep_3_0:"
"sub rcx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rdx, rsi\n"
"or rdi, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_6_rep_3_1\n"
"br_cond_func_0_block_6_rep_3_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, r8\n"
"mov QWORD PTR[r10 + 64], rax\n"
"add r8, rsi\n"
"jmp br_uncond_func_0_block_6_rep_3_0\n"
"func_0_block_6_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_3\n"
"dummy_call_func_0_block_6_rep_3:"
"ret\n"
"end_func_0_block_6_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1728]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_4_asm_start\n"
"br_uncond_func_0_block_6_rep_4_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_6_rep_4_0\n"
"br_cond_func_0_block_6_rep_4_0:"
"add rax, rbx\n"
"call dummy_call_func_0_block_6_rep_4\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_6_rep_4_1\n"
"br_cond_func_0_block_6_rep_4_1:"
"mov QWORD PTR[r10 + 256], rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rbx, rbx\n"
"sub rcx, QWORD PTR[r10 + 192]\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"jmp func_0_block_6_rep_4_asm_end\n"
"func_0_block_6_rep_4_asm_start:"
"mov QWORD PTR[r10 + 0], rdx\n"
"jmp br_uncond_func_0_block_6_rep_4_0\n"
"func_0_block_6_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_4\n"
"dummy_call_func_0_block_6_rep_4:"
"ret\n"
"end_func_0_block_6_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1664]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_5_asm_start\n"
"func_0_block_6_rep_5_asm_start:"
"mov QWORD PTR[r10 + 192], rax\n"
"add rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_6_rep_5_0\n"
"br_cond_func_0_block_6_rep_5_0:"
"sub rbx, QWORD PTR[r10 + 64]\n"
"add rax, QWORD PTR[r10 + 320]\n"
"sub rbx, QWORD PTR[r10 + 128]\n"
"mov rcx, rax\n"
"add rdx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, rsi\n"
"sub rdx, rax\n"
"and rcx, QWORD PTR[r10 + 256]\n"
"call dummy_call_func_0_block_6_rep_5\n"
"mov QWORD PTR[r10 + 0], rsi\n"
"jmp func_0_block_6_rep_5_asm_end\n"
"func_0_block_6_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_5\n"
"dummy_call_func_0_block_6_rep_5:"
"ret\n"
"end_func_0_block_6_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}


if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1920]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_7_asm_start\n"
"br_uncond_func_0_block_6_rep_7_0:"
"mov rax, rbx\n"
"mov rcx, rax\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_6_rep_7_1\n"
"br_cond_func_0_block_6_rep_7_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_6_rep_7_2\n"
"br_cond_func_0_block_6_rep_7_2:"
"call dummy_call_func_0_block_6_rep_7\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_6_rep_7_asm_end\n"
"func_0_block_6_rep_7_asm_start:"
"mul rcx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_6_rep_7_0\n"
"br_cond_func_0_block_6_rep_7_0:"
"call dummy_call_func_0_block_6_rep_7\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_6_rep_7_0\n"
"func_0_block_6_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_7\n"
"dummy_call_func_0_block_6_rep_7:"
"ret\n"
"end_func_0_block_6_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1920]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_8_asm_start\n"
"func_0_block_6_rep_8_asm_start:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_6_rep_8_0\n"
"br_cond_func_0_block_6_rep_8_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rax\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_6_rep_8_1\n"
"br_cond_func_0_block_6_rep_8_1:"
"call dummy_call_func_0_block_6_rep_8\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_6_rep_8_2\n"
"br_cond_func_0_block_6_rep_8_2:"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_6_rep_8_3\n"
"br_cond_func_0_block_6_rep_8_3:"
"jmp func_0_block_6_rep_8_asm_end\n"
"func_0_block_6_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_8\n"
"dummy_call_func_0_block_6_rep_8:"
"ret\n"
"end_func_0_block_6_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1792]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_9_asm_start\n"
"func_0_block_6_rep_9_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_6_rep_9_0\n"
"br_cond_func_0_block_6_rep_9_0:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_6_rep_9\n"
"mov rcx, rcx\n"
"or rcx, rcx\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"or QWORD PTR[r10 + 0], rbx\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_6_rep_9_1\n"
"br_cond_func_0_block_6_rep_9_1:"
"jmp func_0_block_6_rep_9_asm_end\n"
"func_0_block_6_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_9\n"
"dummy_call_func_0_block_6_rep_9:"
"ret\n"
"end_func_0_block_6_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1984]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_10_asm_start\n"
"func_0_block_6_rep_10_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and QWORD PTR[r10 + 0], rax\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_6_rep_10_0\n"
"br_cond_func_0_block_6_rep_10_0:"
"call dummy_call_func_0_block_6_rep_10\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_6_rep_10_1\n"
"br_cond_func_0_block_6_rep_10_1:"
"or rax, rax\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_6_rep_10_2\n"
"br_cond_func_0_block_6_rep_10_2:"
"mov r13, QWORD PTR[r13]\n"
"add rax, rbx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_6_rep_10_3\n"
"br_cond_func_0_block_6_rep_10_3:"
"jmp func_0_block_6_rep_10_asm_end\n"
"func_0_block_6_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_10\n"
"dummy_call_func_0_block_6_rep_10:"
"ret\n"
"end_func_0_block_6_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1664]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_11_asm_start\n"
"func_0_block_6_rep_11_asm_start:"
"or rax, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"and rax, QWORD PTR[r10 + 320]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rax, QWORD PTR[r10 + 192]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_6_rep_11_0\n"
"br_cond_func_0_block_6_rep_11_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_6_rep_11_1\n"
"br_cond_func_0_block_6_rep_11_1:"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 256]\n"
"sub rbx, QWORD PTR[r10 + 128]\n"
"add rbx, rcx\n"
"jmp br_uncond_func_0_block_6_rep_11_0\n"
"br_uncond_func_0_block_6_rep_11_0:"
"jmp func_0_block_6_rep_11_asm_end\n"
"func_0_block_6_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_11\n"
"dummy_call_func_0_block_6_rep_11:"
"ret\n"
"end_func_0_block_6_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1856]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_12_asm_start\n"
"func_0_block_6_rep_12_asm_start:"
"test r11d, 2\n"
"jz br_cond_func_0_block_6_rep_12_0\n"
"br_cond_func_0_block_6_rep_12_0:"
"test r11d, 512\n"
"jz br_cond_func_0_block_6_rep_12_1\n"
"br_cond_func_0_block_6_rep_12_1:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_6_rep_12_2\n"
"br_cond_func_0_block_6_rep_12_2:"
"mov r13, QWORD PTR[r13]\n"
"add rax, QWORD PTR[r10 + 0]\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_6_rep_12_3\n"
"br_cond_func_0_block_6_rep_12_3:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_6_rep_12_4\n"
"br_cond_func_0_block_6_rep_12_4:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_6_rep_12_5\n"
"br_cond_func_0_block_6_rep_12_5:"
"jmp func_0_block_6_rep_12_asm_end\n"
"func_0_block_6_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_12\n"
"dummy_call_func_0_block_6_rep_12:"
"ret\n"
"end_func_0_block_6_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1792]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_13_asm_start\n"
"func_0_block_6_rep_13_asm_start:"
"call dummy_call_func_0_block_6_rep_13\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_6_rep_13_0\n"
"br_cond_func_0_block_6_rep_13_0:"
"mov rbx, rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_6_rep_13_1\n"
"br_cond_func_0_block_6_rep_13_1:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"sub rax, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov rax, rcx\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_6_rep_13_2\n"
"br_cond_func_0_block_6_rep_13_2:"
"jmp func_0_block_6_rep_13_asm_end\n"
"func_0_block_6_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_13\n"
"dummy_call_func_0_block_6_rep_13:"
"ret\n"
"end_func_0_block_6_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1984]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_14_asm_start\n"
"func_0_block_6_rep_14_asm_start:"
"or rax, rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_6_rep_14_0\n"
"br_cond_func_0_block_6_rep_14_0:"
"mov rax, rax\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_6_rep_14_1\n"
"br_cond_func_0_block_6_rep_14_1:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_6_rep_14_2\n"
"br_cond_func_0_block_6_rep_14_2:"
"mov rax, rbx\n"
"call dummy_call_func_0_block_6_rep_14\n"
"mov rax, rax\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_6_rep_14_3\n"
"br_cond_func_0_block_6_rep_14_3:"
"or rax, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov rax, rax\n"
"jmp func_0_block_6_rep_14_asm_end\n"
"func_0_block_6_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_14\n"
"dummy_call_func_0_block_6_rep_14:"
"ret\n"
"end_func_0_block_6_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 654 && (req_id & 1023) < 716 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_6_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 1856]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_6_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_6_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_6_rep_15_asm_start\n"
"func_0_block_6_rep_15_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_6_rep_15_0\n"
"br_cond_func_0_block_6_rep_15_0:"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rdx, rcx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_6_rep_15_1\n"
"br_cond_func_0_block_6_rep_15_1:"
"mov r13, QWORD PTR[r13]\n"
"add rcx, rcx\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_6_rep_15_2\n"
"br_cond_func_0_block_6_rep_15_2:"
"jmp func_0_block_6_rep_15_asm_end\n"
"func_0_block_6_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_6_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_6_rep_15\n"
"dummy_call_func_0_block_6_rep_15:"
"ret\n"
"end_func_0_block_6_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[5]), "r" (curr_pointer_chasing_mem_addrs[5]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[5] = next_mem_addr;
curr_pointer_chasing_mem_addrs[5] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3968]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_0_asm_start\n"
"func_0_block_7_rep_0_asm_start:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_7_rep_0_0\n"
"br_cond_func_0_block_7_rep_0_0:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"add rax, rbx\n"
"mov rbx, rax\n"
"mov rdx, rax\n"
"mov rbx, rax\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_7_rep_0_1\n"
"br_cond_func_0_block_7_rep_0_1:"
"mov rdx, rdx\n"
"add rsi, QWORD PTR[r10 + 0]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_7_rep_0_2\n"
"br_cond_func_0_block_7_rep_0_2:"
"mov rdi, rbx\n"
"jmp func_0_block_7_rep_0_asm_end\n"
"func_0_block_7_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_0\n"
"dummy_call_func_0_block_7_rep_0:"
"ret\n"
"end_func_0_block_7_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3776]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_1_asm_start\n"
"func_0_block_7_rep_1_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 256], rbx\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_7_rep_1_0\n"
"br_cond_func_0_block_7_rep_1_0:"
"and rcx, QWORD PTR[r10 + 192]\n"
"or rbx, rdx\n"
"mov rax, rdx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rdx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_7_rep_1_asm_end\n"
"func_0_block_7_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_1\n"
"dummy_call_func_0_block_7_rep_1:"
"ret\n"
"end_func_0_block_7_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3968]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_2_asm_start\n"
"func_0_block_7_rep_2_asm_start:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_7_rep_2_0\n"
"br_cond_func_0_block_7_rep_2_0:"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_7_rep_2_1\n"
"br_cond_func_0_block_7_rep_2_1:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_7_rep_2_0\n"
"br_uncond_func_0_block_7_rep_2_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_7_rep_2_2\n"
"br_cond_func_0_block_7_rep_2_2:"
"mov rax, rax\n"
"jmp func_0_block_7_rep_2_asm_end\n"
"func_0_block_7_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_2\n"
"dummy_call_func_0_block_7_rep_2:"
"ret\n"
"end_func_0_block_7_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 4032]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_3_asm_start\n"
"func_0_block_7_rep_3_asm_start:"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_7_rep_3_0\n"
"br_cond_func_0_block_7_rep_3_0:"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 0]\n"
"add rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov rcx, rbx\n"
"mov rbx, rcx\n"
"mov rcx, rax\n"
"call dummy_call_func_0_block_7_rep_3\n"
"mov rdx, rcx\n"
"jmp func_0_block_7_rep_3_asm_end\n"
"func_0_block_7_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_3\n"
"dummy_call_func_0_block_7_rep_3:"
"ret\n"
"end_func_0_block_7_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3776]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_4_asm_start\n"
"func_0_block_7_rep_4_asm_start:"
"or rax, rbx\n"
"jmp br_uncond_func_0_block_7_rep_4_0\n"
"br_uncond_func_0_block_7_rep_4_0:"
"and rax, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"and rbx, QWORD PTR[r10 + 128]\n"
"and rax, QWORD PTR[r10 + 192]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_7_rep_4_0\n"
"br_cond_func_0_block_7_rep_4_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 256], rcx\n"
"mov rax, rbx\n"
"add rax, QWORD PTR[r10 + 0]\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_7_rep_4_1\n"
"br_cond_func_0_block_7_rep_4_1:"
"jmp func_0_block_7_rep_4_asm_end\n"
"func_0_block_7_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_4\n"
"dummy_call_func_0_block_7_rep_4:"
"ret\n"
"end_func_0_block_7_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3840]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_5_asm_start\n"
"func_0_block_7_rep_5_asm_start:"
"test r11d, 2\n"
"jz br_cond_func_0_block_7_rep_5_0\n"
"br_cond_func_0_block_7_rep_5_0:"
"sub rax, QWORD PTR[r10 + 128]\n"
"jmp br_uncond_func_0_block_7_rep_5_0\n"
"br_uncond_func_0_block_7_rep_5_0:"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rcx\n"
"or rcx, QWORD PTR[r10 + 64]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov rdx, rcx\n"
"mov rcx, rdx\n"
"mov rbx, rcx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_7_rep_5_1\n"
"br_cond_func_0_block_7_rep_5_1:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_7_rep_5_asm_end\n"
"func_0_block_7_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_5\n"
"dummy_call_func_0_block_7_rep_5:"
"ret\n"
"end_func_0_block_7_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3968]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_6_asm_start\n"
"func_0_block_7_rep_6_asm_start:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_7_rep_6_0\n"
"br_cond_func_0_block_7_rep_6_0:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_7_rep_6_1\n"
"br_cond_func_0_block_7_rep_6_1:"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_7_rep_6_2\n"
"br_cond_func_0_block_7_rep_6_2:"
"mov r13, QWORD PTR[r13]\n"
"and rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 2048\n"
"jz br_cond_func_0_block_7_rep_6_3\n"
"br_cond_func_0_block_7_rep_6_3:"
"jmp br_uncond_func_0_block_7_rep_6_0\n"
"br_uncond_func_0_block_7_rep_6_0:"
"mov QWORD PTR[r10 + 0], rcx\n"
"jmp func_0_block_7_rep_6_asm_end\n"
"func_0_block_7_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_6\n"
"dummy_call_func_0_block_7_rep_6:"
"ret\n"
"end_func_0_block_7_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 4032]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_7_asm_start\n"
"br_uncond_func_0_block_7_rep_7_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"or rbx, rax\n"
"jmp func_0_block_7_rep_7_asm_end\n"
"func_0_block_7_rep_7_asm_start:"
"test r11d, 512\n"
"jz br_cond_func_0_block_7_rep_7_0\n"
"br_cond_func_0_block_7_rep_7_0:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_7_rep_7_1\n"
"br_cond_func_0_block_7_rep_7_1:"
"mov rbx, rbx\n"
"or rcx, rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_7_rep_7_2\n"
"br_cond_func_0_block_7_rep_7_2:"
"add rcx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_7_rep_7_0\n"
"func_0_block_7_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_7\n"
"dummy_call_func_0_block_7_rep_7:"
"ret\n"
"end_func_0_block_7_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3712]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_8_asm_start\n"
"func_0_block_7_rep_8_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 256], rax\n"
"or rbx, QWORD PTR[r10 + 128]\n"
"or rbx, rax\n"
"add rax, QWORD PTR[r10 + 320]\n"
"add rcx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_7_rep_8_0\n"
"br_cond_func_0_block_7_rep_8_0:"
"mov QWORD PTR[r10 + 192], rdx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_7_rep_8_1\n"
"br_cond_func_0_block_7_rep_8_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_7_rep_8_2\n"
"br_cond_func_0_block_7_rep_8_2:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_7_rep_8_asm_end\n"
"func_0_block_7_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_8\n"
"dummy_call_func_0_block_7_rep_8:"
"ret\n"
"end_func_0_block_7_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3904]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_9_asm_start\n"
"func_0_block_7_rep_9_asm_start:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_7_rep_9_0\n"
"br_cond_func_0_block_7_rep_9_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_7_rep_9_1\n"
"br_cond_func_0_block_7_rep_9_1:"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"call dummy_call_func_0_block_7_rep_9\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_7_rep_9_2\n"
"br_cond_func_0_block_7_rep_9_2:"
"jmp func_0_block_7_rep_9_asm_end\n"
"func_0_block_7_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_9\n"
"dummy_call_func_0_block_7_rep_9:"
"ret\n"
"end_func_0_block_7_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 3904]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_10_asm_start\n"
"func_0_block_7_rep_10_asm_start:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_7_rep_10_0\n"
"br_cond_func_0_block_7_rep_10_0:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 64]\n"
"mov rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rbx\n"
"mov rdx, rax\n"
"mov rax, rdx\n"
"or rsi, rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"add rax, rdi\n"
"mov rcx, rdx\n"
"jmp func_0_block_7_rep_10_asm_end\n"
"func_0_block_7_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_10\n"
"dummy_call_func_0_block_7_rep_10:"
"ret\n"
"end_func_0_block_7_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 4032]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_11_asm_start\n"
"func_0_block_7_rep_11_asm_start:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_7_rep_11_0\n"
"br_cond_func_0_block_7_rep_11_0:"
"and rax, rbx\n"
"call dummy_call_func_0_block_7_rep_11\n"
"mov rcx, rbx\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_7_rep_11_1\n"
"br_cond_func_0_block_7_rep_11_1:"
"add rbx, rbx\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_7_rep_11_2\n"
"br_cond_func_0_block_7_rep_11_2:"
"test r11d, 128\n"
"jz br_cond_func_0_block_7_rep_11_3\n"
"br_cond_func_0_block_7_rep_11_3:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_7_rep_11_4\n"
"br_cond_func_0_block_7_rep_11_4:"
"jmp func_0_block_7_rep_11_asm_end\n"
"func_0_block_7_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_11\n"
"dummy_call_func_0_block_7_rep_11:"
"ret\n"
"end_func_0_block_7_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}


if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 4032]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_13_asm_start\n"
"func_0_block_7_rep_13_asm_start:"
"and rax, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"add rax, rbx\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_7_rep_13_0\n"
"br_cond_func_0_block_7_rep_13_0:"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_7_rep_13_1\n"
"br_cond_func_0_block_7_rep_13_1:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_7_rep_13_2\n"
"br_cond_func_0_block_7_rep_13_2:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_7_rep_13_3\n"
"br_cond_func_0_block_7_rep_13_3:"
"jmp func_0_block_7_rep_13_asm_end\n"
"func_0_block_7_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_13\n"
"dummy_call_func_0_block_7_rep_13:"
"ret\n"
"end_func_0_block_7_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 716 && (req_id & 1023) < 761 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_7_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 4032]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_7_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_7_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_7_rep_14_asm_start\n"
"func_0_block_7_rep_14_asm_start:"
"add rax, rbx\n"
"jmp br_uncond_func_0_block_7_rep_14_0\n"
"br_uncond_func_0_block_7_rep_14_0:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_7_rep_14_0\n"
"br_cond_func_0_block_7_rep_14_0:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_7_rep_14_1\n"
"br_cond_func_0_block_7_rep_14_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_7_rep_14_2\n"
"br_cond_func_0_block_7_rep_14_2:"
"and rbx, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_7_rep_14_asm_end\n"
"func_0_block_7_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_7_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_7_rep_14\n"
"dummy_call_func_0_block_7_rep_14:"
"ret\n"
"end_func_0_block_7_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[6]), "r" (curr_pointer_chasing_mem_addrs[6]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[6] = next_mem_addr;
curr_pointer_chasing_mem_addrs[6] = next_pointer_chasing_mem_addr;
}


if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 8128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_0_asm_start\n"
"func_0_block_8_rep_0_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_8_rep_0_0\n"
"br_cond_func_0_block_8_rep_0_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mov rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rax\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_8_rep_0_1\n"
"br_cond_func_0_block_8_rep_0_1:"
"mov rax, rcx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_8_rep_0_2\n"
"br_cond_func_0_block_8_rep_0_2:"
"jmp func_0_block_8_rep_0_asm_end\n"
"func_0_block_8_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_0\n"
"dummy_call_func_0_block_8_rep_0:"
"ret\n"
"end_func_0_block_8_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7616]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_1_asm_start\n"
"br_uncond_func_0_block_8_rep_1_0:"
"sub rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 256], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_8_rep_1_asm_end\n"
"func_0_block_8_rep_1_asm_start:"
"mov QWORD PTR[r10 + 512], rax\n"
"or rcx, QWORD PTR[r10 + 320]\n"
"add rcx, QWORD PTR[r10 + 448]\n"
"call dummy_call_func_0_block_8_rep_1\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"or rcx, QWORD PTR[r10 + 384]\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_8_rep_1_0\n"
"br_cond_func_0_block_8_rep_1_0:"
"and rbx, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_8_rep_1_0\n"
"func_0_block_8_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 576\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_1\n"
"dummy_call_func_0_block_8_rep_1:"
"ret\n"
"end_func_0_block_8_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7936]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_2_asm_start\n"
"func_0_block_8_rep_2_asm_start:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_8_rep_2_0\n"
"br_cond_func_0_block_8_rep_2_0:"
"or rax, rbx\n"
"or rax, rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_8_rep_2_1\n"
"br_cond_func_0_block_8_rep_2_1:"
"mov QWORD PTR[r10 + 128], rbx\n"
"call dummy_call_func_0_block_8_rep_2\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"sub rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_8_rep_2_asm_end\n"
"func_0_block_8_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_2\n"
"dummy_call_func_0_block_8_rep_2:"
"ret\n"
"end_func_0_block_8_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7872]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_3_asm_start\n"
"func_0_block_8_rep_3_asm_start:"
"jmp br_uncond_func_0_block_8_rep_3_0\n"
"br_uncond_func_0_block_8_rep_3_0:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_8_rep_3_0\n"
"br_cond_func_0_block_8_rep_3_0:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_8_rep_3_1\n"
"br_cond_func_0_block_8_rep_3_1:"
"test r11d, 16\n"
"jz br_cond_func_0_block_8_rep_3_2\n"
"br_cond_func_0_block_8_rep_3_2:"
"or rax, QWORD PTR[r10 + 256]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rax, QWORD PTR[r10 + 192]\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov rax, rax\n"
"jmp func_0_block_8_rep_3_asm_end\n"
"func_0_block_8_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_3\n"
"dummy_call_func_0_block_8_rep_3:"
"ret\n"
"end_func_0_block_8_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 8064]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_4_asm_start\n"
"br_uncond_func_0_block_8_rep_4_0:"
"mov rax, rbx\n"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_8_rep_4_0\n"
"br_cond_func_0_block_8_rep_4_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"sub rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_8_rep_4_1\n"
"br_cond_func_0_block_8_rep_4_1:"
"jmp func_0_block_8_rep_4_asm_end\n"
"func_0_block_8_rep_4_asm_start:"
"add rax, QWORD PTR[r10 + 0]\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_8_rep_4_0\n"
"func_0_block_8_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_4\n"
"dummy_call_func_0_block_8_rep_4:"
"ret\n"
"end_func_0_block_8_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7808]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_5_asm_start\n"
"br_uncond_func_0_block_8_rep_5_0:"
"or rax, QWORD PTR[r10 + 128]\n"
"and QWORD PTR[r10 + 64], rbx\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_8_rep_5_1\n"
"br_cond_func_0_block_8_rep_5_1:"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 256], rax\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_8_rep_5_asm_end\n"
"func_0_block_8_rep_5_asm_start:"
"sub rbx, rbx\n"
"add rax, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 320]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_8_rep_5_0\n"
"br_cond_func_0_block_8_rep_5_0:"
"jmp br_uncond_func_0_block_8_rep_5_0\n"
"func_0_block_8_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_5\n"
"dummy_call_func_0_block_8_rep_5:"
"ret\n"
"end_func_0_block_8_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7808]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_6_asm_start\n"
"br_uncond_func_0_block_8_rep_6_0:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_8_rep_6_1\n"
"br_cond_func_0_block_8_rep_6_1:"
"jmp func_0_block_8_rep_6_asm_end\n"
"func_0_block_8_rep_6_asm_start:"
"mov rax, rax\n"
"mov rbx, rax\n"
"and rcx, QWORD PTR[r10 + 320]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov QWORD PTR[r10 + 256], rdx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_8_rep_6_0\n"
"br_cond_func_0_block_8_rep_6_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rdx\n"
"mov rax, rbx\n"
"jmp br_uncond_func_0_block_8_rep_6_0\n"
"func_0_block_8_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_6\n"
"dummy_call_func_0_block_8_rep_6:"
"ret\n"
"end_func_0_block_8_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7936]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_7_asm_start\n"
"br_uncond_func_0_block_8_rep_7_0:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_8_rep_7_0\n"
"br_cond_func_0_block_8_rep_7_0:"
"call dummy_call_func_0_block_8_rep_7\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rax, rbx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_8_rep_7_1\n"
"br_cond_func_0_block_8_rep_7_1:"
"mov rax, rbx\n"
"or rax, QWORD PTR[r10 + 0]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rcx\n"
"jmp func_0_block_8_rep_7_asm_end\n"
"func_0_block_8_rep_7_asm_start:"
"sub rbx, QWORD PTR[r10 + 128]\n"
"jmp br_uncond_func_0_block_8_rep_7_0\n"
"func_0_block_8_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_7\n"
"dummy_call_func_0_block_8_rep_7:"
"ret\n"
"end_func_0_block_8_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7680]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_8_asm_start\n"
"br_uncond_func_0_block_8_rep_8_0:"
"mov QWORD PTR[r10 + 320], rax\n"
"mov QWORD PTR[r10 + 192], rax\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_8_rep_8_0\n"
"br_cond_func_0_block_8_rep_8_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 256], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"and rcx, QWORD PTR[r10 + 448]\n"
"sub rbx, QWORD PTR[r10 + 384]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_8_rep_8_asm_end\n"
"func_0_block_8_rep_8_asm_start:"
"jmp br_uncond_func_0_block_8_rep_8_0\n"
"func_0_block_8_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 512\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_8\n"
"dummy_call_func_0_block_8_rep_8:"
"ret\n"
"end_func_0_block_8_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 8000]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_9_asm_start\n"
"br_uncond_func_0_block_8_rep_9_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_8_rep_9_0\n"
"br_cond_func_0_block_8_rep_9_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_8_rep_9_1\n"
"br_cond_func_0_block_8_rep_9_1:"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_8_rep_9_2\n"
"br_cond_func_0_block_8_rep_9_2:"
"sub rax, QWORD PTR[r10 + 128]\n"
"jmp func_0_block_8_rep_9_asm_end\n"
"func_0_block_8_rep_9_asm_start:"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov rax, rax\n"
"jmp br_uncond_func_0_block_8_rep_9_0\n"
"func_0_block_8_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_9\n"
"dummy_call_func_0_block_8_rep_9:"
"ret\n"
"end_func_0_block_8_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7872]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_10_asm_start\n"
"func_0_block_8_rep_10_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 256], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"sub rcx, QWORD PTR[r10 + 0]\n"
"sub rcx, QWORD PTR[r10 + 128]\n"
"call dummy_call_func_0_block_8_rep_10\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_8_rep_10_asm_end\n"
"func_0_block_8_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_10\n"
"dummy_call_func_0_block_8_rep_10:"
"ret\n"
"end_func_0_block_8_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7936]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_11_asm_start\n"
"br_uncond_func_0_block_8_rep_11_0:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_8_rep_11_2\n"
"br_cond_func_0_block_8_rep_11_2:"
"mov QWORD PTR[r10 + 0], rax\n"
"sub rbx, rbx\n"
"jmp func_0_block_8_rep_11_asm_end\n"
"func_0_block_8_rep_11_asm_start:"
"or rcx, QWORD PTR[r10 + 64]\n"
"and rax, QWORD PTR[r10 + 128]\n"
"mov rbx, rdx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_8_rep_11_0\n"
"br_cond_func_0_block_8_rep_11_0:"
"test r11d, 512\n"
"jz br_cond_func_0_block_8_rep_11_1\n"
"br_cond_func_0_block_8_rep_11_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"add rbx, rbx\n"
"mov rax, rbx\n"
"jmp br_uncond_func_0_block_8_rep_11_0\n"
"func_0_block_8_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_11\n"
"dummy_call_func_0_block_8_rep_11:"
"ret\n"
"end_func_0_block_8_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7936]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_12_asm_start\n"
"func_0_block_8_rep_12_asm_start:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rcx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rbx\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_8_rep_12_0\n"
"br_cond_func_0_block_8_rep_12_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_8_rep_12_1\n"
"br_cond_func_0_block_8_rep_12_1:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov QWORD PTR[r10 + 128], rax\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_8_rep_12_2\n"
"br_cond_func_0_block_8_rep_12_2:"
"mov rax, rax\n"
"jmp func_0_block_8_rep_12_asm_end\n"
"func_0_block_8_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_12\n"
"dummy_call_func_0_block_8_rep_12:"
"ret\n"
"end_func_0_block_8_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7872]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_13_asm_start\n"
"func_0_block_8_rep_13_asm_start:"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rbx, rax\n"
"call dummy_call_func_0_block_8_rep_13\n"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, QWORD PTR[r10 + 64]\n"
"add rdx, rcx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_8_rep_13_0\n"
"br_cond_func_0_block_8_rep_13_0:"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 128]\n"
"or rsi, rdi\n"
"sub rdi, QWORD PTR[r10 + 256]\n"
"add r8, r9\n"
"mov r13, QWORD PTR[r13]\n"
"add rdx, QWORD PTR[r10 + 192]\n"
"jmp func_0_block_8_rep_13_asm_end\n"
"func_0_block_8_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_13\n"
"dummy_call_func_0_block_8_rep_13:"
"ret\n"
"end_func_0_block_8_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 7744]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_14_asm_start\n"
"func_0_block_8_rep_14_asm_start:"
"or rax, QWORD PTR[r10 + 384]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"add rdx, QWORD PTR[r10 + 320]\n"
"or rcx, rdx\n"
"mov QWORD PTR[r10 + 256], rcx\n"
"or rsi, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rsi, rcx\n"
"add rsi, QWORD PTR[r10 + 192]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_8_rep_14_asm_end\n"
"func_0_block_8_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 448\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_14\n"
"dummy_call_func_0_block_8_rep_14:"
"ret\n"
"end_func_0_block_8_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 761 && (req_id & 1023) < 799 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_8_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 8000]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_8_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_8_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_8_rep_15_asm_start\n"
"func_0_block_8_rep_15_asm_start:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_8_rep_15_0\n"
"br_cond_func_0_block_8_rep_15_0:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_8_rep_15_1\n"
"br_cond_func_0_block_8_rep_15_1:"
"add rax, rbx\n"
"mov rax, rbx\n"
"and rcx, QWORD PTR[r10 + 64]\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_8_rep_15_2\n"
"br_cond_func_0_block_8_rep_15_2:"
"call dummy_call_func_0_block_8_rep_15\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rbx\n"
"sub rdx, rbx\n"
"call dummy_call_func_0_block_8_rep_15\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"jmp func_0_block_8_rep_15_asm_end\n"
"func_0_block_8_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_8_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_8_rep_15\n"
"dummy_call_func_0_block_8_rep_15:"
"ret\n"
"end_func_0_block_8_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[7]), "r" (curr_pointer_chasing_mem_addrs[7]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[7] = next_mem_addr;
curr_pointer_chasing_mem_addrs[7] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16256]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_0_asm_start\n"
"func_0_block_9_rep_0_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_9_rep_0_0\n"
"br_cond_func_0_block_9_rep_0_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_9_rep_0_1\n"
"br_cond_func_0_block_9_rep_0_1:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_9_rep_0_2\n"
"br_cond_func_0_block_9_rep_0_2:"
"call dummy_call_func_0_block_9_rep_0\n"
"test r11d, 32768\n"
"jz br_cond_func_0_block_9_rep_0_3\n"
"br_cond_func_0_block_9_rep_0_3:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"jmp func_0_block_9_rep_0_asm_end\n"
"func_0_block_9_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_0\n"
"dummy_call_func_0_block_9_rep_0:"
"ret\n"
"end_func_0_block_9_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16256]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_1_asm_start\n"
"func_0_block_9_rep_1_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_9_rep_1_0\n"
"br_cond_func_0_block_9_rep_1_0:"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_9_rep_1_1\n"
"br_cond_func_0_block_9_rep_1_1:"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_9_rep_1_2\n"
"br_cond_func_0_block_9_rep_1_2:"
"mov rax, rax\n"
"jmp func_0_block_9_rep_1_asm_end\n"
"func_0_block_9_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_1\n"
"dummy_call_func_0_block_9_rep_1:"
"ret\n"
"end_func_0_block_9_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_2_asm_start\n"
"func_0_block_9_rep_2_asm_start:"
"add rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, rcx\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_9_rep_2_0\n"
"br_cond_func_0_block_9_rep_2_0:"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_9_rep_2\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_9_rep_2_1\n"
"br_cond_func_0_block_9_rep_2_1:"
"mov QWORD PTR[r10 + 192], rax\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_9_rep_2_2\n"
"br_cond_func_0_block_9_rep_2_2:"
"jmp func_0_block_9_rep_2_asm_end\n"
"func_0_block_9_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_2\n"
"dummy_call_func_0_block_9_rep_2:"
"ret\n"
"end_func_0_block_9_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16256]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_3_asm_start\n"
"func_0_block_9_rep_3_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rbx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_9_rep_3_0\n"
"br_cond_func_0_block_9_rep_3_0:"
"add rcx, QWORD PTR[r10 + 64]\n"
"or rax, rcx\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_9_rep_3_1\n"
"br_cond_func_0_block_9_rep_3_1:"
"sub rdx, rdx\n"
"mov r13, QWORD PTR[r13]\n"
"and rbx, rbx\n"
"call dummy_call_func_0_block_9_rep_3\n"
"jmp func_0_block_9_rep_3_asm_end\n"
"func_0_block_9_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_3\n"
"dummy_call_func_0_block_9_rep_3:"
"ret\n"
"end_func_0_block_9_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}


if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16192]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_5_asm_start\n"
"func_0_block_9_rep_5_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_9_rep_5_0\n"
"br_cond_func_0_block_9_rep_5_0:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rcx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_9_rep_5_1\n"
"br_cond_func_0_block_9_rep_5_1:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 128]\n"
"mov rcx, rbx\n"
"mov rdx, rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"jmp func_0_block_9_rep_5_asm_end\n"
"func_0_block_9_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_5\n"
"dummy_call_func_0_block_9_rep_5:"
"ret\n"
"end_func_0_block_9_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16320]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_6_asm_start\n"
"br_uncond_func_0_block_9_rep_6_0:"
"test r11d, 16384\n"
"jz br_cond_func_0_block_9_rep_6_1\n"
"br_cond_func_0_block_9_rep_6_1:"
"mov rax, rax\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_9_rep_6_2\n"
"br_cond_func_0_block_9_rep_6_2:"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_9_rep_6_3\n"
"br_cond_func_0_block_9_rep_6_3:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_9_rep_6_4\n"
"br_cond_func_0_block_9_rep_6_4:"
"jmp func_0_block_9_rep_6_asm_end\n"
"func_0_block_9_rep_6_asm_start:"
"call dummy_call_func_0_block_9_rep_6\n"
"mov rax, rax\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_9_rep_6_0\n"
"br_cond_func_0_block_9_rep_6_0:"
"call dummy_call_func_0_block_9_rep_6\n"
"jmp br_uncond_func_0_block_9_rep_6_0\n"
"func_0_block_9_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_6\n"
"dummy_call_func_0_block_9_rep_6:"
"ret\n"
"end_func_0_block_9_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_7_asm_start\n"
"func_0_block_9_rep_7_asm_start:"
"add rax, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"call dummy_call_func_0_block_9_rep_7\n"
"or QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_9_rep_7_0\n"
"br_cond_func_0_block_9_rep_7_0:"
"and rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, rcx\n"
"mov rbx, rax\n"
"sub rdx, QWORD PTR[r10 + 64]\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_9_rep_7_1\n"
"br_cond_func_0_block_9_rep_7_1:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rdx\n"
"jmp func_0_block_9_rep_7_asm_end\n"
"func_0_block_9_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_7\n"
"dummy_call_func_0_block_9_rep_7:"
"ret\n"
"end_func_0_block_9_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_8_asm_start\n"
"func_0_block_9_rep_8_asm_start:"
"add rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov QWORD PTR[r10 + 128], rax\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_9_rep_8_0\n"
"br_cond_func_0_block_9_rep_8_0:"
"sub rcx, rax\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rdx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_9_rep_8_asm_end\n"
"func_0_block_9_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_8\n"
"dummy_call_func_0_block_9_rep_8:"
"ret\n"
"end_func_0_block_9_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_9_asm_start\n"
"func_0_block_9_rep_9_asm_start:"
"mov rax, rbx\n"
"sub rax, QWORD PTR[r10 + 0]\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"add rax, QWORD PTR[r10 + 64]\n"
"mov rax, rbx\n"
"jmp br_uncond_func_0_block_9_rep_9_0\n"
"br_uncond_func_0_block_9_rep_9_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov rcx, rbx\n"
"call dummy_call_func_0_block_9_rep_9\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov rax, rax\n"
"mov rcx, rax\n"
"mov rax, rcx\n"
"jmp func_0_block_9_rep_9_asm_end\n"
"func_0_block_9_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_9\n"
"dummy_call_func_0_block_9_rep_9:"
"ret\n"
"end_func_0_block_9_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 15936]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_10_asm_start\n"
"func_0_block_9_rep_10_asm_start:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_9_rep_10_0\n"
"br_cond_func_0_block_9_rep_10_0:"
"sub rax, QWORD PTR[r10 + 192]\n"
"add rbx, QWORD PTR[r10 + 384]\n"
"add rax, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_9_rep_10\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, QWORD PTR[r10 + 320]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"add rbx, QWORD PTR[r10 + 256]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rbx, rbx\n"
"jmp func_0_block_9_rep_10_asm_end\n"
"func_0_block_9_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 448\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_10\n"
"dummy_call_func_0_block_9_rep_10:"
"ret\n"
"end_func_0_block_9_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16320]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_11_asm_start\n"
"func_0_block_9_rep_11_asm_start:"
"test r11d, 16\n"
"jz br_cond_func_0_block_9_rep_11_0\n"
"br_cond_func_0_block_9_rep_11_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_9_rep_11_1\n"
"br_cond_func_0_block_9_rep_11_1:"
"add rax, rbx\n"
"mov rbx, rax\n"
"imul rcx\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_9_rep_11_2\n"
"br_cond_func_0_block_9_rep_11_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_9_rep_11_3\n"
"br_cond_func_0_block_9_rep_11_3:"
"jmp func_0_block_9_rep_11_asm_end\n"
"func_0_block_9_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_11\n"
"dummy_call_func_0_block_9_rep_11:"
"ret\n"
"end_func_0_block_9_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16128]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_12_asm_start\n"
"func_0_block_9_rep_12_asm_start:"
"test r11d, 128\n"
"jz br_cond_func_0_block_9_rep_12_0\n"
"br_cond_func_0_block_9_rep_12_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_9_rep_12_1\n"
"br_cond_func_0_block_9_rep_12_1:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_9_rep_12_2\n"
"br_cond_func_0_block_9_rep_12_2:"
"test r11d, 16\n"
"jz br_cond_func_0_block_9_rep_12_3\n"
"br_cond_func_0_block_9_rep_12_3:"
"call dummy_call_func_0_block_9_rep_12\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_9_rep_12_4\n"
"br_cond_func_0_block_9_rep_12_4:"
"sub rbx, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"jmp func_0_block_9_rep_12_asm_end\n"
"func_0_block_9_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_12\n"
"dummy_call_func_0_block_9_rep_12:"
"ret\n"
"end_func_0_block_9_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16192]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_13_asm_start\n"
"func_0_block_9_rep_13_asm_start:"
"mov QWORD PTR[r10 + 128], rax\n"
"add rax, rax\n"
"call dummy_call_func_0_block_9_rep_13\n"
"test r11d, 16\n"
"jz br_cond_func_0_block_9_rep_13_0\n"
"br_cond_func_0_block_9_rep_13_0:"
"mov QWORD PTR[r10 + 64], rbx\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_9_rep_13_1\n"
"br_cond_func_0_block_9_rep_13_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_9_rep_13_2\n"
"br_cond_func_0_block_9_rep_13_2:"
"jmp func_0_block_9_rep_13_asm_end\n"
"func_0_block_9_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_13\n"
"dummy_call_func_0_block_9_rep_13:"
"ret\n"
"end_func_0_block_9_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16192]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_14_asm_start\n"
"func_0_block_9_rep_14_asm_start:"
"test r11d, 8\n"
"jz br_cond_func_0_block_9_rep_14_0\n"
"br_cond_func_0_block_9_rep_14_0:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"mul rbx\n"
"mov rax, rax\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_9_rep_14_1\n"
"br_cond_func_0_block_9_rep_14_1:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, rax\n"
"jmp func_0_block_9_rep_14_asm_end\n"
"func_0_block_9_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_14\n"
"dummy_call_func_0_block_9_rep_14:"
"ret\n"
"end_func_0_block_9_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 799 && (req_id & 1023) < 833 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_9_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 16256]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_9_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_9_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_9_rep_15_asm_start\n"
"br_uncond_func_0_block_9_rep_15_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_9_rep_15_1\n"
"br_cond_func_0_block_9_rep_15_1:"
"test r11d, 8\n"
"jz br_cond_func_0_block_9_rep_15_2\n"
"br_cond_func_0_block_9_rep_15_2:"
"jmp br_uncond_func_0_block_9_rep_15_1\n"
"func_0_block_9_rep_15_asm_start:"
"mov rax, rbx\n"
"add rbx, rax\n"
"sub rcx, rdx\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_9_rep_15_0\n"
"br_cond_func_0_block_9_rep_15_0:"
"jmp br_uncond_func_0_block_9_rep_15_0\n"
"br_uncond_func_0_block_9_rep_15_1:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_9_rep_15_asm_end\n"
"func_0_block_9_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_9_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_9_rep_15\n"
"dummy_call_func_0_block_9_rep_15:"
"ret\n"
"end_func_0_block_9_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[8]), "r" (curr_pointer_chasing_mem_addrs[8]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[8] = next_mem_addr;
curr_pointer_chasing_mem_addrs[8] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32576]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_0_asm_start\n"
"br_uncond_func_0_block_10_rep_0_1:"
"jmp func_0_block_10_rep_0_asm_end\n"
"func_0_block_10_rep_0_asm_start:"
"jmp br_uncond_func_0_block_10_rep_0_0\n"
"br_uncond_func_0_block_10_rep_0_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_10_rep_0_0\n"
"br_cond_func_0_block_10_rep_0_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"or rbx, rbx\n"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_10_rep_0_1\n"
"br_cond_func_0_block_10_rep_0_1:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_10_rep_0_2\n"
"br_cond_func_0_block_10_rep_0_2:"
"sub rax, QWORD PTR[r10 + 128]\n"
"or rax, QWORD PTR[r10 + 64]\n"
"and rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_10_rep_0_1\n"
"func_0_block_10_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_0\n"
"dummy_call_func_0_block_10_rep_0:"
"ret\n"
"end_func_0_block_10_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32576]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_1_asm_start\n"
"func_0_block_10_rep_1_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"and rcx, rcx\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 128], rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_10_rep_1_0\n"
"br_cond_func_0_block_10_rep_1_0:"
"test r11d, 16\n"
"jz br_cond_func_0_block_10_rep_1_1\n"
"br_cond_func_0_block_10_rep_1_1:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_10_rep_1_asm_end\n"
"func_0_block_10_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_1\n"
"dummy_call_func_0_block_10_rep_1:"
"ret\n"
"end_func_0_block_10_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32576]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_2_asm_start\n"
"br_uncond_func_0_block_10_rep_2_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_10_rep_2_asm_end\n"
"func_0_block_10_rep_2_asm_start:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_10_rep_2_0\n"
"br_cond_func_0_block_10_rep_2_0:"
"or rbx, rbx\n"
"add rbx, QWORD PTR[r10 + 128]\n"
"test r11d, 8388608\n"
"jz br_cond_func_0_block_10_rep_2_1\n"
"br_cond_func_0_block_10_rep_2_1:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_10_rep_2_2\n"
"br_cond_func_0_block_10_rep_2_2:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rbx\n"
"or rbx, rax\n"
"jmp br_uncond_func_0_block_10_rep_2_0\n"
"func_0_block_10_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_2\n"
"dummy_call_func_0_block_10_rep_2:"
"ret\n"
"end_func_0_block_10_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32576]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_3_asm_start\n"
"func_0_block_10_rep_3_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_10_rep_3_0\n"
"br_cond_func_0_block_10_rep_3_0:"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 128]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_10_rep_3_1\n"
"br_cond_func_0_block_10_rep_3_1:"
"test r11d, 8\n"
"jz br_cond_func_0_block_10_rep_3_2\n"
"br_cond_func_0_block_10_rep_3_2:"
"or rax, rax\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_10_rep_3\n"
"jmp func_0_block_10_rep_3_asm_end\n"
"func_0_block_10_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_3\n"
"dummy_call_func_0_block_10_rep_3:"
"ret\n"
"end_func_0_block_10_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32640]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_4_asm_start\n"
"br_uncond_func_0_block_10_rep_4_0:"
"add rax, QWORD PTR[r10 + 0]\n"
"mov rbx, rcx\n"
"jmp br_uncond_func_0_block_10_rep_4_1\n"
"func_0_block_10_rep_4_asm_start:"
"sub rcx, rcx\n"
"mov rcx, rdx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 262144\n"
"jz br_cond_func_0_block_10_rep_4_0\n"
"br_cond_func_0_block_10_rep_4_0:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_10_rep_4_0\n"
"br_uncond_func_0_block_10_rep_4_1:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_10_rep_4_1\n"
"br_cond_func_0_block_10_rep_4_1:"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_10_rep_4_2\n"
"br_cond_func_0_block_10_rep_4_2:"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_10_rep_4_3\n"
"br_cond_func_0_block_10_rep_4_3:"
"jmp func_0_block_10_rep_4_asm_end\n"
"func_0_block_10_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_4\n"
"dummy_call_func_0_block_10_rep_4:"
"ret\n"
"end_func_0_block_10_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32448]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_5_asm_start\n"
"br_uncond_func_0_block_10_rep_5_0:"
"jmp func_0_block_10_rep_5_asm_end\n"
"func_0_block_10_rep_5_asm_start:"
"test r11d, 262144\n"
"jz br_cond_func_0_block_10_rep_5_0\n"
"br_cond_func_0_block_10_rep_5_0:"
"mov rax, rax\n"
"mov QWORD PTR[r10 + 256], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rax\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 192]\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rcx, rbx\n"
"jmp br_uncond_func_0_block_10_rep_5_0\n"
"func_0_block_10_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_5\n"
"dummy_call_func_0_block_10_rep_5:"
"ret\n"
"end_func_0_block_10_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32576]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_6_asm_start\n"
"func_0_block_10_rep_6_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"and rax, rbx\n"
"mov rcx, rbx\n"
"mov rbx, rcx\n"
"or rdx, QWORD PTR[r10 + 64]\n"
"or rsi, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rsi, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 512\n"
"jz br_cond_func_0_block_10_rep_6_0\n"
"br_cond_func_0_block_10_rep_6_0:"
"mov QWORD PTR[r10 + 128], rdi\n"
"call dummy_call_func_0_block_10_rep_6\n"
"or r8, r8\n"
"jmp func_0_block_10_rep_6_asm_end\n"
"func_0_block_10_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_6\n"
"dummy_call_func_0_block_10_rep_6:"
"ret\n"
"end_func_0_block_10_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32384]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_7_asm_start\n"
"func_0_block_10_rep_7_asm_start:"
"mov QWORD PTR[r10 + 256], rax\n"
"call dummy_call_func_0_block_10_rep_7\n"
"imul QWORD PTR[r10 + 128]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, rbx\n"
"mov QWORD PTR[r10 + 0], rax\n"
"and rbx, QWORD PTR[r10 + 320]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rax, QWORD PTR[r10 + 192]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_10_rep_7_asm_end\n"
"func_0_block_10_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_7\n"
"dummy_call_func_0_block_10_rep_7:"
"ret\n"
"end_func_0_block_10_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32640]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_8_asm_start\n"
"br_uncond_func_0_block_10_rep_8_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_10_rep_8_3\n"
"br_cond_func_0_block_10_rep_8_3:"
"jmp func_0_block_10_rep_8_asm_end\n"
"func_0_block_10_rep_8_asm_start:"
"test r11d, 4\n"
"jz br_cond_func_0_block_10_rep_8_0\n"
"br_cond_func_0_block_10_rep_8_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_10_rep_8_1\n"
"br_cond_func_0_block_10_rep_8_1:"
"mov rax, rax\n"
"call dummy_call_func_0_block_10_rep_8\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_10_rep_8_2\n"
"br_cond_func_0_block_10_rep_8_2:"
"sub rax, rax\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rax, rax\n"
"jmp br_uncond_func_0_block_10_rep_8_0\n"
"func_0_block_10_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_8\n"
"dummy_call_func_0_block_10_rep_8:"
"ret\n"
"end_func_0_block_10_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32704]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_9_asm_start\n"
"br_uncond_func_0_block_10_rep_9_0:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 8\n"
"jz br_cond_func_0_block_10_rep_9_1\n"
"br_cond_func_0_block_10_rep_9_1:"
"mov rax, rax\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_10_rep_9_2\n"
"br_cond_func_0_block_10_rep_9_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_10_rep_9_asm_end\n"
"func_0_block_10_rep_9_asm_start:"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_10_rep_9_0\n"
"br_cond_func_0_block_10_rep_9_0:"
"jmp br_uncond_func_0_block_10_rep_9_0\n"
"func_0_block_10_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_9\n"
"dummy_call_func_0_block_10_rep_9:"
"ret\n"
"end_func_0_block_10_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32576]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_10_asm_start\n"
"br_uncond_func_0_block_10_rep_10_0:"
"sub rax, QWORD PTR[r10 + 0]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_10_rep_10_0\n"
"br_cond_func_0_block_10_rep_10_0:"
"test r11d, 256\n"
"jz br_cond_func_0_block_10_rep_10_1\n"
"br_cond_func_0_block_10_rep_10_1:"
"sub rax, QWORD PTR[r10 + 128]\n"
"call dummy_call_func_0_block_10_rep_10\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_10_rep_10_asm_end\n"
"func_0_block_10_rep_10_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"add rax, rax\n"
"mov rax, rax\n"
"sub rax, rbx\n"
"call dummy_call_func_0_block_10_rep_10\n"
"jmp br_uncond_func_0_block_10_rep_10_0\n"
"func_0_block_10_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_10\n"
"dummy_call_func_0_block_10_rep_10:"
"ret\n"
"end_func_0_block_10_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32640]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_11_asm_start\n"
"br_uncond_func_0_block_10_rep_11_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_10_rep_11_0\n"
"br_cond_func_0_block_10_rep_11_0:"
"or QWORD PTR[r10 + 0], rax\n"
"and rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_10_rep_11_1\n"
"func_0_block_10_rep_11_asm_start:"
"jmp br_uncond_func_0_block_10_rep_11_0\n"
"br_uncond_func_0_block_10_rep_11_1:"
"mov rbx, rax\n"
"add rax, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov rcx, rbx\n"
"call dummy_call_func_0_block_10_rep_11\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"jmp func_0_block_10_rep_11_asm_end\n"
"func_0_block_10_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_11\n"
"dummy_call_func_0_block_10_rep_11:"
"ret\n"
"end_func_0_block_10_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32384]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_12_asm_start\n"
"func_0_block_10_rep_12_asm_start:"
"add rax, QWORD PTR[r10 + 192]\n"
"mov rax, rbx\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 320], rbx\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"sub QWORD PTR[r10 + 0], rax\n"
"mov rcx, rcx\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_10_rep_12_0\n"
"br_cond_func_0_block_10_rep_12_0:"
"mov rdx, rax\n"
"mov QWORD PTR[r10 + 256], rbx\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_10_rep_12_1\n"
"br_cond_func_0_block_10_rep_12_1:"
"add rdx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_10_rep_12_2\n"
"br_cond_func_0_block_10_rep_12_2:"
"jmp func_0_block_10_rep_12_asm_end\n"
"func_0_block_10_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 384\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_12\n"
"dummy_call_func_0_block_10_rep_12:"
"ret\n"
"end_func_0_block_10_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32640]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_13_asm_start\n"
"func_0_block_10_rep_13_asm_start:"
"or rax, rbx\n"
"test r11d, 4194304\n"
"jz br_cond_func_0_block_10_rep_13_0\n"
"br_cond_func_0_block_10_rep_13_0:"
"test r11d, 134217728\n"
"jz br_cond_func_0_block_10_rep_13_1\n"
"br_cond_func_0_block_10_rep_13_1:"
"test r11d, 1024\n"
"jz br_cond_func_0_block_10_rep_13_2\n"
"br_cond_func_0_block_10_rep_13_2:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_10_rep_13_3\n"
"br_cond_func_0_block_10_rep_13_3:"
"or rax, QWORD PTR[r10 + 64]\n"
"mov rbx, rax\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_10_rep_13_4\n"
"br_cond_func_0_block_10_rep_13_4:"
"mov QWORD PTR[r10 + 0], rcx\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_10_rep_13_5\n"
"br_cond_func_0_block_10_rep_13_5:"
"jmp func_0_block_10_rep_13_asm_end\n"
"func_0_block_10_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_13\n"
"dummy_call_func_0_block_10_rep_13:"
"ret\n"
"end_func_0_block_10_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32512]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_14_asm_start\n"
"func_0_block_10_rep_14_asm_start:"
"mov QWORD PTR[r10 + 128], rax\n"
"test r11d, 1\n"
"jz br_cond_func_0_block_10_rep_14_0\n"
"br_cond_func_0_block_10_rep_14_0:"
"jmp br_uncond_func_0_block_10_rep_14_0\n"
"br_uncond_func_0_block_10_rep_14_0:"
"mov QWORD PTR[r10 + 192], rax\n"
"or rax, rbx\n"
"test r11d, 32\n"
"jz br_cond_func_0_block_10_rep_14_1\n"
"br_cond_func_0_block_10_rep_14_1:"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_10_rep_14_2\n"
"br_cond_func_0_block_10_rep_14_2:"
"test r11d, 512\n"
"jz br_cond_func_0_block_10_rep_14_3\n"
"br_cond_func_0_block_10_rep_14_3:"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov QWORD PTR[r10 + 0], rcx\n"
"jmp func_0_block_10_rep_14_asm_end\n"
"func_0_block_10_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_14\n"
"dummy_call_func_0_block_10_rep_14:"
"ret\n"
"end_func_0_block_10_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 833 && (req_id & 1023) < 871 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_10_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 32448]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_10_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_10_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_10_rep_15_asm_start\n"
"func_0_block_10_rep_15_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 256]\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 192], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rax\n"
"add rax, rbx\n"
"mov QWORD PTR[r10 + 128], rcx\n"
"add rdx, QWORD PTR[r10 + 0]\n"
"mov rbx, rsi\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_10_rep_15_asm_end\n"
"func_0_block_10_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 320\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_10_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_10_rep_15\n"
"dummy_call_func_0_block_10_rep_15:"
"ret\n"
"end_func_0_block_10_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[9]), "r" (curr_pointer_chasing_mem_addrs[9]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[9] = next_mem_addr;
curr_pointer_chasing_mem_addrs[9] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 0) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_0_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 64960]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_0\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_0_asm_start\n"
"func_0_block_11_rep_0_asm_start:"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 512], rbx\n"
"mov QWORD PTR[r10 + 384], rbx\n"
"add rax, QWORD PTR[r10 + 128]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_11_rep_0_0\n"
"br_cond_func_0_block_11_rep_0_0:"
"sub rax, QWORD PTR[r10 + 0]\n"
"call dummy_call_func_0_block_11_rep_0\n"
"sub rcx, QWORD PTR[r10 + 256]\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 320], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov QWORD PTR[r10 + 448], rax\n"
"jmp func_0_block_11_rep_0_asm_end\n"
"func_0_block_11_rep_0_asm_end:"

);__asm__ __volatile__ (
"add r10, 576\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_0_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_0\n"
"dummy_call_func_0_block_11_rep_0:"
"ret\n"
"end_func_0_block_11_rep_0:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 1) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_1_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65280]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_1\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_1_asm_start\n"
"func_0_block_11_rep_1_asm_start:"
"test r11d, 2048\n"
"jz br_cond_func_0_block_11_rep_1_0\n"
"br_cond_func_0_block_11_rep_1_0:"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_11_rep_1_1\n"
"br_cond_func_0_block_11_rep_1_1:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, rbx\n"
"and rax, QWORD PTR[r10 + 192]\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_11_rep_1_2\n"
"br_cond_func_0_block_11_rep_1_2:"
"jmp br_uncond_func_0_block_11_rep_1_0\n"
"br_uncond_func_0_block_11_rep_1_0:"
"or rax, QWORD PTR[r10 + 0]\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_11_rep_1_3\n"
"br_cond_func_0_block_11_rep_1_3:"
"jmp func_0_block_11_rep_1_asm_end\n"
"func_0_block_11_rep_1_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_1_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_1\n"
"dummy_call_func_0_block_11_rep_1:"
"ret\n"
"end_func_0_block_11_rep_1:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 2) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_2_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65408]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_2\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_2_asm_start\n"
"func_0_block_11_rep_2_asm_start:"
"test r11d, 524288\n"
"jz br_cond_func_0_block_11_rep_2_0\n"
"br_cond_func_0_block_11_rep_2_0:"
"test r11d, 16\n"
"jz br_cond_func_0_block_11_rep_2_1\n"
"br_cond_func_0_block_11_rep_2_1:"
"mov rax, rbx\n"
"test r11d, 256\n"
"jz br_cond_func_0_block_11_rep_2_2\n"
"br_cond_func_0_block_11_rep_2_2:"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"test r11d, 67108864\n"
"jz br_cond_func_0_block_11_rep_2_3\n"
"br_cond_func_0_block_11_rep_2_3:"
"test r11d, 32768\n"
"jz br_cond_func_0_block_11_rep_2_4\n"
"br_cond_func_0_block_11_rep_2_4:"
"jmp func_0_block_11_rep_2_asm_end\n"
"func_0_block_11_rep_2_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_2_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_2\n"
"dummy_call_func_0_block_11_rep_2:"
"ret\n"
"end_func_0_block_11_rep_2:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 3) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_3_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65280]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_3\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_3_asm_start\n"
"func_0_block_11_rep_3_asm_start:"
"mov QWORD PTR[r10 + 192], rax\n"
"mov rbx, rax\n"
"mov QWORD PTR[r10 + 128], rbx\n"
"mov rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_11_rep_3_0\n"
"br_cond_func_0_block_11_rep_3_0:"
"mov QWORD PTR[r10 + 64], rbx\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"jmp func_0_block_11_rep_3_asm_end\n"
"func_0_block_11_rep_3_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_3_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_3\n"
"dummy_call_func_0_block_11_rep_3:"
"ret\n"
"end_func_0_block_11_rep_3:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 4) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_4_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65344]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_4\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_4_asm_start\n"
"func_0_block_11_rep_4_asm_start:"
"mov QWORD PTR[r10 + 128], rax\n"
"mov rbx, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"and rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_11_rep_4\n"
"and rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 4096\n"
"jz br_cond_func_0_block_11_rep_4_0\n"
"br_cond_func_0_block_11_rep_4_0:"
"or rbx, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 1024\n"
"jz br_cond_func_0_block_11_rep_4_1\n"
"br_cond_func_0_block_11_rep_4_1:"
"jmp func_0_block_11_rep_4_asm_end\n"
"func_0_block_11_rep_4_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_4_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_4\n"
"dummy_call_func_0_block_11_rep_4:"
"ret\n"
"end_func_0_block_11_rep_4:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 5) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_5_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65472]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_5\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_5_asm_start\n"
"func_0_block_11_rep_5_asm_start:"
"mov rax, rax\n"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_11_rep_5_0\n"
"br_cond_func_0_block_11_rep_5_0:"
"test r11d, 2147483648\n"
"jz br_cond_func_0_block_11_rep_5_1\n"
"br_cond_func_0_block_11_rep_5_1:"
"or rbx, rcx\n"
"test r11d, 4\n"
"jz br_cond_func_0_block_11_rep_5_2\n"
"br_cond_func_0_block_11_rep_5_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rcx\n"
"call dummy_call_func_0_block_11_rep_5\n"
"add rcx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"test r11d, 8192\n"
"jz br_cond_func_0_block_11_rep_5_3\n"
"br_cond_func_0_block_11_rep_5_3:"
"jmp func_0_block_11_rep_5_asm_end\n"
"func_0_block_11_rep_5_asm_end:"

);__asm__ __volatile__ (
"add r10, 64\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_5_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_5\n"
"dummy_call_func_0_block_11_rep_5:"
"ret\n"
"end_func_0_block_11_rep_5:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 6) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_6_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65280]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_6\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_6_asm_start\n"
"func_0_block_11_rep_6_asm_start:"
"and rax, QWORD PTR[r10 + 128]\n"
"sub rbx, QWORD PTR[r10 + 0]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rdx\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_11_rep_6_0\n"
"br_cond_func_0_block_11_rep_6_0:"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"mov rcx, rdx\n"
"mov rsi, rcx\n"
"mov QWORD PTR[r10 + 192], rbx\n"
"mov r13, QWORD PTR[r13]\n"
"mov rcx, rsi\n"
"mov rcx, rdx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_11_rep_6_1\n"
"br_cond_func_0_block_11_rep_6_1:"
"jmp func_0_block_11_rep_6_asm_end\n"
"func_0_block_11_rep_6_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_6_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_6\n"
"dummy_call_func_0_block_11_rep_6:"
"ret\n"
"end_func_0_block_11_rep_6:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 7) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_7_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65408]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_7\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_7_asm_start\n"
"func_0_block_11_rep_7_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rax\n"
"mov rbx, rcx\n"
"mov rax, rbx\n"
"test r11d, 268435456\n"
"jz br_cond_func_0_block_11_rep_7_0\n"
"br_cond_func_0_block_11_rep_7_0:"
"mov r13, QWORD PTR[r13]\n"
"jmp br_uncond_func_0_block_11_rep_7_0\n"
"br_uncond_func_0_block_11_rep_7_0:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_11_rep_7_1\n"
"br_cond_func_0_block_11_rep_7_1:"
"sub rcx, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"add rcx, rax\n"
"mov QWORD PTR[r10 + 0], rax\n"
"jmp func_0_block_11_rep_7_asm_end\n"
"func_0_block_11_rep_7_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_7_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_7\n"
"dummy_call_func_0_block_11_rep_7:"
"ret\n"
"end_func_0_block_11_rep_7:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 8) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_8_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65408]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_8\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_8_asm_start\n"
"func_0_block_11_rep_8_asm_start:"
"jmp br_uncond_func_0_block_11_rep_8_0\n"
"br_uncond_func_0_block_11_rep_8_0:"
"mov rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 64]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"call dummy_call_func_0_block_11_rep_8\n"
"or rax, QWORD PTR[r10 + 0]\n"
"mov rbx, rcx\n"
"mov r13, QWORD PTR[r13]\n"
"add rbx, rcx\n"
"test r11d, 524288\n"
"jz br_cond_func_0_block_11_rep_8_0\n"
"br_cond_func_0_block_11_rep_8_0:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_11_rep_8_1\n"
"br_cond_func_0_block_11_rep_8_1:"
"jmp func_0_block_11_rep_8_asm_end\n"
"func_0_block_11_rep_8_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_8_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_8\n"
"dummy_call_func_0_block_11_rep_8:"
"ret\n"
"end_func_0_block_11_rep_8:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 9) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_9_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65408]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_9\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_9_asm_start\n"
"func_0_block_11_rep_9_asm_start:"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 16777216\n"
"jz br_cond_func_0_block_11_rep_9_0\n"
"br_cond_func_0_block_11_rep_9_0:"
"jmp br_uncond_func_0_block_11_rep_9_0\n"
"br_uncond_func_0_block_11_rep_9_0:"
"test r11d, 33554432\n"
"jz br_cond_func_0_block_11_rep_9_1\n"
"br_cond_func_0_block_11_rep_9_1:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 131072\n"
"jz br_cond_func_0_block_11_rep_9_2\n"
"br_cond_func_0_block_11_rep_9_2:"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rbx, rax\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_11_rep_9_3\n"
"br_cond_func_0_block_11_rep_9_3:"
"jmp func_0_block_11_rep_9_asm_end\n"
"func_0_block_11_rep_9_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_9_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_9\n"
"dummy_call_func_0_block_11_rep_9:"
"ret\n"
"end_func_0_block_11_rep_9:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 10) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_10_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65088]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_10\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_10_asm_start\n"
"func_0_block_11_rep_10_asm_start:"
"test r11d, 1073741824\n"
"jz br_cond_func_0_block_11_rep_10_0\n"
"br_cond_func_0_block_11_rep_10_0:"
"mov QWORD PTR[r10 + 128], rax\n"
"or rbx, QWORD PTR[r10 + 192]\n"
"mov rbx, rbx\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 64], rcx\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 320], rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 384], rax\n"
"and rax, QWORD PTR[r10 + 0]\n"
"mov QWORD PTR[r10 + 256], rax\n"
"mov rax, rcx\n"
"mov rdx, rbx\n"
"jmp func_0_block_11_rep_10_asm_end\n"
"func_0_block_11_rep_10_asm_end:"

);__asm__ __volatile__ (
"add r10, 448\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_10_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_10\n"
"dummy_call_func_0_block_11_rep_10:"
"ret\n"
"end_func_0_block_11_rep_10:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 11) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_11_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65280]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_11\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_11_asm_start\n"
"func_0_block_11_rep_11_asm_start:"
"add rax, QWORD PTR[r10 + 192]\n"
"jmp br_uncond_func_0_block_11_rep_11_0\n"
"br_uncond_func_0_block_11_rep_11_0:"
"mov QWORD PTR[r10 + 0], rax\n"
"mov rax, rbx\n"
"mov QWORD PTR[r10 + 64], rbx\n"
"mov rbx, rcx\n"
"or rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov r13, QWORD PTR[r13]\n"
"or rdx, QWORD PTR[r10 + 128]\n"
"test r11d, 16384\n"
"jz br_cond_func_0_block_11_rep_11_0\n"
"br_cond_func_0_block_11_rep_11_0:"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_11_rep_11_1\n"
"br_cond_func_0_block_11_rep_11_1:"
"jmp func_0_block_11_rep_11_asm_end\n"
"func_0_block_11_rep_11_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_11_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_11\n"
"dummy_call_func_0_block_11_rep_11:"
"ret\n"
"end_func_0_block_11_rep_11:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 12) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_12_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65280]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_12\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_12_asm_start\n"
"func_0_block_11_rep_12_asm_start:"
"test r11d, 65536\n"
"jz br_cond_func_0_block_11_rep_12_0\n"
"br_cond_func_0_block_11_rep_12_0:"
"mov r13, QWORD PTR[r13]\n"
"sub rax, QWORD PTR[r10 + 128]\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_11_rep_12_1\n"
"br_cond_func_0_block_11_rep_12_1:"
"or rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"mov rax, rbx\n"
"sub rax, rbx\n"
"mov QWORD PTR[r10 + 64], rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 0]\n"
"or rax, QWORD PTR[r10 + 192]\n"
"and rbx, rax\n"
"test r11d, 2\n"
"jz br_cond_func_0_block_11_rep_12_2\n"
"br_cond_func_0_block_11_rep_12_2:"
"jmp func_0_block_11_rep_12_asm_end\n"
"func_0_block_11_rep_12_asm_end:"

);__asm__ __volatile__ (
"add r10, 256\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_12_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_12\n"
"dummy_call_func_0_block_11_rep_12:"
"ret\n"
"end_func_0_block_11_rep_12:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 13) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_13_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65088]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_13\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_13_asm_start\n"
"br_uncond_func_0_block_11_rep_13_0:"
"mov rax, rax\n"
"add rbx, rax\n"
"mov r13, QWORD PTR[r13]\n"
"or rcx, QWORD PTR[r10 + 320]\n"
"mov r13, QWORD PTR[r13]\n"
"sub rcx, rdx\n"
"mov QWORD PTR[r10 + 256], rcx\n"
"sub rcx, QWORD PTR[r10 + 64]\n"
"jmp func_0_block_11_rep_13_asm_end\n"
"func_0_block_11_rep_13_asm_start:"
"mov QWORD PTR[r10 + 192], rcx\n"
"mov QWORD PTR[r10 + 384], rdx\n"
"test r11d, 65536\n"
"jz br_cond_func_0_block_11_rep_13_0\n"
"br_cond_func_0_block_11_rep_13_0:"
"mov r13, QWORD PTR[r13]\n"
"mov QWORD PTR[r10 + 0], rdx\n"
"sub QWORD PTR[r10 + 128], rbx\n"
"jmp br_uncond_func_0_block_11_rep_13_0\n"
"func_0_block_11_rep_13_asm_end:"

);__asm__ __volatile__ (
"add r10, 448\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_13_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_13\n"
"dummy_call_func_0_block_11_rep_13:"
"ret\n"
"end_func_0_block_11_rep_13:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 14) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_14_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65344]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_14\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_14_asm_start\n"
"func_0_block_11_rep_14_asm_start:"
"mov r13, QWORD PTR[r13]\n"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_11_rep_14_0\n"
"br_cond_func_0_block_11_rep_14_0:"
"mov rax, rax\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_11_rep_14_1\n"
"br_cond_func_0_block_11_rep_14_1:"
"or rbx, QWORD PTR[r10 + 64]\n"
"jmp br_uncond_func_0_block_11_rep_14_0\n"
"br_uncond_func_0_block_11_rep_14_1:"
"test r11d, 536870912\n"
"jz br_cond_func_0_block_11_rep_14_3\n"
"br_cond_func_0_block_11_rep_14_3:"
"movsd xmm0, QWORD PTR[r10 + 128]\n"
"jmp func_0_block_11_rep_14_asm_end\n"
"br_uncond_func_0_block_11_rep_14_0:"
"and rcx, QWORD PTR[r10 + 0]\n"
"add rbx, rax\n"
"test r11d, 1048576\n"
"jz br_cond_func_0_block_11_rep_14_2\n"
"br_cond_func_0_block_11_rep_14_2:"
"jmp br_uncond_func_0_block_11_rep_14_1\n"
"func_0_block_11_rep_14_asm_end:"

);__asm__ __volatile__ (
"add r10, 192\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_14_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_14\n"
"dummy_call_func_0_block_11_rep_14:"
"ret\n"
"end_func_0_block_11_rep_14:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

if ((req_id & 1023) >= 871 && (req_id & 1023) < 1024 && (req_id % 16) == 15) {
__asm__ __volatile__ (
"mov r11, %5\n"
"mov r10, %3\n"
"mov r13, %4\n"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"rdtsc\n"
"mov r12, rax\n"
);
__asm__ __volatile__ (
"func_0_block_11_rep_15_loop_start:"
"lea r8, QWORD PTR[%2]\n"
"lea r9, QWORD PTR[%2 + 65408]\n"
"add r11, 1\n"
"mov rax, 1103515245\n"
"mul r12\n"
"mov r12, rax\n"
"add r12, 12345\n"
"cmp r10, r9\n"
"jle bypass_reset_func_0_block_11_rep_15\n"
"mov r10, r8\n"
"bypass_reset_func_0_block_11_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
__asm__ __volatile__ (
"jmp func_0_block_11_rep_15_asm_start\n"
"func_0_block_11_rep_15_asm_start:"
"call dummy_call_func_0_block_11_rep_15\n"
"test r11d, 2097152\n"
"jz br_cond_func_0_block_11_rep_15_0\n"
"br_cond_func_0_block_11_rep_15_0:"
"add rax, rbx\n"
"mov r13, QWORD PTR[r13]\n"
"and rax, rax\n"
"mov r13, QWORD PTR[r13]\n"
"sub rbx, rax\n"
"test r11d, 128\n"
"jz br_cond_func_0_block_11_rep_15_1\n"
"br_cond_func_0_block_11_rep_15_1:"
"mov r13, QWORD PTR[r13]\n"
"or rbx, QWORD PTR[r10 + 64]\n"
"test r11d, 64\n"
"jz br_cond_func_0_block_11_rep_15_2\n"
"br_cond_func_0_block_11_rep_15_2:"
"mov rbx, rbx\n"
"add rbx, QWORD PTR[r10 + 0]\n"
"jmp func_0_block_11_rep_15_asm_end\n"
"func_0_block_11_rep_15_asm_end:"

);__asm__ __volatile__ (
"add r10, 128\n"
"mov rdi, %5\n"
"add rdi, 438\n"
"cmp r11, rdi\n"
"jl func_0_block_11_rep_15_loop_start\n"
"mov %0, r10\n"
"mov %1, r13\n"
"jmp end_func_0_block_11_rep_15\n"
"dummy_call_func_0_block_11_rep_15:"
"ret\n"
"end_func_0_block_11_rep_15:"
:"=r" (next_mem_addr), "=r" (next_pointer_chasing_mem_addr)
:"r" (mem_data), "r" (curr_mem_addrs[10]), "r" (curr_pointer_chasing_mem_addrs[10]), "r" (req_id)
:"cc", "r8", "r9", "r10", "r11", "r12"
);
curr_mem_addrs[10] = next_mem_addr;
curr_pointer_chasing_mem_addrs[10] = next_pointer_chasing_mem_addr;
}

}
