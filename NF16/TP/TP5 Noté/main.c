#include <stdio.h>
#include <stdlib.h>

#include "examen.h"

int main()
{
    ListeEtu *listeNF16 = creerListe();

    afficherListe(listeNF16);

    ajouterEtu(listeNF16,"DUPONT","Simone",1,1,'A');
    ajouterEtu(listeNF16,"MARTIN","Jacques",1,2,'B');
    ajouterEtu(listeNF16,"DURAND","Fabrice",2,3,'A');
    ajouterEtu(listeNF16,"DUPOND","Pierre",3,2,'B');
    ajouterEtu(listeNF16,"RICHARD","Renaud",3,1,'A');
    ajouterEtu(listeNF16,"LEBLANC","Valerie",2,1,'B');
    ajouterEtu(listeNF16,"LENOIR","Pascale",2,2,'A');
    ajouterEtu(listeNF16,"BARBIER","Yannick",1,2,'B');
    ajouterEtu(listeNF16,"LECLERC","Adeline",2,1,'A');
    ajouterEtu(listeNF16,"LEFEVRE","Michele",2,2,'A');
    ajouterEtu(listeNF16,"DARRAS","Francis",3,2,'A');
    ajouterEtu(listeNF16,"ROLLAND","Richard",3,3,'A');

    afficherListe(listeNF16);

    afficheListeTD(listeNF16,3);

    retirerEtu(listeNF16,"MARTIN","Jacques");
    retirerEtu(listeNF16,"LECLERC","Adeline");
    retirerEtu(listeNF16,"HOLLANDE","Francois");

    afficherListe(listeNF16);

    printf("\n\nLe PGCD de 56 et 20 est : %d\n\n",pgcd(56,20));
    printf("\n\nLe PGCD de 198 et 256 est : %d\n\n",pgcd(198,256));
    printf("\n\nLe PGCD de 15489 et 156 est : %d\n\n",pgcd(15489,156));
    return 0;
}
