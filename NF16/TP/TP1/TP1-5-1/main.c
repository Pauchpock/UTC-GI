#include <stdio.h>
#include <stdlib.h>

int main(char *argc[])
{
   //printf("Introducez un mot");
   //scanf("%c", &s)
   char chaine[] = "bonjour";
   int longueurChaine =0;

   longueurChaine = strlen(chaine);

   printf("la chaine %s fait %d caracteres de long", chaine, longueurChaine);



   return 0;
}
