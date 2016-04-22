#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "arbre.h"
#include "outils.h"

ArbreBR *creer_abr() {
    ArbreBR *a = (ArbreBR*) malloc(sizeof(ArbreBR));

    if (a) {
        a->racine = NULL;
        a->nb_mots_differents = 0;
        a->nb_mots_total = 0;
        return a;
    }
    else
        return NULL;
}

int ajouter_noeud(ArbreBR *arbre, NoeudABR *noeud) {
    if (arbre == NULL || noeud == NULL)
        return 0;

    NoeudABR *racine = arbre->racine, *old = arbre->racine;

    int comparaison;

    while (racine != NULL) {
        old = racine;
        comparaison = strcasecmp(racine->mot,noeud->mot);
        if (comparaison < 0)
            racine = racine->filsDroit;
        else if (comparaison > 0)
            racine = racine->filsGauche;
        else // même mot
            return 0;
    }
    if (old != NULL) {
        if (comparaison < 0) // (comparaison = strcasecmp(old->mot,noeud->mot)) < 0
            old->filsDroit = noeud;
        else if (comparaison > 0)
            old->filsGauche = noeud;
    }
    else
        arbre->racine = noeud;

    arbre->nb_mots_differents++;
    arbre->nb_mots_total++;
    return 1;
}

NoeudABR *rechercher_noeud(ArbreBR *arbre, char *mot) {
    if (arbre == NULL || mot == NULL)
        return NULL;

    NoeudABR *racine = arbre->racine;
    int comparaison;
    while (racine != NULL) {
        if ((comparaison = strcasecmp(mot,racine->mot)) > 0)
            racine = racine->filsDroit;
        else if (comparaison < 0)
            racine = racine->filsGauche;
        else
            return racine;
    }
    return NULL;
}

void parcours_infixe(NoeudABR *n) {
    if (n == NULL) return;
    parcours_infixe(n->filsGauche);
    printf("| %s |",n->mot);
    parcours_infixe(n->filsDroit);
}

void afficher_arbre(ArbreBR arbre) {
    if (arbre.racine == NULL)
        return;

    NoeudABR *racine = arbre.racine;
    parcours_infixe(racine);
    printf("\n");
}

void supprimerNoeud(NoeudABR *noeud) {
    if (noeud != NULL) {
        if (noeud->filsDroit != NULL)
            supprimerNoeud(noeud->filsDroit);
        if (noeud->filsGauche != NULL)
            supprimerNoeud(noeud->filsGauche);

        supprimerPosition(noeud->positions->debut);
        free(noeud->positions);
        free(noeud);
    }
}

int max (int a, int b) {
    return a>b?a:b;
}

int getHauteur(NoeudABR *noeud) {
    if (noeud == NULL)
        return -1;
    return 1+max(getHauteur(noeud->filsGauche), getHauteur(noeud->filsDroit));
}

int isEquilibre(NoeudABR *noeud) {
    if (noeud == NULL) return 1;
    int res = getHauteur(noeud->filsDroit) - getHauteur(noeud->filsGauche);
    if (res>1 || res<-1)
        return 0;
    else
        return (isEquilibre(noeud->filsGauche == 1) && isEquilibre(noeud->filsDroit) == 1)?1:0;
}
