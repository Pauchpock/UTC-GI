#include <stdio.h>
#include <stdlib.h>

void genererMatrice(int taille, int matrice[50][50]) {
    int i, j;
    for (i = 0; i < taille; i++) {
        for (j = 0; j < taille; j++) {
            matrice[i][j] = rand() % 10; // 0 <--> 9
        }
    }
    afficher(taille,matrice);
}

void copieMatriceSaufLC(int matriceSource[50][50], int matriceDest[50][50], int ligne, int colonne, int tailleMatriceSource) {
    int i, j;
    int x = 0, y = 0;
    for (i = 0; i < tailleMatriceSource; i++) {
        if (i == ligne) i++;
        if (i >= tailleMatriceSource) break;
        for (j = 0; j < tailleMatriceSource; j++) {
            if (j == colonne) j++;
            if (j >= tailleMatriceSource) break;
            matriceDest[x][y] = matriceSource[i][j];
            y++;
        }
        x++;
    }
}

void afficher(int taille, int matrice[50][50]) {
    int i, j;
    printf("------------------------------------\n");
    for (i = 0; i<taille;i++) {
        for (j=0;j<taille;j++) {
            printf("%d\t",matrice[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}

int determinant(int indice, int taille, int matrice[50][50]) {
    int cursor, resultat = 0;
    int nouvelleMatrice[50][50];
    if (taille > 2) {
        for (cursor = 0; cursor < taille; cursor++) {
            copieMatriceSaufLC(matrice,nouvelleMatrice,0,cursor,taille-1);
            afficher(taille-1,nouvelleMatrice);
            resultat =+ ((int)pow(-1,(indice+cursor)*indice))*matrice[0][cursor]*determinant(indice+1,taille-1,nouvelleMatrice);
            printf("resulat: %d\n",resultat);
        }
        return resultat;
    }
    else {
        return (matrice[0][0] * matrice[1][1]) - (matrice[0][1] * matrice[1][0]);
    }
}

int main()
{
    int matrice[50][50];
    int taille, det;

    printf("Donnez la taille de la matrice carree (<=2) : ");
    scanf("%d",&taille);

    genererMatrice(taille,matrice);
    det = determinant(1,taille,matrice);

    printf("Le déterminant est : %d",det);
    return 0;
}
