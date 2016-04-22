#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ludotheque.h"
#include "jeu.h"

t_ludotheque* creer_ludotheque() {
    t_ludotheque *ludotheque;

    ludotheque = (t_ludotheque*)malloc(sizeof(t_ludotheque));
    if (ludotheque == NULL) return NULL;
    ludotheque->nb_jeu = 0;
    ludotheque->debut = NULL;
    return ludotheque;
}

int ajouter_jeu(t_ludotheque* ludo, t_jeu* j) {
    if (j==NULL || ludo == NULL) return 0;
    t_jeu* tete = ludo->debut;
    if (tete == NULL || strcmp(j->nom,tete->nom) < 0) {
        j->suivant = ludo->debut;
        ludo->debut = j;
    }
    else {
        while(tete->suivant != NULL && strcmp(j->nom,tete->suivant->nom) > 0) {
            tete = tete->suivant;
        }
        j->suivant = tete->suivant;
        tete->suivant = j;
    }
    return 1;
}

void affiche_ludotheque(t_ludotheque * ludo) {
    if (ludo==NULL) {
        printf("Aucune ludothèque a afficher !\n");
        return;
    }
    int i, counter = 0;
    printf("Nom\t\t\tType\t\tNombre de joueurs\tDurée moyenne\n");
    t_jeu *current = ludo->debut;
    while (current != NULL) {
        counter++;
        printf("%s",current->nom);
        for (i = 0; i < 3 - (strlen(current->nom) / 8); i++) {
            printf("\t");
        }
        char* genre = stringFromGenre(current->genre);
        printf("%s",genre);
        for (i = 0; i < 2 - (strlen(genre) / 8); i++) {
            printf("\t");
        }
        printf("%d-%d\t\t\t%d'\n",current->nbJoueurMin,current->nbJoueurMax,current->duree);
        current = current->suivant;
    }
    printf("Total\t%d\n",counter);
}

int retirer_jeu(t_ludotheque* ludo, char* nom) {
    if (ludo == NULL || nom == NULL) return 0;
    t_jeu *current = ludo->debut;
    if (strcmp(nom,current->nom) == 0) {
        ludo->debut = current->suivant;
        return 1;
    }
    while (current->suivant != NULL) {
        if (strcmp(nom,current->suivant->nom) == 0) {
            current->suivant = current->suivant->suivant;
            return 1;
        }
        current = current->suivant;
    }
    return 0;
}

void supprimer_ludotheque(t_ludotheque *ludo) {
    if (ludo != NULL) {
        t_jeu *current = ludo->debut;
        t_jeu *temp;
        while(current != NULL) {
            temp = current;
            current = current->suivant;
            free(temp);
            temp = NULL;
        }
        free(ludo);
        ludo = NULL;
    }
}

t_ludotheque* requete_jeu(t_ludotheque *ludo, genre_jeu genre, int nbJoueurs, int duree) {
    printf("\nRequete recue : %s %d %d\n",stringFromGenre(genre),nbJoueurs,duree);
    t_ludotheque *new_ludo = creer_ludotheque();
    if (ludo == NULL || new_ludo == NULL) return NULL;
    t_jeu *current = ludo->debut;
    while(current != NULL) {
        if (
             (genre == -1 || current->genre == genre)
            &&
             (nbJoueurs == -1 || (nbJoueurs <= current->nbJoueurMax && nbJoueurs >= current->nbJoueurMin))
            &&
             (
              duree == -1 ||
              (duree <= (current->duree + (current->duree)*0.1) && duree >= (current->duree - (current->duree)*0.1))
             )
           ) {
            ajouter_jeu(new_ludo,creer_jeu(current->nom,current->genre,current->nbJoueurMin,current->nbJoueurMax,current->duree));
        }
        current = current->suivant;
    }
    return new_ludo;
}

t_ludotheque* saisir_requete(t_ludotheque *ludo) {
    if (ludo == NULL)
        return NULL;
    char genre_str[10];
    int nb, duree;
    printf("Veuillez saisir dans l'ordre : genre, nombre de joueurs, duree\n");
    scanf("%s",genre_str);
    scanf("%d%d",&nb,&duree);
    while (getchar()!='\n'); // clear input
    return requete_jeu(ludo,strcmp(genre_str,"-1")==0?-1:genreFromString(genre_str),nb,duree);
}

t_ludotheque* fusion(t_ludotheque *ludo1, t_ludotheque *ludo2) {
    t_ludotheque *newl = creer_ludotheque();
    t_jeu *current, *old= newl->debut;
    if (ludo1 == NULL)
        return ludo2==NULL?NULL:ludo2;
    else if (ludo2 == NULL)
        return ludo1;
    t_jeu *debut1 = ludo1->debut;
    t_jeu *debut2 = ludo2->debut;
    while (debut1 != NULL || debut2 != NULL) {
        if (debut2 == NULL || (debut1 != NULL && strcmp(debut1->nom,debut2->nom) < 0)) {
            t_jeu *new_jeu = creer_jeu(debut1->nom,debut1->genre,debut1->nbJoueurMin,debut1->nbJoueurMax,debut1->duree);
            current = new_jeu;
            debut1 = debut1->suivant;
        }
        else if (debut1 == NULL || (debut2 != NULL && strcmp(debut2->nom,debut1->nom) < 0)) {
            t_jeu *new_jeu = creer_jeu(debut2->nom,debut2->genre,debut2->nbJoueurMin,debut2->nbJoueurMax,debut2->duree);
            current = new_jeu;
            debut2 = debut2->suivant;
        }
        else if (strcmp(debut2->nom,debut1->nom) == 0) {
            t_jeu *new_jeu = creer_jeu(debut2->nom,debut2->genre,debut2->nbJoueurMin,debut2->nbJoueurMax,debut2->duree);
            current = new_jeu;
            debut1 = debut1->suivant;
            debut2 = debut2->suivant;
        }
        if (newl->debut == NULL) newl->debut = current;
        else old->suivant = current;
        old = current;
    }
    return newl;
}
