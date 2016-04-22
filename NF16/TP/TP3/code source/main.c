#include <stdio.h>
#include <stdlib.h>
#include "ludotheque.h"

void afficherMenu() {
    printf("Que voulez-vous faire ?\n");
    printf("==========================================================================\n");
    printf("1. Créer une ludothèque\n");
    printf("2. Afficher la dernière ludothèque créée\n");
    printf("3. Ajouter un jeu à la dernière ludothèque créée\n");
    printf("4. Effectuer une recherche dans la dernière ludothèque créée\n");
    printf("5. Créer une deuxième ludothèque et la fusionner avec la première\n");
    printf("6. Quitter\n");
    printf("==========================================================================\n\n");
}

int main() {
    t_ludotheque *ludo1 = NULL, *ludo2 = NULL, *temp = NULL;
    t_jeu *jeu11, *jeu12, *jeu13, *jeu14, *jeu21, *jeu22, *jeu23;
    char inputUser;

    afficherMenu();

    while((inputUser = getchar()) != '6') {
        while (getchar()!='\n'); // clear input

        switch(inputUser) {
            case '1':
                supprimer_ludotheque(ludo1);
                ludo1 = creer_ludotheque();
                jeu11 = creer_jeu("Jeu de l'oie",HASARD,2,10,30);
                jeu12 = creer_jeu("Echecs",RPG,1,4,90);
                jeu13 = creer_jeu("Monopoly",PLATEAU,2,3,10);
                jeu14 = creer_jeu("Tarot",RPG,2,6,15);
                ajouter_jeu(ludo1,jeu11);
                ajouter_jeu(ludo1,jeu12);
                ajouter_jeu(ludo1,jeu13);
                ajouter_jeu(ludo1,jeu14);
                printf("Ludothèque 1 créée et remplie.\n");
                break;
            case '2':
                printf("Ludothèque n°1\n");
                affiche_ludotheque(ludo1);
                break;
            case '3':
                printf("Creation d'un jeu\n");
                if (ajouter_jeu(ludo1,saisir_jeu()) == 0)
                    printf("Le jeu n'a pas été ajouté (la ludothèque n'existe pas ?)\n");
                else
                    printf("Le jeu a bien été ajouté !\n");
                break;
            case '4':
                if (ludo1==NULL)
                    printf("Aucune requête ne peut être effectuée : la ludothèque n'existe pas.\n");
                else {
                    temp = saisir_requete(ludo1);
                    if (temp != NULL)
                        affiche_ludotheque(temp);
                    else
                        printf("Une erreur est survenue.\n");
                }
                break;
            case '5':
                if (ludo1 == NULL) {
                    ludo1 = creer_ludotheque();
                    jeu11 = creer_jeu("CTest",HASARD,2,10,30);
                    jeu12 = creer_jeu("ATest",RPG,1,4,90);
                    jeu13 = creer_jeu("BTest",PLATEAU,2,3,10);
                    jeu14 = creer_jeu("zTest",RPG,2,6,15);
                    ajouter_jeu(ludo1,jeu11);
                    ajouter_jeu(ludo1,jeu12);
                    ajouter_jeu(ludo1,jeu13);
                    ajouter_jeu(ludo1,jeu14);
                    printf("Ludothèque 1 créée et remplie.\n");
                }
                else
                    printf("Ludothèque n°1\n");
                affiche_ludotheque(ludo1);

                supprimer_ludotheque(ludo2);
                ludo2 = creer_ludotheque();
                jeu21 = creer_jeu("CTest",HASARD,2,10,30);
                jeu22 = creer_jeu("BBTest",RPG,1,4,90);
                jeu23 = creer_jeu("ZTest",PLATEAU,2,3,10);
                ajouter_jeu(ludo2,jeu21);
                ajouter_jeu(ludo2,jeu22);
                ajouter_jeu(ludo2,jeu23);
                printf("Ludothèque 2 créée et remplie.\n");
                affiche_ludotheque(ludo2);
                printf("\nFusion...\n");
                temp = fusion(ludo1,ludo2);
                if (temp != NULL) affiche_ludotheque(temp);
                break;
            default:
                printf("Mauvaise entrée. Veuillez taper 1, 2, 3, 4, 5 ou 6.\n");
                continue;
        }

        printf("\n");
        afficherMenu();
    }
    printf("Au revoir !\n");
    supprimer_ludotheque(ludo1);
    supprimer_ludotheque(ludo2);
    return 0;
}
