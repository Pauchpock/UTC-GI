#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f,g,h,i,j;
    int result;

    printf("donnez 10 entiers");
    scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
    result = a+b+c+d+e+f+g+h+i+j;
    printf("%d+%d+%d+%d+%d+%d+%d+%d+%d+%d=%d",a,b,c,d,e,f,g,h,i,j,result);
}
