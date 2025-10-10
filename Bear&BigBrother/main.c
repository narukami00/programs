#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,count=0 ;
    scanf("%d %d",&a,&b);

    while(a<=b){
        a=3*a;
        b=2*b;
        count++;
    }

    printf("%d",count);

    return 0;
}
