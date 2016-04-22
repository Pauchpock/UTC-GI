#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Entrez un entier : ");
    scanf("%d", &i);
    printf("Entier: %d, Decimal: %f, Octal: %o, Hexa: %x",i,(float) i,i,i);
    return 0;
}
