#!/usr/bin/python3

from pwn import *

elf = ELF('./corrupted')

REMOTE = False

context.arch = 'amd64'

def get_remote():
    return remote('localhost', 1337) if REMOTE else elf.process()

if __name__ == '__main__':
    r = get_remote()

    # TODO: Exploit !

    sc = asm("""
       ret 
    """)

    # For debugging purpose...
    # print(disasm(sc))

    # gdb.attach(r, gdbscript='b *main+150\nc')
    # pause()

    r.sendafter(b': ', sc)

    r.interactive()
