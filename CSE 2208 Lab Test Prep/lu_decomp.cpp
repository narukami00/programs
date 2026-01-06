#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<vector<double>>A(n,vector<double>(n)),L(n,vector<double>(n,0.0)),U(n,vector<double>(n,0.0));
    vector<double>b(n),x(n),y(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            (j==n)?cin>>b[i]:cin>>A[i][j];
        }
    }

    // Check for no solution or infinite solutions ------------------------------
    {
        vector<vector<double>>aug(n,vector<double>(n+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)aug[i][j]=A[i][j];
            aug[i][n]=b[i];
        }

        for(int i=0;i<n;i++){
            int mx=i;
            for(int k=i+1;k<n;k++){
                if(fabs(aug[k][i])>fabs(aug[mx][i])){
                    mx=k;
                }
            }

            swap(aug[i],aug[mx]);

            for(int k=i+1;k<n;k++){
                double fact=aug[k][i]/aug[i][i];
                for(int j=i;j<=n;j++)aug[k][j]-=fact*aug[i][j];
            }
        }

        int ra=0,rb=0;
        for(int i=0;i<n;i++){
            bool za=1,zab=1;
            for(int j=0;j<n;j++){
                if(fabs(aug[i][j])>1e-10){
                    za=0,zab=0;break;
                }
            }
            if(!za)ra++;
            if(za && fabs(aug[i][n])>1e-10)zab=0;
            if(!zab)rb++;
        }

        if(rb>ra){
            cout<<"No solution exists"<<endl;
            return 0;
        }else if(ra>rb){
            cout<<"Infinite solutions exist"<<endl;
            return 0;
        }
    }

    // end of check ------------------------------------------

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
        }
        y[i]=b[i]-sum;
    }

    for(int i=n-1;i>=0;i--){
        double sum=0.0;
        for(int j=i+1;j<n;j++){
            sum+=U[i][j]*x[j];
        }
        x[i]=(y[i]-sum)/U[i][i];
    }

    for(int i=0;i<n;i++)cout<<fixed<<setprecision(6)<<x[i]<<endl;
}