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

int dfs(int v, vector<vector<int>>&adj, vector<bool>&vis,vector<int>&a){
    vis[v]=1;

    if(sz(adj[v])==0){
        return a[v];
    }

    int mn=LLONG_MAX;

    for(auto u:adj[v]){
        if(!vis[u]){
            int x=dfs(u,adj,vis,a);
            mn=min(mn,x);
        }
    }


    int diff=mn-a[v];

    //cout<<"at :"<<v<<" now diff is "<<diff<<endl;

    if(v==0){
        a[0]+=mn;
        return a[0];
    }

    if(diff>=2){
        a[v]+=(diff/2);
    }


    //cout<<"at :"<<v<<" now min is "<<mn<<endl;

    return min(mn,a[v]);
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n);
        cin>>a;

        vector<vector<int>>adj(n);
        vector<bool>vis(n,0);

        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            adj[x-1].pb(i-1);
        }

        // for(int i=0;i<n;i++){
        //     cout<<i<<" : ";
        //     cout<<adj[i]<<endl;
        // }

        cout<<dfs(0,adj,vis,a)<<endl;
    }
return 0;
}