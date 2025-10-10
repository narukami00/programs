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
        vector<vector<int>>edges(n+1);
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            edges[x].pb(i);
        }
        vector<int>size(n+1);
        int ans=0;
        function<void(int,int)>dfs=[&](int v,int p){
            vector<int>a;
            size[v]=1;
            for(int u:edges[v]){
                if(u==p)continue;
                dfs(u,v);
                size[v]+=size[u];
                a.pb(size[u]);
            }
            vector<int>dp(size[v]);
            int cs=0;
            for(int x:a){
                for(int i=cs+x;i>=0;i--){
                    for(int pr=min(cs,i);pr>=max(0ll,i-x);pr--){
                        int j=i-pr;
                        dp[i]=max(dp[i],dp[pr]+j*(cs-pr)+pr*(x-j));
                    }
                }
                cs+=x;
            }
            ans+=*max_element(all(dp));
            dp.clear();
            a.clear();
        };
        dfs(1,0);
        cout<<ans<<endl;
    }
return 0;
}