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
const int mod=998244353;
const int MAX=30;
int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cin>>n;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];

        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]^arr[i];

        int cnt[2][MAX]={0};
        int sum[2][MAX]={0};
        int res[MAX]={0};

        for(int j=0;j<=n;j++){
            for(int k=0;k<MAX;k++){
                int bit=(pre[j]>>k)&1;
                int rev=bit^1;

                if(cnt[rev][k]>0)res[k]+=(cnt[rev][k]*j-sum[rev][k]);

                cnt[bit][k]++;
                sum[bit][k]+=j;
            }
        }

        int ans=0;
        for(int k=0;k<MAX;k++){
            ans=(ans+(res[k]%mod)*((1<<k)%mod))%mod;
        }

        cout<<ans<<endl;
    }
return 0;
}