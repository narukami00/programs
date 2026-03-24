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
        vector<int>child(n,0);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int>depth(n,0);

        function<void(int,int)>dfs=[&](int u,int p){
            for(int v:adj[u]){
                if(v!=p){
                    depth[v]=depth[u]+1;
                    child[u]++;
                    dfs(v,u);
                }
            }
        };
        dfs(0,-1);

        map<int,int>cnt;
        for(int i=0;i<n;i++){
            cnt[depth[i]]++;
        }

        int ans=0;
        for(auto x:cnt)ans=max(ans,x.s);

        for(int i=0;i<n;i++){
            ans=max(ans,child[i]+1);
        }

        cout<<ans<<endl;
    }
return 0;
}