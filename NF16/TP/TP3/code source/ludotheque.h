#ifndef LUDOTHEQUE_H_INCLUDED
#define LUDOTHEQUE_H_INCLUDED
#include "jeu.h"

struct ludotheque {
    int nb_jeu;
    t_jeu *debut;
};

typedef struct ludotheque t_ludotheque;

t_ludotheque* creer_ludotheque();

int ajouter_jeu(t_ludotheque* ludo, t_jeu* j);

void affiche_ludotheque(t_ludotheque *ludo);

int retirer_jeu(t_ludotheque* ludo, char* nom);

void supprimer_ludotheque(t_ludotheque *ludo);

t_ludotheque* requete_jeu(t_ludotheque *ludo, genre_jeu genre, int nbJoueurs, int duree);

t_ludotheque* saisir_requete(t_ludotheque *ludo);

t_ludotheque* fusion(t_ludotheque *ludo1, t_ludotheque *ludo2);

#endif // LUDOTHEQUE_H_INCLUDED
