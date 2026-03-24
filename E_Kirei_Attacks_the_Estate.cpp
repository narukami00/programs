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
        vector<int>a(n);
        cin>>a;
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<int>mn(n,0);
        vector<int>mx(n,0);

        mn[0]=a[0];
        mx[0]=a[0];
        {
            stack<int>st;
            st.push(0);
            vector<int>vis(n,0);
            vis[0]=1;
            while(!st.empty()){
                int u=st.top();st.pop();
                for(int v:adj[u]){
                    if(!vis[v]){
                        vis[v]=1;
                        st.push(v);
                        mx[v]=max(a[v],a[v]-mn[u]);
                        mn[v]=min(a[v],a[v]-mx[u]);
                    }
                }
            }
        }
        cout<<mx<<endl;
    }
return 0;
}