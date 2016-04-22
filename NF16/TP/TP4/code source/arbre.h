#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "liste.h"

typedef struct noeudABR {
    char *mot;
    ListePosition *positions;
    struct noeudABR *filsGauche;
    struct noeudABR *filsDroit;
} NoeudABR;

typedef struct arbreBR {
    NoeudABR *racine;
    int nb_mots_differents;
    int nb_mots_total;
} ArbreBR;

ArbreBR *creer_abr();

int ajouter_noeud(ArbreBR *arbre, NoeudABR *noeud);

NoeudABR *rechercher_noeud(ArbreBR *arbre, char *mot);

void parcours_infixe(NoeudABR *n);

void afficher_arbre(ArbreBR arbre);

void supprimerNoeud(NoeudABR *noeud);

int max (int a, int b);

int getHauteur(NoeudABR *noeud);

int isEquilibre(NoeudABR *n);

#endif // ARBRE_H_INCLUDED
