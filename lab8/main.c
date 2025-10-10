#include <stdio.h>
#include <stdlib.h>
#define m 3
#define n 2
#define o 3
int main()
{
    int a[m][n][o]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    int *p=a;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<o;k++){
                printf("%d ",a[i][j][k]);
            }
        }
    }
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<o;k++){
                printf("%d ",*(p+i*n*o+j*o+k));
            }
        }
    }
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<o;k++){
                printf("%d ",*(*(*(a+i)+j)+k));
            }
        }
    }

    return 0;
}
