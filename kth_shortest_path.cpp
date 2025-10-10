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

const int N=128;
const int K=3;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<pair<int,int>>adj[N];
vector<int>dist[N];

void dijkstra(int src,int des){
    int i,curr_dis;
    int curr_node,curr_cost;

    for(int i=0;i<N;i++){
        dist[i].clear();
    }

    while(!pq.empty())pq.pop();

    pq.push({0,src});
    while(!pq.empty()){
        curr_cost=pq.top().first;
        curr_node=pq.top().second;
        pq.pop();

        if(dist[curr_node].size()==0 || dist[curr_node].back()!=curr_cost){
            dist[curr_node].pb(curr_cost);
        }

        if(dist[curr_node].size()>K)continue;

        for(int i=0;i<adj[curr_node].size();i++){
            if(dist[adj[curr_node][i].first].size()==K){
                continue;
            }
            pq.push({curr_cost+adj[curr_node][i].second,adj[curr_node][i].first});
        }
    }

    if(dist[des].size()<K){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[des][1]<<endl;
    }
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,m;
        cin>>n>>m;

        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        int src,des;
        cin>>src>>des;

        dijkstra(src,des);

    }
return 0;
}