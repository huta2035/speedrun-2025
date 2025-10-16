#!/usr/bin/python3

from pwn import *
import re

REMOTE = False

context.log_level = 'debug'

def get_remote():
    return remote('localhost', 1337) if REMOTE else process(['python3', 'do-not-open/server.py'])

def compute_serial(username: bytes) -> str:
    # You only need to implement this function !
    # Serial format: (^[0-9A-F]{8}-[0-9A-F]{8}-[0-9A-F]{8}-[0-9A-F]{8}$)

    serial = '???'

    return serial

if __name__ == '__main__':
    r = get_remote()

    for i in range(5):
        username = re.search(r'username\s+"([^"]+)"', r.recv().decode()).group(1)
        serial = compute_serial(username.encode())

        if re.match(r'^[0-9A-F]{8}-[0-9A-F]{8}-[0-9A-F]{8}-[0-9A-F]{8}$', serial) is None:
            log.warn(f'Computed serial \"{serial}\" does not match the format')

        r.sendline(serial)
        if r.recvline() != b'Correct !\n':
            log.error(f'{username} => {serial} KO')
            exit()
        else:
            log.success(f'{username} => {serial} OK')

    r.interactive()

