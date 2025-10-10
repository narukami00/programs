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

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(m);
        for(auto &it:a)cin>>it;
        for(auto &it:b)cin>>it;
        vector<int>pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<=m;i++){
            int sum=b[i-1];
            for(int j=0;j<n;j++){
                if(dp[j]==1e9) continue;
                int indx=upper_bound(all(pre),sum+(j==0?0:pre[j-1]))-pre.begin();
                if(indx==j) continue;
                dp[indx]=min(dp[indx],dp[j]+(m-i));
            }
        }
        if(dp[n]==1e9)dp[n]=-1;
        cout<<dp[n]<<endl;
    }
return 0;
}