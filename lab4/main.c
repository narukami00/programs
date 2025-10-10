#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter a number : \n");
    scanf("%d",&x);

    for(int i=x;i>=1;i--){
        for(int spc=(x-i);spc>=1;spc--){
            printf(" ");
        }
        for(int j=(2*i-1);j>=1;j--){
            printf("x");
        }
        printf("\n");
    }
    for(int i=2;i<=x;i++){
        for(int spc=1;spc<=(x-i);spc++){
            printf(" ");
        }
        for(int j=1;j<=(2*i-1);j++){
            printf("x");
        }
        printf("\n");
    }


    return 0;
}
