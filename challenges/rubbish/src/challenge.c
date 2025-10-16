#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "flag.h"

#define BUFFER_SIZE 0x100

static const char enc_flag[] = FLAG;
static const size_t flag_len = FLAG_LENGTH;

static void __attribute__((constructor)) setup(void)
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

bool check_flag(char *input)
{
    const char *flag_ptr = enc_flag;

    if (strlen(input) != FLAG_LENGTH) {
        return false;
    }

    if (strncmp(input, "HXN{", 4) != 0 || input[FLAG_LENGTH - 1] != '}') {
        return false;
    }

    for (int i = 0; i < flag_len; i++) {
        if (*flag_ptr != input[i]) {
            return false;
        }

        flag_ptr += flag_len - i + 1;
    }

    return true;
}

int main(int argc, char * argv[])
{
    char input[BUFFER_SIZE];

    printf("Enter the flag: ");
    if (fgets(input, sizeof input, stdin) == NULL) {
        perror("fgets");
        return -1;
    }
    input[strcspn(input, "\n")] = 0;

    if (!check_flag(input)) {
        printf("Wrong !\n");
        return 1;
    }

    printf("Correct, GG ! %s\n", input);

    return 0;
}
