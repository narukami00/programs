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

vector<double> gauss(vector<vector<double>>&a){
    int n=sz(a);

    for(int i=0;i<n;i++){
        int mxrow=i;
        for(int k=i+1;k<n;k++){
            if(fabs(a[k][i])>fabs(a[mxrow][i])){
                mxrow=k;
            }
        }
        swap(a[i],a[mxrow]);

        double div=a[i][i];
        for(int j=i;j<=n;j++){
            a[i][j]/=div;
        }

        for(int k=0;k<n;k++){
            if(k!=i){
                double fact=a[k][i];
                for(int j=i;j<=n;j++){
                    a[k][j]-=fact*a[i][j];
                }
            }
        }
    }

    vector<double>ans(n);
    for(int i=0;i<n;i++){
        ans[i]=a[i][n];
    }
    return ans;
}

int32_t main(){
    Flashyy
    //tc
    {
        vector<double>x = {1, 2, 3, 4, 5};
        vector<double>y = {2.2, 2.8, 3.6, 4.5, 5.1};

        int n=sz(x);
        int k=2; // Degree of polynomial

        vector<vector<double>>A(k+1,vector<double>(k+2,0));

        for(int row=0;row<=k;row++){
            for(int col=0;col<=k;col++){
                double sum=0;
                for(int i=0;i<n;i++){
                    sum+=pow(x[i],row+col);
                }
                A[row][col]=sum;
            }
        }

        for(int row=0;row<=k;row++){
            double sum=0;
            for(int i=0;i<n;i++){
                sum+=pow(x[i],row)*y[i];
            }
            A[row][k+1]=sum;
        }

        vector<double> coef=gauss(A);

        cout<<"The polynomial regression equation is: y = ";
        for(int i=0;i<=k;i++){
            cout<<coef[i];
            if(i!=k)cout<<"x^"<<i<<" + ";
        }
        cout<<endl;
    }
return 0;
}