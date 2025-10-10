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

int dfs(int node,vector<vector<int>>& adj, vector<int>& vis,vector<int>& arr){
    int mini=arr[node];
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            mini=min(mini,dfs(it,adj,vis,arr));
        }
    }
    return mini;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        cin>>arr;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans+=dfs(i,adj,vis,arr);
            }
        }
        cout<<ans<<endl;
    }
return 0;
}