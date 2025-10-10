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

const int inf=9e18;
int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        cin>>arr;

        vector<array<int,11>>dp(n+1);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=inf;
            }
        }

        dp[0][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                if(dp[i][j]==inf)continue;
                int cur=dp[i][j];
                int mn=arr[i];
                for(int d=0;j+d<=k && i+d<n;d++){
                    if(d>0)mn=min(mn,arr[i+d]);
                    int ni=i+d+1;
                    int nj=j+d;
                    dp[ni][nj]=min(dp[ni][nj],cur+(d+1)*mn);
                }
            }
        }
        
        int ans=inf;
        for(int j=0;j<=k;j++){
            ans=min(ans,dp[n][j]);
        }
        cout<<ans<<endl;
    }
return 0;
}