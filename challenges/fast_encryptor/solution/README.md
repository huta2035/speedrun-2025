The goal of the challenge is to reconstruct an image encrypted by a binary.  
It is a simple XOR with a 4-byte integer value obtained via `rand()`. A random seed is set at program startup (sourced from `/dev/urandom`).  
You can see the extension of the encrypted file (`.png`).  
This is therefore a known-plaintext attack, since the PNG magic bytes are known.

```python
def decrypt_flag(flag: bytes) -> bytes:
    key = xor(flag[:4], b'\x89PNG')
    return xor(key, flag)
```
