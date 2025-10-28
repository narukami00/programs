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
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<tuple<int,int,int>>edges;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({u,v,w});
        }

        bool neg_cyc=0;
        int mn_dis=LLONG_MAX;

        for(int u=1;u<=n;u++){
            vector<int>dist(n+1,LLONG_MAX);
            dist[u]=0;
            for(int i=1;i<n;i++){
                neg_cyc=0;
                for(auto &[u,v,w]:edges){
                    if(dist[u]!=LLONG_MAX && dist[v]>dist[u]+w){
                        dist[v]=dist[u]+w;
                        neg_cyc=1;
                    }
                }if(!neg_cyc)break;
            }

            if(neg_cyc)break;

            for(int v=1;v<=n;v++){
                if(v==u)continue;
                if(dist[v]!=LLONG_MAX)mn_dis=min(mn_dis,dist[v]);
            }
        }

        if(neg_cyc)cout<<"-inf\n";
        else cout<<mn_dis<<endl;
    }
return 0;
}