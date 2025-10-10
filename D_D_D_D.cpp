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
const int INF=2e9+1;
int32_t main(){
    Flashyy
    tc
    {
        int n,m,l;
        cin>>n>>m>>l;
        int sum=0,min_odd=INF;
        vector<int>a(l);
        for(int i=0;i<l;i++){
            cin>>a[i];
            sum+=a[i];
            if(a[i]%2){
                min_odd=min(min_odd,a[i]);
            }
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<array<int,2>>dis(n,{INF,INF});
        queue<pair<int,int>>q;
        q.push({0,0});
        dis[0][0]=0;
        while(!q.empty()){
            auto [u,p]=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(dis[v][!p]>dis[u][p]+1){
                    dis[v][!p]=dis[u][p]+1;
                    q.push({v,!p});
                }
            }
        }
        for(int i=0;i<n;i++){
            bool f=0;
            for(int p=0;p<2;p++){
                int s=sum-(p==sum%2?0:min_odd);
                if(dis[i][p]<=s){
                    f=1;
                }
            }
            cout<<f;
        }
        cout<<endl;
    }
return 0;
}