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
        int n,k;
        cin>>n>>k;
        vector<vector<int>>adj(n+1);

        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        vector<bool>vis(n+1,0);
        int ans=0;


        function<void(int)> dfs=[&](int u){
            vis[u]=1;
            dp[u][0]=1;
            vector<int>cnt(k+1,0);
            cnt[0]=1;

            for(int v:adj[u]){
                if(vis[v])continue;
                dfs(v);
                for(int d=1;d<=k;d++){
                    ans+=dp[v][d-1]*cnt[k-d];
                }
                for(int d=1;d<=k;d++){
                    cnt[d]+=dp[v][d-1];
                    dp[u][d]+=dp[v][d-1];
                }
            }
        };

        dfs(1);

        cout<<ans<<endl;
    }
return 0;
}