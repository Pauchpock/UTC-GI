#include <stdio.h>
#include <stdlib.h>

int main()
{
    char var;
    printf("Entrez un charactere : ");
    scanf("%c",&var);
    if (var >= '0' && var <= '9')
        printf("Chiffre");
    else if (var >= 'a' && var <= 'z')
        printf("Minuscule");
    else if (var >= 'A' && var <= 'Z')
       printf("Majuscule");
    else
       printf("Unknown");
}
