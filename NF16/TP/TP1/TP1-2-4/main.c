#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
   while(1) {
       printf("Enter character: ");
       switch(c = getchar()) {
           case '1':
            printf("Un\n");
            break;
           case '2':
            printf("Deux\n");
            break;
           case '3':
            printf("Trois\n");
            break;
           default:
            printf("Autre caractere\n");
            break;
       }
       fflush(stdin);
   }
   return 0;
}
