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

const int N=1e5;
vector<int>adj[N+1];
int dp[N+1][2];

void dfs(int u){
    dp[u][0]=0;
    dp[u][1]=1;
    int best=0;
    for(int v:adj[u]){
        dfs(v);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        best=max(best,dp[v][1]);
    }
    dp[u][1]+=best;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cin>>n;
        for(int i=2;i<=n;i++){
            int x;cin>>x;
            adj[x].pb(i);
        }
        dfs(1);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
return 0;
}