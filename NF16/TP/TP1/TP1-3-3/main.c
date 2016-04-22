#include <stdio.h>
#include <stdlib.h>

//void affiche(int *tableau, int tailleTableau);
int main(void)
{
    int Tableau [3][4] = {{12, 13, 14, 15},
                          {16, 17, 18, 19},
                          {20, 21, 22, 23},
                          };

    int i,j;
    for (i=0; i<3; i++){
    for (j=0; j<4; j++){

     printf("%d", Tableau[i][j]);
      }

    printf("\n");
}
return 0;

}

