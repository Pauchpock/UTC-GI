#include <stdio.h>
#include <stdlib.h>

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main()
{
    char c;
    do {
        scanf("%c",&c);
        switch(c) {
            case 'o':
            case 'O':
            case 'n':
            case 'N':
            case '0':
            case '1':
            case '2':
            case '3':
                printf("ok '%c'\n",c);
                break;
            default:
                printf("ko '%c'\n",c);
        }
        clean_stdin();
    } while (c != 'n' && c != 'N');
    return 0;
}
