#!/usr/bin/python3

from random import choice

CHARSET = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!?_$()[]{}'

def gen_random(n):
    return ''.join(choice(CHARSET) for _ in range(n))

with open('flag.txt', 'r') as f:
    flag = f.read().splitlines()[0]

enc_flag = ''

for i in range(len(flag)):
    enc_flag += flag[i]
    enc_flag += gen_random(len(flag) - i)

with open('flag.h', 'w') as f:
    f.write(f'#define FLAG \"{enc_flag}\"\n')
    f.write(f'#define FLAG_LENGTH {len(flag)}')

