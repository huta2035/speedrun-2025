#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define PROT_RWX (PROT_READ | PROT_WRITE | PROT_EXEC)
#define SHELLCODE_MAX 0x40

static void *sc;

static void __attribute__((constructor)) setup()
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    if ((sc = mmap(NULL, 0x1000, PROT_RWX, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
        perror("mmap");
        exit(-1);
    }
}

int main(int argc, char *argv[])
{
    printf("-= ~ 1337 Shellcode Loader ~ =-\n");
    printf("Please enter your shellcode (64 bytes max): ");

    read(0, sc, SHELLCODE_MAX);

    memset(sc + 0x10, 0xff, 0x10);

    printf("[!] It seems that your shellcode has been corrupted...\n");
    printf("[*] Executing...");
    
    ((void (*)(void))sc)();

    printf("[+] Done !\n");

    return 0;
}
