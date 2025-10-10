#include <stdio.h>
#include <ctype.h>

int main(){

    char unit ;
    float temp;

    printf("\nIs the Tempreature in C ,F or K? ");
    scanf("%c",&unit);

    unit = toupper(unit);

    if(unit=='C'){

        char conv;

        printf("\nWhat temp do you want to convert in?");
        scanf(" %c",&conv);

        conv = toupper(conv);

        printf("\nEnter the temp.");
        scanf("%f",&temp);


        if(conv=='F'){

            temp = (temp*9/5)+32;
            printf("\nThe temp in F is %f",temp);


        }
        else if(conv=='K'){

            temp = (temp+273);
            printf("\nThe temp in K is %f",temp);

        }
        else{printf("\nEnter a valid unit");}




    }

    else if(unit=='F'){

        char conv;

        printf("\nWhat temp do you want to convert in?");
        scanf(" %c",&conv);

        conv = toupper(conv);

        printf("\nEnter the temp.");
        scanf("%f",&temp);

        if(conv=='C'){

            temp = (temp-32)*5/9;
            printf("\nThe temp in C is %f",temp);


        }
        else if(conv=='K'){

            temp = ((temp-32)*5/9)+273;
            printf("\nThe temp in K is %f",temp);

        }
        else{printf("\nEnter a valid unit");}



    }

    else if(unit=='K'){

        char conv;

        printf("\nWhat temp do you want to convert in?");
        scanf(" %c",&conv);

        conv = toupper(conv);

        printf("\nEnter the temp.");
        scanf("%f",&temp);

        if(conv=='F'){

            temp = ((temp-273)*9/5)+32;
            printf("\nThe temp in F is %f",temp);


        }
        else if(conv=='C'){

            temp = (temp-273);
            printf("\nThe temp in C is %f",temp);

        }
        else{printf("\nEnter a valid unit");}



    }
    else{printf("\nPlease enter a valid unit");}


}
