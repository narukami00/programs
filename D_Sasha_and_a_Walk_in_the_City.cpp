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

const int MOD = 998244353;

int dfs(int u,int par,vector<vector<int>>&adj,int &ans){
    int tans=1;
    for(auto v:adj[u]){
        if(v!=par){
            int w=dfs(v,u,adj,ans);
            tans=(tans*w)%MOD;
            ans=(ans+w-1)%MOD;
        }
    }
    return tans+1;
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

        int ans=0;
        cout<<(dfs(0,-1,adj,ans)+ans)%MOD<<endl;
    }
return 0;
}