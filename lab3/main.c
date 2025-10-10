#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    A:
    printf("Enter your marks : \n");
    scanf("%f",&num);
    num=num/10;
    if(num>10 || num<0){
    printf("Invalid Input.\n");
    goto A;
    }
    num=round((int)num);

    switch((int)num){

    case 10:
        printf("A");
        break;
    case 9:
        printf("A");
        break;
    case 8:
        printf("B");
        break;
    case 7:
        printf("C");
        break;
    case 6:
        printf("D");
        break;
    default: printf("F");
        break;


        }











    return 0;

}
