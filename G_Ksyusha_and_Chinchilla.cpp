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
        int n;
        cin>>n;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].pb({v,i});
            adj[v].pb({u,i});
        }

        if(n%3!=0){
            cout<<-1<<endl;
            continue;
        }

        vector<int>cut,size(n);
        auto dfs=[&](auto self,int u,int p)->void{
            size[u]=1;
            for(auto [v,i]:adj[u]){
                if(v==p)continue;
                self(self,v,u);
                if(size[v]%3==0)cut.pb(i);
                else size[u]+=size[v];
            }
        };

        dfs(dfs,0,-1);
        int need=n/3-1;
        if(sz(cut)!=need){
            cout<<-1<<endl;
            continue;
        }

        cout<<need<<endl;
        cout<<cut<<endl;
    }
return 0;
}