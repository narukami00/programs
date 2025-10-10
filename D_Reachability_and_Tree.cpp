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
        int n;
        cin>>n;
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int r=0;
        while(r<n && sz(adj[r])!=2){
            r++;
        }

        if(r>=n){
            no;
            continue;
        }

        vector<bool>vis(n,0);
        vector<pair<int,int>>ans;
        ans.pb({r,adj[r][0]});
        ans.pb({adj[r][1],r});
        vis[r]=1;

        function<void(int,bool)>dfs=[&](int v, bool in){
            vis[v]=1;
            for(int u:adj[v]){
                if(vis[u])continue;
                if(in)ans.pb({u,v});
                else ans.pb({v,u});
                dfs(u,!in);
            }
        };

        dfs(adj[r][0],1);
        dfs(adj[r][1],0);

        yes;
        sort(all(ans));
        for(auto [u,v]:ans){
            cout<<u+1<<sp<<v+1<<endl;
        }
    }
return 0;
}