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
int curx,grp;
int dfs(int u,int par,vector<vector<int>>&adj){
    int sum=1;
    for(int v:adj[u]){
        if(v==par)continue;
        sum+=dfs(v,u,adj);
    }
    if(sum>=curx){
        grp++;
        return 0;
    }
    return sum;
}

bool pos(int n,int k, vector<vector<int>>&adj,int x){
    grp=0;
    curx=x;
    int rem=dfs(0,-1,adj);
    if(rem>=x)grp++;
    return grp>=k+1;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int l=1,r=n/(k+1),ans=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pos(n,k,adj,mid)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        cout<<ans<<endl;
    }
return 0;
}