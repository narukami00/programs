#include <stdio.h>

int main()
{
    int id,unit,bill,surcharge;

    printf("Please input your Customer ID : \n");
    scanf("%d",&id);
    printf("How many units did you consume this month? \n");
    scanf("%d",&unit);


    if(unit>=400)
    {
        bill=10*unit;
        surcharge = bill*0.15;
        bill=bill + (bill*0.15);

    }
    else if(unit>200)
    {
        bill=7*unit;
        surcharge=bill*0.15;
        bill=bill + (bill*0.15);
    }
    else if(unit <=199 && unit>20)
    {
        bill=5*unit;
        if(bill>200){

            surcharge=bill*0.15;
            bill=bill + (bill*0.15);
        }
        else{surcharge=0;}



    }
    else if(unit<=20)
    {
        bill=100;
        surcharge=0;
    }
    printf("Your bill is %d tk\n",bill);
    printf("Surcharge : %d tk",surcharge);
    return 0;
}
