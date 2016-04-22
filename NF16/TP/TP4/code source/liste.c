#include <stdlib.h>
#include "liste.h"

ListePosition *creer_liste_positions() {
    ListePosition *list = (ListePosition*) malloc(sizeof(ListePosition));
    if (list) {
        list->debut = NULL;
        list->nb_elements = 0;
        return list;
    }
    else
        return NULL;
}

int ajouter_position(ListePosition *listeP, int ligne, int ordre, int num_phrase) {
    if (listeP == NULL)
        return 0;

    Position *pos = (Position*) malloc(sizeof(Position));
    if (pos) {
        listeP->nb_elements++;
        pos->numero_ligne = ligne;
        pos->ordre = ordre;
        pos->numero_phrase = num_phrase;
        pos->suivant = NULL;

        Position *cursor = listeP->debut;
        if (cursor != NULL) {
            while (cursor->suivant != NULL)
                cursor = cursor->suivant;
            cursor->suivant = pos;
        }
        else
            listeP->debut = pos;
        return 1;
    }
    else
        return 0;
}

void supprimerPosition(Position *pos) {
    if (pos != NULL) {
        Position *current = pos->suivant, *old = pos;
        while (current != NULL) {
            free(old);
            old = current;
            current = current->suivant;
        }
        free(old);
    }
}
