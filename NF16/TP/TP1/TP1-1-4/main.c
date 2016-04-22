#include <stdio.h>
#include <stdlib.h>

int main()
{
     double f, c;
     printf("donnez la temperature en F \n");
     scanf("%lf", &f);
     c = ((5.0/9.0) * (f - 32.0));
     printf("la temperature en C : %lf (farenheit : %lf)", c, f);
}
