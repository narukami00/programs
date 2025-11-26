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
        vector<vector<int>>graph(n+1),regraph(n+1);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({u,v,w});
            graph[u].pb(v);
            regraph[v].pb(u);
        }

        for(int i=1;i<=n;i++)edges.pb({0,i,0});
        vector<int>h(n+1,LLONG_MAX);
        h[0]=0;

        for(int i=0;i<n;i++){
            bool cng =0;
            for(auto &[u,v,w]:edges){
                if(h[u]!=LLONG_MAX && h[v]>h[u]+w){
                    h[v]=h[u]+w;
                    cng=1;
                }
            }
            if(!cng)break;
        }

        vector<int>neg;
        for(auto &[u,v,w]:edges){
            if(h[u]!=LLONG_MAX && h[v]>h[u]+w){
                if(v>=1 && v<=n)neg.pb(v);
            }
        }

        queue<int>q;
        vector<bool>aff(n+1,0);
        for(int x:neg){
            if(!aff[x]){
                aff[x]=1;
                q.push(x);
            }
        }

        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:graph[u]){
                if(!aff[v]){
                    aff[v]=1;
                    q.push(v);
                }
            }
        }

        for(int i=1;i<=n;i++)if(aff[i])h[i]=LLONG_MIN;

        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &[u,v,w]:edges){
            if(u==0 || h[u]==LLONG_MAX || h[v]==LLONG_MAX || h[u]==LLONG_MIN || h[v]==LLONG_MIN)continue;
            adj[u].pb({v,w+h[u]-h[v]});
        }

        vector<bool>to_neg(n+1,0),from_neg(n+1,0);

        for(int i=1;i<=n;i++)from_neg[i]=aff[i];

        queue<int>qq;
        for(int x:neg){
            if(!to_neg[x]){
                to_neg[x]=1;
                qq.push(x);
            }
        }

        while(!qq.empty()){
            int u=qq.front();qq.pop();
            for(int v:regraph[u]){
                if(!to_neg[v]){
                    to_neg[v]=1;
                    qq.push(v);
                }
            }
        }

        for(int u=1;u<=n;u++){
            vector<int>dist(n+1,LLONG_MAX);
            if(h[u]!=LLONG_MAX && h[u]!=LLONG_MIN){
                dist[u]=0;
                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
                pq.push({0,u});
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
            }

            for(int v=1;v<=n;v++){
                if(to_neg[u] && from_neg[v]){
                    cout<<"-INF";
                }else if(dist[v]>=LLONG_MAX/2 || h[u]>=LLONG_MAX/2 || h[v]>=LLONG_MAX/2){
                    cout<<"INF";
                }else{
                    cout<<dist[v]-h[u]+h[v];
                }
                if(v<n)cout<<sp;
            }cout<<endl;
        }

    }
return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define double long double
// #define endl '\n'
// #define no cout<<"NO\n"
// #define yes cout<<"YES\n"
// #define sp " "
// #define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
// #define sz(x) x.size()
// #define f first
// #define s second
// #define pb push_back
// #define eb emplace_back

// template <typename T>
// istream &operator>>(istream &istream, vector<T> &v)
// {
//     for (auto &it : v)
//         cin >> it;
//     return istream;
// }
// template <typename T>
// ostream &operator<<(ostream &ostream, const vector<T> &c)
// {
//     for (auto &it : c)
//         cout << it << " ";
//     return ostream;
// }

// int32_t main(){
//     Flashyy
//     //tc
//     {
//         int n,m;
//         cin>>n>>m;
//         vector<vector<int>>dist(n+1,vector<int>(n+1,LLONG_MAX));
//         for(int i=1;i<=n;i++)dist[i][i]=0;

//         for(int i=0;i<m;i++){
//             int u,v,w;
//             cin>>u>>v>>w;
//             dist[u][v]=min(dist[u][v],w);
//         }

//         for(int k=1;k<=n;k++){
//             for(int i=1;i<=n;i++){
//                 if(dist[i][k]==LLONG_MAX)continue;
//                 for(int j=1;j<=n;j++){
//                     if(dist[k][j]==LLONG_MAX)continue;
//                     if(dist[i][j]>dist[i][k]+dist[k][j]){
//                         dist[i][j]=dist[i][k]+dist[k][j];
//                     }
//                 }
//             }
//         }

//         for(int k=1;k<=n;k++){
//             if(dist[k][k]<0){
//                 for(int i=1;i<=n;i++){
//                     for(int j=1;j<=n;j++){
//                         if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
//                             dist[i][j]=LLONG_MIN;
//                         }
//                     }
//                 }
//             }
//         }

//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=n;j++){
//                 if(dist[i][j]==LLONG_MAX)cout<<"INF";
//                 else if(dist[i][j]==LLONG_MIN)cout<<"-INF";
//                 else cout<<dist[i][j];
//                 if(j<n)cout<<sp;
//             }
//             cout<<endl;
//         }

//     }
// return 0;
// }