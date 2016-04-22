#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outils.h"

void saveWord(ArbreBR *arbre, char *mot, int ligne, int ordre, int phrase) {
    NoeudABR *noeud = rechercher_noeud(arbre,mot);
    if (noeud == NULL) { // Nouveau mot
        noeud = (NoeudABR*) malloc(sizeof(NoeudABR));
        noeud->positions = creer_liste_positions();
        noeud->mot = mot;
        noeud->filsGauche = NULL;
        noeud->filsDroit = NULL;
        ajouter_noeud(arbre,noeud);
    }
    else // Mot déjà présent
        arbre->nb_mots_total++;

    ajouter_position(noeud->positions,ligne,ordre,phrase);
}

int charger_fichier(ArbreBR *arbre, char *filename) {
    if (arbre == NULL)
        return 0;

    FILE *fp;
    int c, c_old;

    int ligne = 1, ordre = 1, phrase = 1;
    char *mot = (char*) malloc(sizeof(char)*26);
    int counter = 0, total = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Le fichier ne peut pas être ouvert.");
        return 0;
    }
    do {
        c_old = c;
        c = fgetc(fp);
        if (feof(fp)) // END OF FILE
            break;

        if (c == EOF || c == '\n') {
            if (c_old != '.' && c_old != ' ') {
                total++;
                mot[counter] = 0;
                saveWord(arbre,mot,ligne,ordre,phrase);
                ordre++;
            }
            ligne++;

            counter = 0;
            mot = (char*) malloc(sizeof(char)*26);
        }
        else if (c == ' ') {
            if (c_old != '.') {
                total++;
                mot[counter] = 0;
                saveWord(arbre,mot,ligne,ordre,phrase);
                ordre++;
            }

            counter = 0;
            mot = (char*) malloc(sizeof(char)*26);
        }
        else if (c == '.') {
            mot[counter] = 0;
            saveWord(arbre,mot,ligne,ordre,phrase);
            counter = 0;
            total++;
            ordre = 1;
            phrase++;
        }
        else {
            if (c == '\r') {
                c = c_old;
                continue; // WINDOWS SUCKS
            }
            mot[counter] = c;
            counter++;
        }
    }while(1);

    if (c_old != '.' && c_old != ' ' && c_old != '\n') {
        saveWord(arbre,mot,ligne,ordre,phrase);
        total++;
    }

    fclose(fp);
    return total;
}

void ajouterMot(Phrase *p, char *mot) {
    if (p == NULL || mot == NULL) return;

    Mot *m = (Mot*) malloc(sizeof(Mot));
    if (!m)
        return;
    m->mot = mot;
    m->suivant = NULL;

    Mot *debut = p->debut;
    if (debut != NULL) {
        while(debut->suivant != NULL) {
            debut = debut->suivant;
        }
        debut->suivant = m;
    }
    else
        p->debut = m;
}

Phrase* creerPhrase(int numero) {
    Phrase *phr = (Phrase*) malloc(sizeof(Phrase));
    if (!phr)
        return NULL;

    phr->debut = NULL;
    phr->numero = numero;
    phr->suivante = NULL;
    return phr;
}

Phrase *creerPhrases(char *filename) {
    int phrase = 1;
    Phrase *phr = creerPhrase(phrase);
    if (!phr)
        return NULL;

    Phrase *origine = phr;

    FILE *fp;
    int c, c_old;

    char *mot = (char*) malloc(sizeof(char)*26);
    int counter = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    do {
        c_old = c;
        c = fgetc(fp);
        if (feof(fp)) // END OF FILE
            break;

        if (c == EOF || c == '\n') {
            if (c_old != '.' && c_old != ' ') {
                mot[counter] = 0;
                ajouterMot(phr,mot);
            }
            counter = 0;
            mot = (char*) malloc(sizeof(char)*26);
        }
        else if (c == ' ') {
            if (c_old != '.') {
                mot[counter] = 0;
                ajouterMot(phr,mot);
            }

            counter = 0;
            mot = (char*) malloc(sizeof(char)*26);
        }
        else if (c == '.') {
            mot[counter] = 0;
            ajouterMot(phr,mot);
            counter = 0;
            phrase++;
            phr->suivante = creerPhrase(phrase);
            phr = phr->suivante;
        }
        else {
            if (c == '\r') {
                c = c_old;
                continue; // WINDOWS SUCKS
            }
            mot[counter] = c;
            counter++;
        }
    }while(1);

    if (c_old != '.' && c_old != ' ' && c_old != '\n') {
        ajouterMot(phr,mot);
    }

    fclose(fp);
    return origine;
}

void afficher_phrase(Phrase *phrase, int numero) {
    while(phrase != NULL) {
        if (phrase->numero == numero) {
            Mot *mot = phrase->debut;
            while (mot != NULL) {
                printf("%s ",mot->mot);
                mot = mot->suivant;
            }
        }
        phrase = phrase->suivante;
    }
    printf(".\n");
}
