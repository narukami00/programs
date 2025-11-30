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

int32_t main(){
    Flashyy
    //tc
    {
        vector<double>x={1,2,3,4};
        vector<double>y={2.7,7.4,20.1,54.6};
    
        int n=sz(x);
        double sumx=0,sumy=0,sumxy=0,sumx2=0;
        for(int i=0;i<n;i++){
            sumx+=x[i];
            sumy+=log(y[i]);
            sumxy+=x[i]*log(y[i]);
            sumx2+=x[i]*x[i];
        }

        double b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
        double a=exp((sumy-b*sumx)/n);

        cout<<"y="<<a<<"e^("<<b<<"x)"<<endl;
    }
return 0;
}