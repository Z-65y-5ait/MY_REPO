#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int j,n,NA=0;
    const int MAX=30,MIN=1;
    srand(time(NULL));
    NA=(rand()%(MAX-MIN+1))+MIN;
    for(j=1;j<=5;j++){
        printf("le nombre est:");
        scanf("%d",&n);
        if(n==NA){
            printf("vous avez trouve le bon nombre\n");
            break;
        }
        else if(n>NA){
            printf("plus bas\n");
        }
        else if(n<NA) {
            printf("plus haut\n");
        }
        else{
            printf("les 5 essais sont terminer la nombre etait:%d\n",NA);
        }
    }
    return 0;
}
