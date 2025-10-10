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
        vector<vector<int>>adj(n),cycles;
        vector<int>indeg(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            x--;
            adj[i].pb(x);
            indeg[x]++;
        }
        vector<int>cost(n);
        cin>>cost;

        vector<bool>vis(n),back(n);
        vector<int>st;

        vector<int>ans;
        {
            queue<int>q;
            for(int i=0;i<n;i++){
                if(indeg[i]==0){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int u=q.front();q.pop();
                vis[u]=1;
                ans.pb(u+1);
                for(int v:adj[u]){
                    if(--indeg[v]==0){
                        q.push(v);
                    }
                }
            }
        }

        function<void(int)>dfs=[&](int u){
            vis[u]=back[u]=1;
            st.pb(u);
            for(int v:adj[u]){
                if(!vis[v]){
                    dfs(v);
                }else if(back[v]){
                    auto it=find(all(st),v);
                    cycles.pb({it,st.end()});
                }
            }
            st.pop_back();
            back[u]=0;
        };

        for(int i=0;i<n;i++)if(!vis[i])dfs(i);

        for(auto& cyc:cycles){
            int mn=min_element(all(cyc),[&](int a,int b){return cost[a]<cost[b];})-cyc.begin();
            for(int k=1;k<=sz(cyc);k++){
                int indx=(mn+k)%sz(cyc);
                ans.pb(cyc[indx]+1);
            }
        }

        cout<<ans<<endl;
    }
return 0;
}