#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var1, var2, temp;
    printf("Entrez deux entiers :\n");
    scanf("%d",&var1);
    scanf("%d",&var2);
    temp = var1;
    var1 = var2;
    var2 = temp;
    printf("%d ; %d",var1, var2);
    return 0;
}
