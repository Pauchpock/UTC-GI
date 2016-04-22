#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombre, resultat;
    resultat = 1;

    printf("Entrez un nombre positif dont vous voulez calculer la factorielle : ");
    scanf("%d",&nombre);
    for(;nombre>0;nombre--) {
        resultat *= nombre; // <=> resultat = resultat * nombre;
    }
    printf("Resultat : %d",resultat);
    return 0;
}
