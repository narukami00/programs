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
        int n,m,q;
        cin>>n>>m>>q;
        vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
        for(int i=1;i<=n;i++)dist[i][i]=0;

        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            dist[u][v]=min(dist[u][v],w);
            dist[v][u]=min(dist[v][u],w);
        }
        
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        while(q--){
            int u,v;
            cin>>u>>v;
            if(dist[u][v]==INF)cout<<-1<<endl;
            else cout<<dist[u][v]<<endl;
        }
    }
return 0;
}