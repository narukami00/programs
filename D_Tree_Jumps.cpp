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

static const int MOD=998244353;
static const int MAXN=300000;

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int> parent(n+1,0);
        for(int i=2;i<=n;i++) cin>>parent[i];

        vector<vector<int>> adj(n+1);
        for(int i=2;i<=n;i++){
            adj[i].pb(parent[i]);
            adj[parent[i]].pb(i);
        }

        vector<int> dist(n+1,-1);
        dist[1]=0;
        queue<int> q;
        q.push(1);

        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(auto &it : adj[v]){
                if(dist[it]<0){
                    dist[it]=dist[v]+1;
                    q.push(it);
                }
            }
        }

        int maxdis=0;
        for(int i=1;i<=n;i++) maxdis=max(maxdis,dist[i]);

        vector<vector<int>> level(maxdis+1);
        for(int i=1;i<=n;i++) level[dist[i]].pb(i);

        vector<int> dp(n+1,0ll);
        dp[1]=1;

        vector<int> sums(maxdis+1,0ll);
        sums[0]=1;

        for(int d=1;d<=maxdis;d++){
            int sum=0;
            for(int it: level[d]){
                int num=sums[d-1];
                if(parent[it]!=0 && parent[it]!=1) num=(num-dp[parent[it]]+MOD)%MOD;
                dp[it]=num;
                sum=(sum+num)%MOD;
            }
            sums[d]=sum;
        }

        int ans=0;
        for(int i=1;i<=n;i++) ans=(ans+dp[i])%MOD;

        cout<<ans<<endl;

    }
return 0;
}