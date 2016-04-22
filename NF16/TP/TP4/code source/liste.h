#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

typedef struct position {
    int numero_ligne;
    int ordre;
    int numero_phrase;
    struct position *suivant;
} Position;

typedef struct listePosition {
    Position *debut;
    int nb_elements;
} ListePosition;

ListePosition *creer_liste_positions();

int ajouter_position(ListePosition *listeP, int ligne, int ordre, int num_phrase);

void supprimerPosition(Position *pos);

#endif // LISTE_H_INCLUDED
