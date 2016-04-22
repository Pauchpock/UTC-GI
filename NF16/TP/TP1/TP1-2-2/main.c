#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    do {
        printf("Entrez un nombre (negatif pour arreter) : ");
        scanf("%d",&i);
    } while(i>-1);
    printf("Fini !!!");
    return 0;
}
