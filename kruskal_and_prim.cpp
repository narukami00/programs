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

struct DSU{
    int n;
    vector<int>p,r;
    DSU(int n=0){init(n);}
    void init(int n_){n=n_;p.resize(n);r.assign(n+1,0);for(int i=0;i<=n;i++)p[i]=i;}
    int find(int a){return p[a]==a?a:p[a]=find(p[a]);}
    bool unite(int a,int b){
        a=find(a);b=find(b);
        if(a==b)return false;
        if(r[a]<r[b])swap(a,b);
        p[b]=a;
        if(r[a]==r[b])r[a]++;
        return true;
    }
};

int kruskal(int n,vector<tuple<int,int,int>>&edges){
    sort(all(edges));
    DSU dsu(n);
    int cost=0;
    for(auto &[w,u,v]:edges){
        if(dsu.unite(u,v)){
            cost+=w;
        }
    }
    return cost;
}

int prim(int n,vector<vector<pair<int,int>>>&adj){
    vector<bool>vis(n+1,0);
    vector<int>dist(n+1,LLONG_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    int cost=0;
    int visi=0;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [w,u]=pq.top();
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        cost+=w;
        visi++;
        for(auto &[v,wt]:adj[u]){
            if(!vis[v] && wt<dist[v]){
                dist[v]=wt;
                pq.push({wt,v});
            }
        }
    }
    if(visi!=n)return -1;
    return cost;
}

int32_t main(){
    Flashyy
    //tc
    {

    }
return 0;
}