#include<bits/stdc++.h>
using namespace std;

vector<vector<double>>fun(vector<double>&x, vector<double>&y, int n){
    vector<vector<double>>table(n,vector<double>(n));

    for(int i=0;i<n;i++)table[i][0]=y[i];

    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            table[i][j]=(table[i+1][j-1]-table[i][j-1])/(x[i+j]-x[i]);
        }
    }
    return table;
}

double prod(double x, vector<double>&xx, int k){
    double p=1.0;
    for(int i=0;i<k;i++)p*=(x-xx[i]);
    return p;
} 

int main(){
    int n;cin>>n;
    vector<double>x(n+1),y(n+1);
    for(int i=0;i<=n;i++)cin>>x[i];
    for(int i=0;i<=n;i++)cin>>y[i];

    double val;cin>>val;
    auto table=fun(x,y,n+1);

    double ans=0;
    for(int i=1;i<n;i++)ans+=table[0][i]*prod(val,x,i);

    double err=table[0][n]*prod(val,x,n);

    cout<<fixed<<setprecision(6)<<"Interpolated value at "<<val<<" is "<<ans+table[0][0]<<endl;
    cout<<fixed<<setprecision(6)<<"Estimated error is "<<err<<endl;
}