#include<bits/stdc++.h>
using namespace std;

void cofact(vector<vector<double>>&A, vector<vector<double>>&temp, int p, int q, int n){
    int i=0,j=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(row!=p && col!=q){
                temp[i][j++]=A[row][col];
                if(j==n-1)j=0,i++;
            }
        }
    }
}

double deter(vector<vector<double>>&A, int n){
    if(n==1)return A[0][0];
    double det=0;
    vector<vector<double>>temp(n,vector<double>(n));
    int sign=1;
    for(int i=0;i<n;i++){
        cofact(A,temp,0,i,n);
        det+=sign*A[0][i]*deter(temp,n-1);
        sign=-sign;
    }
    return det;
}

vector<vector<double>>adjoint(vector<vector<double>>&A){
    int n=A.size();
    vector<vector<double>>adj(n,vector<double>(n,0));
    if(n==1){adj[0][0]=1;return adj;}

    int sign;
    vector<vector<double>>temp(n,vector<double>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cofact(A,temp,i,j,n);
            sign=((i+j)%2==0)?1:-1;
            adj[j][i]=sign*deter(temp,n-1);
        }
    }
    return adj;
}

vector<vector<double>>inverse(vector<vector<double>>&A){
    int n=A.size();
    double det=deter(A,n);

    if(det==0){
        throw runtime_error("Singular matrix, can't find its inverse");
    }

    vector<vector<double>>adj=adjoint(A);
    vector<vector<double>>inv(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inv[i][j]=adj[i][j]/det;
        }
    }
    return inv;
}

int main(){
    int n;cin>>n;
    vector<vector<double>>mat(n,vector<double>(n));
    vector<double>b(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++)cin>>b[i];

    double det=deter(mat,n);

    vector<vector<double>>inv=inverse(mat);
    vector<double>ans(n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i]+=inv[i][j]*b[j];
        }
    }

    for(int i=0;i<n;i++)cout<<fixed<<setprecision(6)<<ans[i]<<endl;
}