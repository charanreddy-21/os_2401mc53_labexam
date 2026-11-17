# 2401MC53_Sri_Charan_LABEXAM

Name: K. Sri Charan Reddy.
Roll: 2401MC53.
SLOT: 2 (4PM - 6PM)





# Question 1: Page Protection

Implemented page protection using `mprotect()` and `munprotect()`.

### Implementation

1. Added `SYS_mprotect` and `SYS_munprotect` system call numbers (22 and 23) in `syscall.h`.
2. Added `sys_mprotect()` and `sys_munprotect()` to `syscall.c` and connected them to their respective system calls.
3. Implemented the `mprotect()` and `munprotect()` functions in `vm.c`. Also added the required helper function declaration in `defs.h`.
4. Added the system call declarations in `user.h` and their corresponding entries in `usys.S`.
5. Created `prottest.c` to test page protection. The program allocates one aligned page of memory using `sbrk(4096)` and checks whether the protection functions work correctly.

# Question 2: Priority Scheduling

Implemented priority-based CPU scheduling.

### Implementation

1. Added a `priority` variable to the process structure in `proc.h`.
2. Initialized the priority-related variables in `allocproc()` in `proc.c`.
3. Modified the `scheduler()` function in `proc.c` to select processes based on their priority.
4. Added `SYS_set_priority` (24) in `syscall.h`.
5. Registered `sys_set_priority()` in `syscall.c` and connected it to the system call.
6. Added the `set_priority(int, int)` declaration in `user.h` and its corresponding system call entry in `usys.S`.
7. Created `schedtest.c` to test priority scheduling and change process priorities directly from user space.
