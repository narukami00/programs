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
const int N=2e5;
int32_t main(){
    Flashyy
    vector<int>pow2(N+1,1);
    for(int i=1;i<=N;i++){
        pow2[i]=(pow2[i-1]*2)%mod;
    }
    tc
    {
        int n,k;
        cin>>n>>k;
        
        vector<int>freq(64,0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            freq[x]++;
        }

        vector<int>cnt(64,0);
        for(int mask=0;mask<64;mask++){
            int c=0;
            for(int x=0;x<64;x++){
                if((x&mask)==mask)c+=freq[x];
            }cnt[mask]=c;
        }

        vector<int>f(64,0);
        for(int mask=0;mask<64;mask++){
            f[mask]=(pow2[cnt[mask]]+mod-1)%mod;
        }

        int ans=0;
        for(int i=0;i<64;i++){
            if(__builtin_popcount(i)!=k)continue;
            int total=0;
            for(int j=0;j<64;j++){
                if((j&i)!=i) continue;
                int p=__builtin_popcount(j)-__builtin_popcount(i);
                int sign=(p&1)?mod-1:1;
                total=(total+sign*f[j])%mod;
            }ans=(ans+total)%mod;
        }
        cout<<ans<<endl;
    }
return 0;
}