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
        int n,k;
        cin>>n>>k;
        vector<int>marked(k);
        for(int i=0;i<k;i++){
            cin>>marked[i];
            marked[i]--;
        }

        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        auto bfs=[&](int src,vector<int>&dis){
            dis.assign(n,-1);
            queue<int>q;
            dis[src]=0;
            q.push(src);
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int v:adj[u]){
                    if(dis[v]<0){
                        dis[v]=dis[u]+1;
                        q.push(v);
                    }
                }
            }
        };

        vector<int>dis;
        bfs(marked[0],dis);
        int a=marked[0];
        for(int x:marked)if(dis[x]>dis[a])a=x;

        vector<int>disa;
        bfs(a,disa);
        int b=a;
        for(int x:marked)if(disa[x]>disa[b])b=x;

        cout<<(disa[b]+1)/2<<endl;
    }
return 0;
}