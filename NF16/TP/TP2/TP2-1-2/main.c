#include <stdio.h>
#include <stdlib.h>

int factorielle(int n) { // the function call itself <=> RECURSVITY
    if (n > 0)
        return n*factorielle(n-1);
    else
        return 1;
}

int main()
{
    int nombre, resultat;
    resultat = 1;

    printf("Entrez un nombre positif dont vous voulez calculer la factorielle : ");
    scanf("%d",&nombre);
    resultat = factorielle(nombre);
    printf("Resultat : %d",resultat);
    return 0;
}
