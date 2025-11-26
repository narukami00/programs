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
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({u,v,w});
        }
        vector<int>dist(n+1,0);
        vector<int>par(n+1,-1);
        int cng=-1;
        for(int i=0;i<n;i++){
            cng=-1;
            for(auto [u,v,w]:edges){
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                    par[v]=u;
                    cng=v;
                }
            }
        }
        if(cng==-1)no;
        else{
            yes;
            for(int i=0;i<n;i++)cng=par[cng];
            vector<int>cyc;
            int cur=cng;
            do{
                cyc.pb(cur);
                cur=par[cur];
            }while(cur!=cng);
            cyc.pb(cng);
            reverse(all(cyc));
            cout<<cyc<<endl;
        }
    }
return 0;
}