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
#define sz(x) x.size()
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
vector<int> adj[100005];
bool vis[100005];
bool col[100005];
bool pos=1;
void dfs(int v,bool c){
    if(vis[v]) return;
    vis[v]=1;
    col[v]=c;
    for(auto it:adj[v]){
        if(!vis[it]){
            dfs(it,c^1);
        }else{
            if(c==col[it]) pos=0;
        }
    }
}
int32_t main(){
    Flashyy
    //tc
    {
        int n,m;cin>>n>>m;

        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,0);
            }
        }

        if(pos){
            int cnt[2]={};
            for(int i=0;i<n;i++) ++cnt[col[i]];

            cout<<cnt[0]<<endl;
            for(int i=0;i<n;i++){
                if(col[i]==0){
                    cout<<i+1<<" ";
                }
            }cout<<endl;

            cout<<cnt[1]<<endl;
            for(int i=0;i<n;i++){
                if(col[i]==1){
                    cout<<i+1<<" ";
                }
            }cout<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
return 0;
}