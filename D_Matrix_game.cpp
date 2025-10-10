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
const int MOD = 1e9+7;

int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;   
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);    
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}


int32_t main(){
    Flashyy
    int MAX=1e5;
    vector<int>fact(MAX+1,1),invfact(MAX+1,1);
    for(int i=1;i<=MAX;i++){
        fact[i]=mul(fact[i-1],i);
    }
    invfact[MAX]=inv(fact[MAX]);
    for(int i=MAX;i>0;i--){
        invfact[i-1]=mul(invfact[i],i);
    }
    tc
    {
        int a,b,k;
        cin>>a>>b>>k;

        int n=(mul(k,a-1)+1)%MOD;

        int t=1;
        for(int i=0;i<a;i++){
            t=mul(t,add(n,-i));
        }
        
        int c=mul(t,invfact[a]);

        int m=(mul(k,mul(c,b-1))+1)%MOD;

        cout<<n<<sp<<m<<endl;
    }
return 0;
}