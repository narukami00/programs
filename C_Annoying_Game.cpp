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
        int n,k;
        cin>>n>>k;
        vector<int>a(n),b(n);
        cin>>a>>b;

        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][0]=a[0];
        dp[0][1]=a[0]+b[0];
        int g1=dp[0][0];
        int g2=dp[0][1];
        int ans=max(g1,g2);

        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0]+a[i],a[i]);
            dp[i][1]=max({a[i]+b[i],dp[i-1][0]+a[i]+b[i],dp[i-1][1]+a[i]});
            g1=max(g1,dp[i][0]);
            g2=max(g2,dp[i][1]);
            ans=max(ans,max(g1,g2));
        }

        if(k%2==0)cout<<g1<<endl;
        else cout<<ans<<endl;
    }
return 0;
}