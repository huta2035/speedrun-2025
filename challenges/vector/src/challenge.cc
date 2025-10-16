#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define FLAG_SIZE 0x20
#define BUFFER_SIZE 0x20
#define TERMINATOR "voila"
#define PLACEHOLDER_FLAG "HXN{placeholder_flag}"

static char flag[FLAG_SIZE];
static bool vip = false;

static void read_flag(void)
{
    FILE *fp = NULL;
    if ((fp = fopen("flag.txt", "rb")) == NULL) {
        strcpy(flag, PLACEHOLDER_FLAG);
        return;
    }
        
    fgets(flag, sizeof flag, fp);
    fclose(fp);
}

static void __attribute__((constructor)) setup(void)
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    read_flag();
}

static const char * const answers[] = {
    "Got it !",
    "Alright",
    "What's next ?",
    "Oui oui baguette",
};

static char buf[BUFFER_SIZE];

/*

Internal structure of std::vector<T> (g++)

template<typename T, typename Alloc = std::allocator<T>>
class vector {
private:
    T* _M_start; 
    T* _M_finish;
    T* _M_end_of_storage;
};

*/

static std::vector<char *> order;

int main(int argc, char * argv[])
{
    printf("Welcome to the Hexacon buffet !\n");
    printf("What would you like to eat ? (end your order with \"" TERMINATOR "\")\n");

    while(1) {
        printf("> ");
        scanf("%s", buf);
        
        if (!strcmp(buf, TERMINATOR))
            break;

        order.push_back(strdup(buf));

        puts(answers[rand() % (sizeof answers / sizeof *answers)]);
    }

    if (vip) {
        printf("As you are a VIP, we added a special french dish to your order !\n");
        puts(flag);
    }

    printf("Bon appetit !\n");

    return 0;
}
