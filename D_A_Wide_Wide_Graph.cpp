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
        int n;
        cin>>n;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        auto bfs=[&](int src,vector<int>&dis){
            queue<int>q;
            dis[src]=0;
            q.push(src);
            while(!q.empty()){
                int u=q.front();q.pop();
                for(auto v:adj[u]){
                    if(dis[v]==-1){
                        dis[v]=dis[u]+1;
                        q.push(v);
                    }
                }
            }
        };

        vector<int>dis1(n+1,-1);
        bfs(1,dis1);

        int a=1;
        for(int i=1;i<=n;i++)if(dis1[i]>dis1[a])a=i;

        vector<int>disa(n+1,-1);
        bfs(a,disa);

        int b=1;
        for(int i=1;i<=n;i++)if(disa[i]>disa[b])b=i;

        vector<int>disb(n+1,-1);
        bfs(b,disb);

        vector<int>ecc(n+1);
        int mx=0;
        for(int i=1;i<=n;i++){
            ecc[i]=max(disa[i],disb[i]);
            mx=max(mx,ecc[i]);
        }

        vector<int>freq(mx+2,0);
        for(int i=1;i<=n;i++)freq[ecc[i]]++;

        vector<int>pre(mx+2,0);
        pre[0]=freq[0];
        for(int i=1;i<=mx+1;i++)pre[i]=pre[i-1]+(i<sz(freq)?freq[i]:0);

        for(int i=1;i<=n;i++){
            int x=(i-1<=mx+1)?pre[min(i-1,mx+1)]:n;
            int y=(x<n)?1:0;
            cout<<x+y<<sp;
        }
        cout<<endl;
    }
return 0;
}