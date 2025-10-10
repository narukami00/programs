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
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        auto dij=[&](int u)->vector<int>{
            vector<int>dis(n,LLONG_MAX);
            vector<bool>vis(n);

            priority_queue<pair<int,int>>q;
            q.push({0,u});
            while(sz(q)){
                auto [d,c]=q.top();
                d=-d;
                q.pop();

                if(vis[c])continue;
                vis[c]=1;
                dis[c]=d;

                for(auto [x,w]:adj[c]){
                    if(vis[x])continue;

                    q.push({-max(d,w),x});
                }
            }
            return dis;
        };

        int ans=LLONG_MAX;
        vector<int>dis1=dij(0),dis2=dij(n-1);

        for(int u=0;u<n;u++){
            for(auto [v,w]:adj[u]){
                ans=min(ans,{max({dis1[u],dis2[u],w})+w});
            }
        }

        cout<<ans<<endl;
    }
return 0;
}