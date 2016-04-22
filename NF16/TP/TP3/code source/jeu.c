#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "jeu.h"

t_jeu* creer_jeu(char *nom, genre_jeu genre, int nbJoueurMin, int nbJoueurMax, int duree) {
    t_jeu *jeu;
    jeu = (t_jeu*)malloc(sizeof(t_jeu));
    if (jeu == NULL) return NULL;
    jeu->nom = nom;
    jeu->genre = genre;
    jeu->nbJoueurMin = nbJoueurMin;
    jeu->nbJoueurMax = nbJoueurMax;
    jeu->duree = duree;
    return jeu;
}

t_jeu* saisir_jeu() {
    char *nom = (char*)malloc((sizeof(char))*50);
    char genre_str[10];
    int nbMin, nbMax, duree;
    printf("Veuillez saisir dans l'ordre : nom, genre, nombre de joueurs minimum, nombre de joueurs maximum, la duree.\n");
    scanf("%s",nom);
    scanf("%s",genre_str);
    scanf("%d%d%d",&nbMin,&nbMax,&duree);
    while (getchar()!='\n'); // clear input
    return creer_jeu(nom,genreFromString(genre_str),nbMin,nbMax,duree);

}

char *stringFromGenre(enum genre g) {
    if (g == -1) return "-1";
    static char *strings[] = { "PLATEAU", "RPG", "COOPERATIF", "AMBIANCE", "HASARD" };
    return strings[g];
}

genre_jeu genreFromString(char *str) {
    if (strcasecmp(str,"AMBIANCE") == 0) // si strcasecmp() n'existe pas sur votre OS utilisez strcmp()
        return AMBIANCE;
    else if (strcasecmp(str,"COOPERATIF") == 0) // si strcasecmp() n'existe pas sur votre OS utilisez strcmp()
        return COOPERATIF;
    else if (strcasecmp(str,"RPG") == 0) // si strcasecmp() n'existe pas sur votre OS utilisez strcmp()
        return RPG;
    else if (strcasecmp(str,"PLATEAU") == 0) // si strcasecmp() n'existe pas sur votre OS utilisez strcmp()
        return PLATEAU;
    else if (strcasecmp(str,"HASARD") == 0) // si strcasecmp() n'existe pas sur votre OS utilisez strcmp()
        return HASARD;
    return HASARD;
}
