#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "examen.h"

ListeEtu* creerListe() {
    ListeEtu* liste = (ListeEtu*) malloc(sizeof(ListeEtu));
    if (liste) {
        liste->tete = NULL;
        return liste;
    }
    else
        return NULL;
}

int ajouterEtu(ListeEtu *maListe, char *nom, char *prenom, int grp_td, int grp_tp, char semaine) {
    if (maListe == NULL) return 0;

    Etudiant* etu = (Etudiant*) malloc(sizeof(Etudiant));
    if (!etu) return 0;

    etu->nom = nom;
    etu->prenom = prenom;
    etu->numTD = grp_td;
    etu->numTP = grp_tp;
    etu->semaine = semaine;
    etu->suivant = NULL;

    Etudiant* tete = maListe->tete;
    if (tete == NULL) {
        maListe->tete = etu;
        return 1;
    }
    while(tete->suivant != NULL && strcmp(tete->nom,etu->nom) < 0) {
        tete = tete->suivant;
    }
    if (tete->suivant != NULL) {
        etu->suivant = tete->suivant;
    }
    tete->suivant = etu;
    return 1;
}

void afficherListe(ListeEtu *maListe) {
    if (maListe == NULL)
        printf("La liste n'existe pas.\n");
    else if (maListe->tete == NULL)
        printf("La liste est vide.\n");
    else {
        printf("\n======================\nAffichage liste\n======================\n");
        Etudiant *tete = maListe->tete;
        do {
            printf("%s %s\tTD: %d\tTP: %d\tsemaine: %c\n",tete->prenom, tete->nom, tete->numTD, tete->numTP, tete->semaine);
        }while((tete = tete->suivant) != NULL);
    }
}

void afficheListeTD(ListeEtu *maListe, int grp_td) {
    if (maListe == NULL)
        printf("La liste n'existe pas.\n");
    else if (maListe->tete == NULL)
        printf("La liste est vide.\n");
    else {
        printf("\n======================\nAffichage liste TD\n======================\n");
        Etudiant *tete = maListe->tete;
        do {
            if (tete->numTD == grp_td)
                printf("%s %s\tTD: %d\tTP: %d\tsemaine: %c\n",tete->prenom, tete->nom, tete->numTD, tete->numTP, tete->semaine);
        }while((tete = tete->suivant) != NULL);
    }
}

void retirerEtu(ListeEtu *maListe, char *nom1, char *prenom1) {
    Etudiant *tete;
    if (maListe != NULL && (tete = maListe->tete) != NULL) {
        Etudiant *prec = NULL;
        do {
            if (strcmp(tete->nom,nom1) == 0 && strcmp(tete->prenom,prenom1) == 0) {
                if (prec != NULL) {
                    prec->suivant = tete->suivant;
                }
                free(tete);
                return;
            }
            prec = tete;
        }while((tete = tete->suivant) != NULL);
    }
}

int pgcd(int a, int b) {
    if(a <= 0 || b <= 0) // Gestion des nombres négatifs ou nuls
        return 0;

    int res;
    if (b > a)
        return (res = pgcd(a,b % a))==0?a:res;
    else
        return (res = pgcd(b,a % b))==0?b:res;
}
