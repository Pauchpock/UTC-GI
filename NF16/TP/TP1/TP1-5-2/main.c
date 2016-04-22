#include <stdio.h>
#include <stdlib.h>

int main()
{
 int i=0;
 char chaine[100];

 printf("Escrivez un mot dans minuscules: \n");
 scanf("%s", chaine); // takes the string

 while(chaine[i]!='\0') //null or different than zero
{
chaine[i]-=32; //ASCII convertion
printf("%c",chaine[i]); //print the caracter
i++;
}
return 0;
 }


