#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

static void init_rand(void)
{
    int seed = 0;

    FILE *fp = fopen("/dev/urandom", "rb");
    fread(&seed, sizeof seed, 1, fp);
    fclose(fp);

    srand(seed);
}

static size_t read_file(char *filename, char **content)
{
    *content = NULL;

    FILE *fp = NULL;
    if ((fp = fopen(filename, "rb")) == NULL) {
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = (ftell(fp) + 3) & ~4;
    fseek(fp, 0, SEEK_SET);

    char *buf = malloc(file_size);
    fread(buf, file_size, sizeof *buf, fp);
    fclose(fp);

    *content = buf;
    return file_size;
}

static void encrypt_file(uint32_t *content, size_t size)
{
    int n = rand();
    for (size_t i = 0; i < size / sizeof (uint32_t); i++) {
        content[i] ^= n;
    }
}

int main(int argc, char * argv[])
{
    init_rand();

    char *flag_content = NULL;
    size_t flag_len = 0;
    
    if ((flag_len = read_file("flag.png", &flag_content)) == 0) {
        return 1;
    }

    encrypt_file((uint32_t*) flag_content, flag_len);

    FILE *fp = fopen("flag.png.enc", "wb");
    fwrite(flag_content, flag_len, 1, fp);
    fclose(fp);
    free(flag_content);

    unlink("flag.png");

    return 0;
}
