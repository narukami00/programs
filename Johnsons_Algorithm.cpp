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

bool bellman(int n,vector<tuple<int,int,int>>&edges,vector<int>&dist){
    for(int i=1;i<=n;i++){
        edges.pb({0,i,0});
    }
    for(int i=0;i<=n;i++){
        bool cng=0;
        for(auto [u,v,w]:edges){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                cng=1;
                if(i==n)return false;
            }
        }
        if(!cng)return true;
    }
}

void dijkstra(int s,int n, vector<vector<pair<int,int>>>&adj, vector<int>&dist){
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});

    while(!pq.empty()){
        auto [d,u]=pq.top();pq.pop();
        if(d!=dist[u])continue;

        for(auto [v,w]:adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

int32_t main(){
    Flashyy
    int cnt=1;
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<tuple<int,int,int>>edges;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({u,v,w});
        }

        vector<int>h(n+1,0);
        if(!bellman(n,edges,h)){
            cout<<"graph "<<cnt<<" no\n\n";
            cnt++;
            continue;
        }

        for(auto &[u,v,w]:edges){
            if(u==0)continue;
            int nw=w+h[u]-h[v];
            adj[u].pb({v,nw});
        }

        cout<<"graph "<<cnt<<" yes\n\n";
        cnt++;

        for(int i=1;i<=n;i++){
            cout<<h[i]<<" ";
        }
        cout<<h[0]<<endl;
        cout<<endl;

        for(int u=1;u<=n;u++){
            vector<int>dist(n+1,LLONG_MAX);
            dijkstra(u,n,adj,dist);
            for(int v=1;v<=n;v++){
                if(dist[v]>=LLONG_MAX/2)cout<<"#";
                else cout<<dist[v]-h[u]+h[v];
                cout<<(v==n?"\n":" ");
            }
        }cout<<endl;
    }
return 0;
}