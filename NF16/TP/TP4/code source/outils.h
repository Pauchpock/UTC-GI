#ifndef OUTILS_H_INCLUDED
#define OUTILS_H_INCLUDED

#include "arbre.h"

typedef struct mot {
    char* mot;
    struct mot *suivant;
} Mot;

typedef struct phrase {
    int numero;
    Mot *debut;
    struct phrase *suivante;
} Phrase;

void saveWord(ArbreBR *arbre, char *mot, int ligne, int ordre, int phrase);

int charger_fichier(ArbreBR *arbre, char *filename);

void ajouterMot(Phrase *p, char *m);

Phrase* creerPhrase(int numero);

Phrase *creerPhrases(char *filename);

void afficher_phrase(Phrase *phrase, int numero);

#endif // OUTILS_H_INCLUDED
