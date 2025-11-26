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
int32_t main(){
    Flashyy
    //tc
    {
        int n;
        int case_num=1;
        while(cin>>n){
            vector<int>busy(n+1);
            for(int i=1;i<=n;i++)cin>>busy[i];
            int m;
            cin>>m;
            vector<tuple<int,int,int>>edges;
            vector<vector<int>>adj(n+1);
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                int w=(busy[v]-busy[u]);
                w=w*w*w;
                edges.pb({u,v,w});
                adj[u].pb(v);
            }

            vector<int>dist(n+1,INF);
            vector<int>par(n+1,-1);
            dist[1]=0;

            for(int i=1;i<=n-1;i++){
                for(auto [u,v,w]:edges){
                    if(dist[u]!=INF && dist[v]>dist[u]+w){
                        dist[v]=dist[u]+w;
                        par[v]=u;
                    }
                }
            }

            vector<bool>neg(n+1,false);
            for(auto [u,v,w]:edges){
                if(dist[u]!=INF && dist[v]>dist[u]+w){
                    neg[v]=true;
                }
            }

            queue<int>q;
            for(int i=1;i<=n;i++){
                if(neg[i]){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto v:adj[u]){
                    if(!neg[v]){
                        neg[v]=true;
                        q.push(v);
                    }
                }
            }

            int Q;cin>>Q;
            cout<<"Set #"<<case_num++<<endl;
            while(Q--){
                int x;
                cin>>x;
                if(x<1 || x>n || dist[x]==INF || dist[x]<3 || neg[x]){
                    cout<<"?"<<endl;
                }
                else{
                    cout<<dist[x]<<endl;
                }
            }
        }
    }
    return 0;
}