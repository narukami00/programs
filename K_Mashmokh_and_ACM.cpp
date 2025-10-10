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
#define sz(x) x.size()
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

int32_t main(){
    Flashyy
    //tc
    {
        int n,k;
        cin>>n>>k;
        int dp[k+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        for(int i=0;i<k;i++){
            for(int j=1;j<=n;j++){
                for(int v=j;v<=n;v+=j){
                    dp[i+1][v]=(dp[i+1][v]+dp[i][j])%mod;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=(ans+dp[k][i])%mod;
        cout<<ans<<endl;
    }
return 0;
}