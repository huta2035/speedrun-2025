The goal of the challenge is to recover the function that computes a serial.

The serial is computed as follows:

```python
def compute_serial(username: bytes) -> str:
    h = hashlib.md5(username[::-1]).digest()
    h = [f'{u32(h[i:i+4]):08X}' for i in range(0, len(h), 4)]
    return f'{h[0]}-{h[2]}-{h[1]}-{h[3]}'
```

A remote service is available to test 5 serials for random usernames.
For solving, the provided template contains a `compute_serial` function that must be implemented.
