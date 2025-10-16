#!/usr/bin/python3

from pwn import *

elf = ELF('./rubbish')

if __name__ == '__main__':
    r = elf.process()

    flag_len = 0x24    
    enc_flag = elf.read(elf.sym['enc_flag'], 0x400).split(b'\x00')[0]

    # TODO: Solve !
    flag = b'HXN{???}'

    r.sendlineafter(b': ', flag)

    r.interactive()
