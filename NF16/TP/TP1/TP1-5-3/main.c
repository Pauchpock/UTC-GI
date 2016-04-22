#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficherMot(char motSecret[], char lettresTrouvees[]) {
    printf("Mot a trouver : ");
    int i;
    for (i = 0; i < strlen(motSecret); i++) {
        if (lettresTrouvees[i] == 0)
            printf("*");
        else
            printf("%c",motSecret[i]);
    }
    printf("\n");
}

char demanderLettre() {
    printf("\nEntrez une lettre : ");
    char c = getchar();
    while (getchar() != '\n');
    return c;
}

/**
* Retourne 0 si on a gagné, sinon autre chose
*/
int verifierLettre(char c, char motSecret[], char lettresTrouvees[]) {
    int gagne = strlen(motSecret);
    int i;
    for (i = 0; i < strlen(motSecret); i++) {
        if (motSecret[i] == c)
            lettresTrouvees[i] = 1;
        gagne -= lettresTrouvees[i];
    }
    return gagne;
}

int main()
{
    char motSecret[50];
    int lettresTrouvees[50];
    int nombreDeCoupsRestants = 10;
    int gagne = -1; // vaut 0 si on a gagné

    printf("Entrez le mot a deviner : ");
    scanf("%s",&motSecret);
    while (getchar() != '\n');

    int i;
    for (i = 0; i < strlen(motSecret); i++) {
        lettresTrouvees[i] = 0;
    }

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    do {
        afficherMot(motSecret, lettresTrouvees);
        printf("Coups restants : %d\n",nombreDeCoupsRestants);
        char c = demanderLettre();
        printf("Vous avez entre : %c\n",c);
        nombreDeCoupsRestants--;
        gagne = verifierLettre(c, motSecret, lettresTrouvees);
    } while (gagne != 0 && nombreDeCoupsRestants > 0);
    if (gagne == 0)
        printf("\nYOU WIN\n");
    else
        printf("\nYOU LOSE\n");

    printf("Le mot a trouver etait : %s",motSecret);
    return 0;
}
