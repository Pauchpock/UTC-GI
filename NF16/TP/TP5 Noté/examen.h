#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

typedef struct Etudiant_s {
    char *nom;
    char *prenom;
    int numTD;
    int numTP;
    char semaine;
    struct Etudiant_s *suivant;
} Etudiant;

typedef struct ListeEtu_s {
    Etudiant *tete;
} ListeEtu;

ListeEtu* creerListe();

int ajouterEtu(ListeEtu *maListe, char *nom, char *prenom, int grp_td, int grp_tp, char semaine);

void afficherListe(ListeEtu *maListe);

void afficheListeTD(ListeEtu *maListe, int grp_td);

void retirerEtu(ListeEtu *maListe, char *nom1, char *prenom1);

int pgcd(int a, int b);

#endif // EXAMEN_H_INCLUDED
