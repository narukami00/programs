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

const int mod=1e9+7;

void dfs1(int node, vector<vector<int>>&adj, vector<int>&back){
    for(auto it:adj[node]){
        back[node]=(back[node]+1)%mod;
        dfs1(it,adj,back);
        back[node]=(back[node]+back[it]+1)%mod;
    }
}

void dfs2(int node, vector<vector<int>>&adj, vector<int>&back, vector<int>&ans){
    for(auto it:adj[node]){
        ans[it]=(ans[node]+back[it]+1)%mod;
        dfs2(it,adj,back,ans);
    }
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            if(l!=0)adj[i].pb(--l);
            if(r!=0)adj[i].pb(--r);
        }

        // for(int i=0;i<n;i++){
        //     for(auto it:adj[i])cout<<it<<" ";
        //     cout<<endl;
        // }

        vector<int>back(n,0);
        dfs1(0,adj,back);

        //cout<<back<<endl;

        vector<int>ans(n,0);
        ans[0]=back[0];
        dfs2(0,adj,back,ans);

        for(int i=0;i<n;i++){
            if(ans[i]+1==mod)cout<<0<<sp;
            else cout<<ans[i]+1<<sp;
        }
        cout<<endl;
    }
return 0;
}