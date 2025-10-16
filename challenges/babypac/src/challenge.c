#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 0x20

static void __attribute__((constructor)) setup()
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

static void win(char *cmd)
{
    if ((uint64_t) cmd & 0xffff000000000000) {
        printf("Invalid parameter PAC !\n");
        exit(1);
    }
    
    printf("Congratulations !\n");
    system(cmd);
}

static uint64_t read_long(char *prompt)
{
    char buf[BUFFER_SIZE];

    printf("%s", prompt);
    fgets(buf, sizeof buf, stdin);
    return strtoull(buf, NULL, 0);
}

static int menu(void)
{
    printf("1. Forge code pointer\n");
    printf("2. Forge data pointer\n");
    printf("3. Execute !\n");
    printf("0. Exit\n");

    return read_long("> ");
}

int main(int argc, char * argv[])
{
    printf("Welcome to babyPAC !\n");
    printf("Here is a little present: %p\n", win);
    
    printf("Input some data: ");
    char *data = calloc(BUFFER_SIZE, sizeof *data);
    fgets(data, BUFFER_SIZE, stdin);
    data[strcspn(data, "\n")] = 0;

    for (;;) {
        void (*fptr)(void*) = NULL;
        char *data_ptr = data;
        void *diversifier = NULL;

        switch(menu()) {
            case 1:
                fptr = (void*) read_long("Pointer ? ");
                diversifier = (void*) read_long("Diversifier ? ");

                asm volatile(
                    "pacia %0, %1"
                    : "+r"(fptr) 
                    : "r"(diversifier)
                );

                printf("Authenticated pointer: %p\n", fptr);
            break;
            case 2:
                diversifier = (void*) read_long("Diversifier ? ");
                asm volatile(
                    "pacda %0, %1"
                    : "+r"(data_ptr) 
                    : "r"(diversifier)
                );

                printf("Authenticated pointer: %p\n", data_ptr);
            break;
            case 3:
                fptr = (void*) read_long("Address to execute ? ");
                data_ptr = (void *) read_long("Argument ? ");

                asm volatile (
                    "autda %0, %1\n"
                    "blraaz %2"
                    : "+r"(data_ptr) : "r"(main), "r"(fptr)
                );
            case 0:
                return 0;
            break;
            default:
                printf("Unknown choice, try again.\n");
            break;
        }
    }
}
