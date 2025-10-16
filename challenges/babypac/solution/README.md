The challenge is an introduction to PAC. The goal is to call the `win` function with a controlled parameter while validating the authentication of the different pointers.  

A menu allows the player to:
- forge a code pointer (via `PACIA` and an arbitrary *diversifier*)
- forge a data pointer (via `PACDA` and an arbitrary *diversifier*)
- execute a code pointer (arbitrary)

Pointer authentication is performed at execution time:
- On the function pointer &rarr; `BLRAAZ`
- On the data pointer passed as a parameter &rarr; `AUTDA` with the address of `main` as the *diversifier*

Simplified solution:
```python
    forge_data_ptr(leak - win_offset + elf.sym['main'])
    execute(forge_code_ptr(leak, 0))
```
