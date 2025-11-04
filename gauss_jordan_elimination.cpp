#include<bits/stdc++.h>
using namespace std;

void gauss_jordan_elimination(vector<vector<double>>aug_mat,int n){
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(fabs(aug_mat[i][i])<fabs(aug_mat[k][i])){
                swap(aug_mat[i],aug_mat[k]);
            }
        }
        double diag=aug_mat[i][i];
        for(int j=0;j<=n;j++){
            aug_mat[i][j]/=diag;
        }
        for(int k=0;k<n;k++){
            if(k!=i){
                double fact=aug_mat[k][i];
                for(int j=0;j<=n;j++){
                    aug_mat[k][j]-=fact*aug_mat[i][j];
                }
                //aug_mat[k][n]-=fact*aug_mat[i][n];
            }
        }
    }
    cout<<"The solution is:\n";
    for(int i=0;i<n;i++){
        cout<<"x"<<i+1<<" = "<<aug_mat[i][n]<<"\n";
    }
}

int main(){
    int n;
    cout<<"Enter the number of variables: ";
    cin>>n;
    vector<vector<double>>aug_mat(n,vector<double>(n+1));
    cout<<"Enter the augmented matrix row-wise:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>aug_mat[i][j];
        }
    }
    cout<<"System of equations represented by the augmented matrix is:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"("<<aug_mat[i][j]<<")"<<"x"<<j+1;
            if(j!=n-1)cout<<" + ";
        }cout<<" = "<<aug_mat[i][n]<<"\n";
    }
    gauss_jordan_elimination(aug_mat,n);
}