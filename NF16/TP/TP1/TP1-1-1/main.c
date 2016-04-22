#include <stdio.h>
#include <stdlib.h>

int main()
{
    float var1, var2, somme;
    printf("Entrez deux nombres:\n");
    scanf("%f",&var1);
    scanf("%f",&var2);
    printf("Vous avez entré : %f ; %f\n", var1, var2);
    somme = var1 + var2;
    printf("La somme est : %f", somme);
    return 0;
}
