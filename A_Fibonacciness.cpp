#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a1,a2,a3,a4,a5;
        cin>>a1>>a2>>a4>>a5;
        a3=a1+a2;
        int cnt1=1;
        if(a2+a3==a4)cnt1++;
        if(a3+a4==a5)cnt1++;

        a3=a4-a2;
        int cnt2=1;
        if(a1+a2==a3)cnt2++;
        if(a3+a4==a5)cnt2++;
         a3=a5-a4;
         int cnt3=1;
         if(a1+a2==a3)cnt3++;
         if(a2+a3==a4)cnt3++;
         if(cnt1>cnt3)
         {
             if(cnt1>cnt2)
             {
                 cout<<cnt1<<endl;

             }
             else{cout<<cnt2<<endl;}
         }
         else
         {
             if(cnt3>cnt2)
             {
                 cout<<cnt3<<endl;
             }
             else{cout<<cnt2<<endl;}
         }

       }

    }