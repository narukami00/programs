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
        vector<set<int>>adj(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        vector<tuple<int,int,int>>ans;
        for(int i=1;i<=n;i++){
            while(sz(adj[i])>=2){
                int u=*adj[i].begin();
                adj[i].erase(adj[i].begin());

                int v=*adj[i].begin();
                adj[i].erase(adj[i].begin());

                adj[u].erase(i);
                adj[v].erase(i);

                ans.pb({i,u,v});

                if(adj[u].count(v)){
                    adj[u].erase(v);
                    adj[v].erase(u);
                }else{
                    adj[u].insert(v);
                    adj[v].insert(u);
                }
            }
        }

        vector<int>ones;
        vector<pair<int,int>>edges;

        for(int i=1;i<=n;i++){
            if(adj[i].empty()){
                ones.pb(i);
            }else if(*adj[i].begin()>i){
                edges.pb({i,*adj[i].begin()});
            }
        }

        if(!edges.empty()){
            auto [x,y]=edges.back();
            edges.pop_back();

            for(int u:ones){
                ans.pb({x,y,u});
                y=u;
            }

            for(auto [u,v]:edges){
                ans.pb({y,u,v});
            }
        }

        cout<<sz(ans)<<endl;
        for(auto [x,y,z]:ans)cout<<x<<sp<<y<<sp<<z<<endl;
    }
return 0;
}