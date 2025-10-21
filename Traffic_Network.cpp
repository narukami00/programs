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

const int INF=1e15;
vector<int>dijkstra(int n,int src,vector<vector<pair<int,int>>>&adj){
    vector<int>dist(n+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto [dis,node]=pq.top();
        pq.pop();
        if(dis!=dist[node])continue;
        for(auto [v,w]:adj[node]){
            if(dist[v]>dis+w){
                dist[v]=dis+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,m,k,s,t;
        cin>>n>>m>>k>>s>>t;
        vector<vector<pair<int,int>>>adj(n+1),rev(n+1);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            rev[v].pb({u,w});
        }

        auto dis_s=dijkstra(n,s,adj);
        auto dis_t=dijkstra(n,t,rev);

        int ans=dis_s[t];
        for(int i=0;i<k;i++){
            int u,v,w;
            cin>>u>>v>>w;

            ans=min(ans,dis_s[u]+w+dis_t[v]);
            ans=min(ans,dis_s[v]+w+dis_t[u]);
        }

        if(ans>=INF/2)cout<<-1<<endl;
        else cout<<ans<<endl;   
    }
return 0;
}