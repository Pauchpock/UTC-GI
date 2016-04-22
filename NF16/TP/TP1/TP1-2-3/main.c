#include <stdio.h>
#include <stdlib.h>

int table(int number) {
    int i;
    for (i = 1; i<=9; i++) {
        printf("%d: %d\n",i,i*number);
    }
}

int main()
{
    int i;
    do {
        printf("Quelle table de multiplication voulez-vous, tapez 0 (zéro) pour sortir ?");
        scanf("%d",&i);
        if (i >= 1 && i <= 9)
            table(i);
        else
            printf("ce n'est pas dans les possibilités du programme, recommencez !");
    } while (i != 0);
    return 0;
}
