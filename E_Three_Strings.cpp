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
    tc
    {
        string a,b,c;
        cin>>a>>b>>c;
        int na=sz(a),nb=sz(b);
        vector<vector<int>>dp(na+1,vector<int>(nb+1,LLONG_MAX));
        dp[0][0]=0;
        for(int j=1;j<=nb;j++)dp[0][j]=dp[0][j-1]+(c[j-1]==b[j-1]?0:1);
        for(int i=1;i<=na;i++)dp[i][0]=dp[i-1][0]+(c[i-1]==a[i-1]?0:1);
        for(int i=1;i<=na;i++){
            for(int j=1;j<=nb;j++){
                int ca=(a[i-1]==c[i+j-1]?0:1);
                int cb=(b[j-1]==c[i+j-1]?0:1);
                dp[i][j]=min(dp[i-1][j]+ca,dp[i][j-1]+cb);
            }
        }
        cout<<dp[na][nb]<<endl;
    }
return 0;
}