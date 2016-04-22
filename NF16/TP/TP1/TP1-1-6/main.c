#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Entrez un entier : ");
    scanf("%d", &i);
    if (i == 0)
        printf("Zero !");
    else if(i%2==0)
        printf("Pair !");
    else
        printf("Impair !");
    return 0;
}
