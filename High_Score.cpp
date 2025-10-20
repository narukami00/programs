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
    //tc
    {
        int n,m;
        cin>>n>>m;
        vector<tuple<int,int,int>>edges;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }

        vector<int>dist(n+1,LLONG_MIN);
        dist[1]=0;

        for(int i=0;i<n-1;i++){
            for(auto [u,v,w]:edges){
                if(dist[u]!=LLONG_MIN && dist[v]<dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }

        vector<int> affect(n+1,0); 
        for(auto [u,v,w]:edges){
            if(dist[u]!=LLONG_MIN && dist[v]<dist[u]+w){
                affect[v]=1;
            }
        }

        queue<int>q;
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(affect[i]){
                q.push(i);
                vis[i]=1;
            }
        }

        vector<vector<int>>adj(n+1);
        for(auto [u,v,w]:edges){
            adj[u].pb(v);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }

        if(vis[n])cout<<-1<<endl;
        else cout<<dist[n]<<endl;
    }
return 0;
}