#!/usr/bin/python3

import random
import hashlib
import struct

CHARSET = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'
CORRECT_COUNT = 5

def generate_username() -> str:
    name_len = random.randint(4, 12)
    return ''.join(random.choice(CHARSET) for _ in range(name_len))

def compute_serial(username: bytes) -> bytes:
    h = hashlib.md5(username[::-1]).digest()
    h = [f'{struct.unpack("<I", h[i:i+4])[0]:08X}' for i in range(0, len(h), 4)]
    return f'{h[0]}-{h[2]}-{h[1]}-{h[3]}'

if __name__ == '__main__':
    
    for i in range(CORRECT_COUNT):
        username = generate_username()
        user_serial = input(f'Serial for username "{username}" ? ')

        if compute_serial(username.encode()) != user_serial:
            print("Incorrect serial !")
            exit()
        
        print("Correct !")

    print('Congratulations, here is your flag:')

    with open('flag.txt', 'r') as f:
        print(f.read())
        