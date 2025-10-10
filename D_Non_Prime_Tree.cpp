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
            --u,--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int>ans(n);
        int last=1;
        ans[0]=last;

        function<void(int,int)>dfs=[&](int u, int p){
            for(int v:adj[u]){
                if(v==p)continue;
                ans[v]=last+1;
                while(ans[v]!=ans[u]+1 && (ans[v]%2!=ans[u]%2 || ans[v]-ans[u]==2)){
                    ans[v]++;
                }
                last=ans[v];
                dfs(v,u);
            }
        };

        dfs(0,0);
        cout<<ans<<endl;
    }
return 0;
}