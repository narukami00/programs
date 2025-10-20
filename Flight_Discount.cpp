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

        vector<vector<int>>dist(n+1,vector<int>(2,LLONG_MAX));
        dist[1][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,1,0});

        while(!pq.empty()){
            auto [d,u,used]=pq.top();
            pq.pop();
            if(d!=dist[u][used])continue;
            for(auto [v,w]:adj[u]){
                if(used==0){
                    if(dist[v][0]>d+w){
                        dist[v][0]=d+w;
                        pq.push({dist[v][0],v,0});
                    }
                    if(dist[v][1]>d+w/2){
                        dist[v][1]=d+w/2;
                        pq.push({dist[v][1],v,1});
                    }
                }else if(used==1){
                    if(dist[v][1]>d+w){
                        dist[v][1]=d+w;
                        pq.push({dist[v][1],v,1});
                    }
                }
            }
        }
        cout<<dist[n][1]<<endl;
    }
return 0;
}