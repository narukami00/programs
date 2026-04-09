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

const int mod=1e9+7;
const int N=3e5+5;

int fact[N];
int invFact[N];


int fast_mod_exp(int a,int b){
    int res=1;
    while(b>0){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invFact[N - 1] = fast_mod_exp(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

int ncr(int n,int r){
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
}


int32_t main(){
    Flashyy
    precompute();

    tc
    {
        int n,k;
        cin>>n>>k;
        int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(x==0)cnt0++;
            else cnt1++;
        }
        int start=(k+1)/2;
        int endd=min(k,cnt1);

        int ans=0;
        for(int x=start;x<=endd;x++){
            ans=(ans+(ncr(cnt1,x)*ncr(cnt0,k-x))%mod)%mod;
        }

        cout<<ans<<endl;
    }
return 0;
}