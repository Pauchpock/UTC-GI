#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

typedef enum genre {
    PLATEAU, RPG, COOPERATIF, AMBIANCE, HASARD
} genre_jeu;

typedef struct jeu {
    char *nom;
    genre_jeu genre;
    int nbJoueurMin;
    int nbJoueurMax;
    int duree;
    struct jeu *suivant;
} t_jeu;

t_jeu* creer_jeu(char *nom, genre_jeu genre, int nbJoueurMin, int nbJoueurMax, int duree);

t_jeu* saisir_jeu();

char *stringFromGenre(enum genre g);

genre_jeu genreFromString(char *str);

#endif // JEU_H_INCLUDED
