#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,count=0;
    scanf("%d",&n);

    while(n){
        if(n-5>=0){n-=5;count++;}
        else if(n-4>=0) {n-=4;count++;}
        else if(n-3>=0) {n-=3;count++;}
        else if(n-2>=0) {n-=2;count++;}
        else if(n-1>=0) {n-=1;count++;}
        else break;


    }
    printf("%d",count);


    return 0;
}
