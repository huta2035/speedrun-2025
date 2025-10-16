#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

#include "md5.h"


static void foo(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // swap characters
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

// static void print_hash(char *hash)
// {
//     printf("Hash: ");
//     for (int i = 0; i < 16; i++) {
//         printf("%02hhX", hash[i]);
//     }
//     printf("\n");
// }

static bool check_serial(char *username, char *serial)
{
    char *rev_username = malloc(strlen(username) + 1);
    strcpy(rev_username, username);

    foo(rev_username);
 
    MD5Context ctx;
    md5Init(&ctx);
    md5Update(&ctx, (uint8_t *)rev_username, strlen(rev_username));
    md5Finalize(&ctx);

    uint32_t serial_arr[4];
    if (sscanf(serial, "%08X-%08X-%08X-%08X", 
        &serial_arr[0],
        &serial_arr[2],
        &serial_arr[1],
        &serial_arr[3]
    ) != 4) {
        printf("Malformed serial.\n");
        return false;
    }

    // print_hash(ctx.digest);
    // print_hash((char *)serial_arr);

    if (memcmp(ctx.digest, serial_arr, sizeof ctx.digest)) {
        return false;
    }

    return true;
}

int main(int argc, char * argv[])
{
    char *username = "hexacon";
    if (argc >= 2) {
        username = argv[1];
    }

    printf("Yet another keygen !\n");
    printf("Serial for username \"%s\" ?\n", username);


    char *serial = NULL;
    size_t serial_len = 0;
    getline(&serial, &serial_len, stdin);

    if (!check_serial(username, serial)) {
        printf("Invalid !\n");
        return 1;
    }

    printf("Valid !\n");

    return 0;
}
