#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = getchar();
    for (c = 'A'; c <= 'Z'; c++) {
        printf("%c: %d %x\n",c,c,c);
    }
    for (c = 'a'; c <= 'z'; c++) {
        printf("%c: %d %x\n",c,c,c);
    }
    return 0;
}
