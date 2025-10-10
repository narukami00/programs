#include <stdio.h>
#include <stdlib.h>

int smaller(int *a , int *b){
     return (*a>*b)?1:0;
}

int larger(int *a , int *b){
     return (*a<*b)?1:0;
}

void sort(int *a , int (*compare) (int* , int*)){
    int temp;

    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){

                if(compare(a+i,a+j)){
                    temp=*(a+i);
                    *(a+i)=*(a+j);
                    *(a+j)=temp;
                }

        }
    }

}

int main()
{
    int a[2][2][2] = {5,2,4,9,1,0,4,6};
    sort((int*)a,smaller);
    int *p=(int*)a;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                printf("%d ",*(p+i*2*2+j*2+k));
            }
        }

    }

    return 0;
}/*The array is of size 2x2x2 and contains the following elements: {5,2,4,9,1,0,4,6}.
 The program should define two comparison functions, smaller and larger, to determine the order of two integers.
 The sort function should take the array and a comparison function as arguments, and sort the array using the comparison function.
 The sorted array should then be printed to the console.*/
