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
        int n,st,en;
        cin>>n>>st>>en;
        vector<vector<int>>adj(n+1);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int>dp(n+1,-1);
        queue<int>q;
        dp[en]=0;
        q.push(en);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int nxt:adj[cur]){
                if(dp[nxt]==-1){
                    dp[nxt]=dp[cur]+1;
                    q.push(nxt);
                }
            }
        }
        vector<pair<int,int>> ans;
        for(int i=1;i<=n;i++)ans.pb({dp[i],i});

        sort(rall(ans));
        for(auto &it:ans)cout<<it.s<<sp;
        cout<<endl;
    }
return 0;
}