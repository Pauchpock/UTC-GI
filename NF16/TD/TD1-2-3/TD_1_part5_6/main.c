#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = getchar();
    if (c >= 'a' && c <= 'z') {
        c-=32;
    }
    else if (c >= 'A' && c <= 'Z') {
        c+=32;
    }
    printf("%c",c);
    return 0;
}
