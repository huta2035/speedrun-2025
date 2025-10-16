The goal of the challenge is to exploit a buffer overflow in `.bss` by overwriting a `std::vector<char *>` object. To obtain the flag, the player must change the global variable `bool vip` to `true`. If so, the flag will be printed at the end of the program. The solution is to overwrite the vector's different fields:

```c
struct std::vector<char *> {
    char **begin;
    char **end;
    char **end_of_storage;
};
```

By overwriting `begin` and `end` with the address of `vip`, you can then overwrite `vip` with a non-zero value (`true`). Be careful to overwrite the `end_of_storage` field with an address further in memory to avoid triggering a vector reallocation.
