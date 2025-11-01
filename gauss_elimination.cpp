#include<bits/stdc++.h>
using namespace std;

void gauss_elimination(vector<vector<double>>aug_mat,int n){
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            if(fabs(aug_mat[i][i])<fabs(aug_mat[k][i])){
                swap(aug_mat[i],aug_mat[k]);
            }
        }

        for(int k=i+1;k<n;k++){
            double fact=aug_mat[k][i]/aug_mat[i][i];
            for(int j=i;j<=n;j++){
                aug_mat[k][j]-=fact*aug_mat[i][j];
            }
        }
    }

    vector<double>sol(n);
    for(int i=n-1;i>=0;i--){
        sol[i]=aug_mat[i][n];
        for(int j=i+1;j<n;j++){
            sol[i]-=aug_mat[i][j]*sol[j];
        }sol[i]/=aug_mat[i][i];
    }

    cout<<"The solution is:\n";
    for(int i=0;i<n;i++){
        cout<<"x"<<i+1<<" = "<<sol[i]<<"\n";
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
    gauss_elimination(aug_mat,n);
}