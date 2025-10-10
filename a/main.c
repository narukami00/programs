#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5]={4,5,7,9,3};
    int l=1,r=3,k=10,sum=0;

    for(int i=1;i<5;i++){
        if(i>=l && i<=r){
            arr[i]=k;
        }
    }
    for(int i=0;i<5;i++){
        sum=sum+arr[i];
    }
    if(sum%2==0)
        printf("Yes");
    else
        printf("No");
    return 0;
}
