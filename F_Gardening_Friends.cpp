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

vector<int>bfs(int src,vector<vector<int>>&adj){
    int n=sz(adj);
    vector<int>dis(n,-1);
    queue<int>q;
    dis[src]=0;
    q.push(src);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:adj[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,k,c;
        cin>>n>>k>>c;
        vector<vector<int>>adj(n);;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        auto d1=bfs(0,adj);
        int a=max_element(all(d1))-d1.begin();
        auto da=bfs(a,adj);
        int b=max_element(all(da))-da.begin();
        auto db=bfs(b,adj);

        int ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            int j=max(da[i],db[i]);
            int prof=k*j-c*d1[i];
            ans=max(ans,prof);
        }

        cout<<ans<<endl;
    }
return 0;
}