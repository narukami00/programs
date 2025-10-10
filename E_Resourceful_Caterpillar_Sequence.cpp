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
        
        vector<vector<int>>adj(n);
        vector<int>adj_no_leaf(n,0);

        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int leaves=0;
        int start=0;

        for(int i=0;i<n;i++)leaves+=(sz(adj[i])==1);

        int ans=leaves*(n-leaves);

        for(int i=0;i<n;i++){
            if(sz(adj[i])>1){
                for(int v:adj[i]){
                    adj_no_leaf[i]+=(sz(adj[v])>1);
                }
                start+=(adj_no_leaf[i]==sz(adj[i]));
            }
        }

        for(int i=0;i<n;i++){
            if(sz(adj[i])>1 && adj_no_leaf[i]!=sz(adj[i])){
                ans+=start*(adj_no_leaf[i]-1);
            }
        }
        cout<<ans<<endl;
    }
return 0;
}