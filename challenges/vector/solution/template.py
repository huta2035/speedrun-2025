#!/usr/bin/python3

from pwn import *

elf = ELF('./vector')

REMOTE = False

context.arch = 'amd64'

def get_remote():
    return remote('localhost', 1337) if REMOTE else elf.process()

if __name__ == '__main__':
    r = get_remote()

    # TODO: Exploit !

    r.sendlineafter(b'> ', b'wine')
    r.sendlineafter(b'> ', b'baguette')
    r.sendlineafter(b'> ', b'fromage')

    r.sendlineafter(b'> ', b'voila')

    r.interactive()
