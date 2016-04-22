#include <stdio.h>
#include <stdlib.h>

#include "outils.h"

void afficher_menu() {
    printf("Que voulez-vous faire ?\n");
    printf("============================================================\n");
    printf("1 - Créer un ABR\n");
    printf("2 - Charger un fichier dans l'ABR\n");
    printf("3 - Caractéristiques de l'ABR\n");
    printf("4 - Afficher tous les mots distincts par ordre alphabétique\n");
    printf("5 - Rechercher un mot\n");
    printf("6 - Afficher les phrases contenant deux mots\n");
    printf("7 - Quitter\n");
    printf("============================================================\n");
}

int verifArbreNonNull(ArbreBR *arbre) {
    if (arbre == NULL) {
        printf("Vous devez créer un ABR avant ! Appuyez sur Entrée...\n");
        getchar();
        return 0;
    }
    return 1;
}

int main()
{
    ArbreBR *arbre = NULL;
    Phrase *phrase1 = NULL;
    char inputUser;
    afficher_menu();

    while ((inputUser = getchar()) != '7') {
        if (inputUser != '\n')
            while (getchar()!='\n'); // clear input

        switch(inputUser) {
            case '1':
                if (arbre != NULL) {
                    supprimerNoeud(arbre->racine);
                    free(arbre);
                    arbre = NULL;
                }
                arbre = creer_abr();
                if (arbre)
                    printf("Arbre créé !\n");
                else
                    printf("Une erreur a empêché l'arbre de se créer.\n");
                break;
            case '2':
                if (verifArbreNonNull(arbre)==0)
                    break;

                printf("Nom du fichier ? ");
                char filename[40];
                scanf("%s",filename);
                while (getchar()!='\n'); // clear input
                printf("%d mots lus.\n",charger_fichier(arbre,filename));
                phrase1 = (Phrase*) creerPhrases(filename);
                break;
            case '3':
                if (verifArbreNonNull(arbre)==0)
                    break;

                printf("Nombre de noeuds : %d\n",arbre->nb_mots_differents);
                printf("Hauteur : %d\n",getHauteur(arbre->racine));
                printf("Equilibré : %s\n",isEquilibre(arbre->racine)==1?"oui":"non");
                break;
            case '4':
                if (verifArbreNonNull(arbre)==0)
                    break;

                afficher_arbre(*arbre);
                break;
            case '5':
                if (verifArbreNonNull(arbre)==0)
                    break;

                char mot[40];
                printf("Mot à chercher ? ");
                scanf("%s",mot);
                while (getchar()!='\n'); // clear input
                NoeudABR *n = rechercher_noeud(arbre,mot);
                if (n!=NULL) {
                    Position *pos = n->positions->debut;
                    while (pos != NULL) {
                        printf("N° ligne: %d\tOrdre: %d\tN° de phrase: %d\n",pos->numero_ligne,pos->ordre,pos->numero_phrase);
                        pos = pos->suivant;
                    }
                }
                else
                    printf("Mot introuvable.\n");
                break;
            case '6':
                if (verifArbreNonNull(arbre)==0)
                    break;
                char mot1[20], mot2[20];
                printf("Entrez deux mots à chercher (séparés par la touche Entrée) :\n");
                scanf("%s",mot1);
                while (getchar()!='\n'); // clear input
                scanf("%s",mot2);
                while (getchar()!='\n'); // clear input
                printf("Recherche de \"%s\" et \"%s\"...\n",mot1,mot2);

                NoeudABR *n1 = rechercher_noeud(arbre,mot1);
                NoeudABR *n2 = rechercher_noeud(arbre,mot2);
                if (n1!=NULL && n2!=NULL) {
                    Position *pos1 = n1->positions->debut;
                    Position *pos2 = n2->positions->debut, *pos2_origine = pos2;
                    int num_phrase, ancien_num_phrase = -1;
                    while (pos1 != NULL) {
                        while (pos2 != NULL) {
                            if (((num_phrase = pos1->numero_phrase) == pos2->numero_phrase) && (num_phrase != ancien_num_phrase)) {
                                ancien_num_phrase = num_phrase;
                                printf("La phase n°%d contient les deux mots !\n",num_phrase);
                                afficher_phrase(phrase1, num_phrase);
                            }
                            pos2 = pos2->suivant;
                        }
                        pos2 = pos2_origine;
                        pos1 = pos1->suivant;
                    }
                }
                else
                    printf("Mot introuvable.\n");
                break;
            default:
                printf("Mauvaise entrée. Veuillez taper 1, 2, 3, 4, 5, 6 ou 7.\n");
                continue;
        }

        afficher_menu();
    }
    if (arbre != NULL) {
        supprimerNoeud(arbre->racine);
        free(arbre);
    }

    return 0;
}
