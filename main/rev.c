#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i;
    printf("veuillez saisir un entier:");
    scanf("%d",&n);
    i=0;
    m=n;
    do{
    i=(i*10)+(n%10);
    n=n/10;
    }while(n!=0);
    printf("%d",i);
    if(i==m)
        printf("palindrome");
    else
       printf("non palindrome");
    return 0;
}
