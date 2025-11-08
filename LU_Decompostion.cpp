#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of variables: ";
    cin>>n;

    vector<vector<double>>A(n,vector<double>(n));
    vector<double>b(n),x(n),y(n);
    vector<vector<double>>L(n,vector<double>(n,0.0)),U(n,vector<double>(n,0.0));
    
    cout<<"Enter the augmented matrix A row-wise:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(j==n)cin>>b[i];
            else cin>>A[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            double sum=0.0;
            for(int j=0;j<i;j++){
                sum+=L[i][j]*U[j][k];
            }
            U[i][k]=A[i][k]-sum;
        }

        for(int k=i;k<n;k++){
            if(i==k)L[i][i]=1.0;
            else{
                double sum=0.0;
                for(int j=0;j<i;j++){
                    sum+=L[k][j]*U[j][i];
                }
                L[k][i]=(A[k][i]-sum)/U[i][i];
            }
        }
    }

    for(int i=0;i<n;i++){
        double sum=0.0;
        for(int j=0;j<i;j++){
            sum+=L[i][j]*y[j];
        }y[i]=b[i]-sum;
    }

    for(int i=n-1;i>=0;i--){
        double sum=0.0;
        for(int j=i+1;j<n;j++){
            sum+=U[i][j]*x[j];
        }x[i]=(y[i]-sum)/U[i][i];
    }

    cout<<"The solution is:\n";
    for(int i=0;i<n;i++)cout<<"x"<<i+1<<" = "<<x[i]<<"\n";
}