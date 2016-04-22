#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, y, r;
    printf("Donnez un pourcentage :\n");
    scanf("%f", &x);
    printf("Donnez un nombre :\n");
    scanf("%f", &y);
    printf("Le resultat est : ");
    r = x*(y/100);
    printf("%f", r);
}
