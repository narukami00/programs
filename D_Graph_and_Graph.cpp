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
        int n,s1,s2;
        cin>>n>>s1>>s2;
        s1--,s2--;

        vector<vector<int>>adj1(n),adj2(n);
        vector<bool>good(n,0);
        set<pair<int,int>>edges;

        int m1;cin>>m1;
        for(int i=0;i<m1;i++){
            int v,u;
            cin>>v>>u;
            v--,u--;
            if(v>u)swap(v,u);
            adj1[v].pb(u);
            adj1[u].pb(v);
            edges.insert({v,u});
        }

        int m2;cin>>m2;
        for(int i=0;i<m2;i++){
            int v,u;
            cin>>v>>u;
            v--,u--;
            if(v>u)swap(v,u);
            if(edges.find({v,u})!=edges.end()){
                good[v]=1,good[u]=1;
            }
            adj2[v].pb(u);
            adj2[u].pb(v);
        }

        vector<vector<int>>adj(n,vector<int>(n,LLONG_MAX));
        adj[s1][s2]=0;
        set<tuple<int,int,int>>st;
        st.insert({0,s1,s2});
        
        while(!st.empty()){
            auto [x,v,u] =*st.begin();
            st.erase(st.begin());
            for(auto w1:adj1[v]){
                for(auto w2:adj2[u]){
                    int w=abs(w1-w2);
                    if(adj[w1][w2]>adj[v][u]+w){
                        st.erase({adj[w1][w2],w1,w2});
                        adj[w1][w2]=adj[v][u]+w;
                        st.insert({adj[w1][w2],w1,w2});
                    }
                }
            }
        }

        int ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(!good[i])continue;
            ans=min(ans,adj[i][i]);
        }

        if(ans==LLONG_MAX)ans=-1;

        cout<<ans<<endl;
    }
return 0;
}