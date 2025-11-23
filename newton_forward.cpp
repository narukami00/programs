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

vector<vector<double>> div_dif(vector<double>&x, vector<double>&y, int n){
    vector<vector<double>>table(n,vector<double>(n));

    for(int i=0;i<n;i++)table[i][0]=y[i];

    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            table[i][j]=(table[i+1][j-1]-table[i][j-1])/(x[i+j]-x[i]);
        }
    }
    return table;
}

double prod_terms(double x, vector<double>&xp, int k){
    double p=1.0;
    for(int i=0;i<k;i++){
        p*=(x - xp[i]);
    }
    return p;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cout<<"Enter the number of data points: ";
        cin>>n;

        vector<double>x(n+1),y(n+1);
        cout<<"Enter "<<n+1<<" x-values including the extra point:";
        for(int i=0;i<=n;i++)cin>>x[i];

        cout<<"Enter "<<n+1<<" y-values including the extra point:";
        for(int i=0;i<=n;i++)cin>>y[i];

        double val;
        cout<<"Enter value of x to interpolate: ";
        cin>>val;

        auto table=div_dif(x,y,n+1);

        double interp_val=table[0][0];
        for(int i=1;i<n;i++){
            interp_val+=table[0][i]*prod_terms(val,x,i);
        }

        double trunc_err=table[0][n]*prod_terms(val,x,n);

        cout<<fixed<<setprecision(6);
        cout<<"Interpolated value at x = "<<val<<" is "<<interp_val<<endl;
        cout<<"Truncation Error at x = "<<val<<" is "<<trunc_err<<endl;
    }
return 0;
}