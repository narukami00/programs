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
            edges.pb({w,u,v});
        }
        sort(all(edges));
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
        DSU dsu(n+1);
        int first_way_cost=0;
        vector<tuple<int,int,int>>used_edges;
        for(auto &[w,u,v]:edges){
            if(dsu.unite(u,v)){
                first_way_cost+=w;
                used_edges.pb({w,u,v});
            }
        }
        if(used_edges.size()<n-1){
            cout<<"Case #"<<tt<<" : No way\n";
            continue;
        }
        int second_way_cost=LLONG_MAX;
        for(auto &[w,u,v]:used_edges){
            dsu.init(n+1);
            int curr_cost=0;
            int cnt=0;
            for(auto &[w2,u2,v2]:edges){
                if(u2==u && v2==v && w2==w)continue;
                if(dsu.unite(u2,v2)){
                    curr_cost+=w2;
                    cnt++;
                }
            }
            if(cnt==n-1)second_way_cost=min(second_way_cost,curr_cost);
        }
        if(second_way_cost==LLONG_MAX){
            cout<<"Case #"<<tt<<" : No second way\n";
        }
        else{
            cout<<"Case #"<<tt<<" : "<<second_way_cost<<endl;
        }
    }
return 0;
}