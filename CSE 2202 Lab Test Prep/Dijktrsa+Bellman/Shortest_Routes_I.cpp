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

        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
        }

        vector<int>dist(n+1,LLONG_MAX);
        dist[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dis=it.f;
            int node=it.s;

            if(dis!=dist[node])continue;

            for(auto &v:adj[node]){
                if(dist[v.f]>dis+v.s){
                    dist[v.f]=dis+v.s;
                    pq.push({dist[v.f],v.f});
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<dist[i]<<sp;
        }cout<<endl;
    }
return 0;
}