#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<double>x={1,2,3,4,5};
    vector<double>y={2.2,2.8,3.6,4.5,5.1};
    int n=x.size();
    double sum_x=0,sum_y=0,sum_xy=0,sum_x2=0;
    for(int i=0;i<n;i++){
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=x[i]*y[i];
        sum_x2+=x[i]*x[i];
    }

    double m=(n*sum_xy-sum_x*sum_y)/(n*sum_x2-sum_x*sum_x);
    double c=(sum_y-m*sum_x)/n;

    cout<<"Y = "<<m<<"X + "<<c<<endl;
}