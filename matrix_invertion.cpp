#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) x.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void get_cofact(vector<vector<double>>&mat, vector<vector<double>>&temp, int p, int q, int n){
    int i=0,j=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(row!=p && col!=q){
                temp[i][j++]=mat[row][col];
                if(j==n-1){
                    j=0;
                    i++;
                }
            }
        }
    }
}

double deter(vector<vector<double>>&mat, int n){
    if(n==1)return mat[0][0];
    double det=0;
    vector<vector<double>>temp(n, vector<double>(n,0));
    int sign=1;
    for(int f=0;f<n;f++){
        get_cofact(mat,temp,0,f,n);
        det+=sign*mat[0][f]*deter(temp,n-1);
        sign=-sign; 
    }
    return det;
}

vector<vector<double>>adjoint(vector<vector<double>>&mat){
    int n=mat.size();
    vector<vector<double>>adj(n,vector<double>(n,0));

    if(n==1){
        adj[0][0]=1;
        return adj;
    }

    int sign;
    vector<vector<double>>temp(n,vector<double>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            get_cofact(mat,temp,i,j,n);
            sign=((i+j)%2==0)?1:-1;
            adj[j][i]=sign*deter(temp,n-1);
        }
    }
    return adj;
}

vector<vector<double>>inverse(vector<vector<double>>&mat){
    int n=mat.size();
    double det=deter(mat,n);

    if(det==0){
        cout<<"Singular matrix, can't find its inverse"<<endl;
        exit(0);
    }

    vector<vector<double>>adj=adjoint(mat);
    vector<vector<double>>inv(n,vector<double>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inv[i][j]=adj[i][j]/det;
        }
    }
    return inv;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cout<<"Enter the order of the square matrix: ";
        cin>>n;

        vector<vector<double>>mat(n,vector<double>(n));
        vector<double>b(n);

        cout<<"Enter the elements of the matrix row-wise:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }

        cout<<"Enter the elements of the constant matrix (b):\n";
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        vector<vector<double>>inv=inverse(mat);
        vector<double>x(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x[i]+=inv[i][j]*b[j];
            }
        }

        cout<<"The solution matrix (x) is:\n";
        for(int i=0;i<n;i++){
            cout<<x[i]<<endl;
        }cout<<endl;
    }
return 0;
}