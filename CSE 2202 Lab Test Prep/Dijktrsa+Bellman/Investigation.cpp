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
const int MOD=1e9+7;
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
        vector<int>ways(n+1,0);
        vector<int>mn_f(n+1,LLONG_MAX);
        vector<int>mx_f(n+1,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        dist[1]=0;
        ways[1]=1;
        mn_f[1]=0;
        pq.push({0,1});

        while(!pq.empty()){
            auto [dis,node]=pq.top();
            pq.pop();

            if(dis!=dist[node])continue;

            for(auto [v,w]:adj[node]){
                if(dist[v]>dis+w){
                    dist[v]=dis+w;
                    ways[v]=ways[node];
                    mn_f[v]=mn_f[node]+1;
                    mx_f[v]=mx_f[node]+1;
                    pq.push({dist[v],v});
                }else if(dist[v]==dis+w){
                    ways[v]=(ways[v]+ways[node])%MOD;
                    mn_f[v]=min(mn_f[v],mn_f[node]+1);
                    mx_f[v]=max(mx_f[v],mx_f[node]+1);
                }
            }
        }

        cout<<dist[n]<<sp<<ways[n]<<sp<<mn_f[n]<<sp<<mx_f[n]<<endl;
    }
return 0;
}