#!/usr/bin/python3

from pwn import *

def decrypt_flag(flag: bytes) -> bytes:
    # TODO: Implement this function
    return b'???'

if __name__ == '__main__':
    with open('flag.png.enc', 'rb') as f:
        enc_flag = f.read()

    with open('flag.png', 'wb') as f:
        f.write(decrypt_flag(enc_flag))
