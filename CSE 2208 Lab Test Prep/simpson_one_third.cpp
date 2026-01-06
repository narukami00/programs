#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 1.0/(1.0 + x*x);
}

int main(){
    double a=0,b=1;
    int n=10;

    if(n%2==1)n++;

    double h=(b-a)/n, res=f(a)+f(b);

    for(int i=1;i<n;i++){
        double x=a+i*h;
        if(i%2==0)res+=2*f(x);
        else res+=4*f(x);
    }

    res*=(h/3);
    cout<<fixed<<setprecision(6)<<res<<endl;
}