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
        int n,m;
        cin>>n>>m;
        vector<int> b(n+1);
        for(int i=1;i<=n;i++)cin>>b[i];

        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<m;i++){
            int s,t,w;
            cin>>s>>t>>w;
            adj[t].pb({s,w});
        }

        auto pos=[&](int r){
            vector<int>dp(n+1,LLONG_MIN);
            dp[1]=min(r,b[1]);
            for(int to=2;to<=n;to++){
                for(auto &[from,cost]:adj[to]){
                    if(cost<=dp[from]){
                        dp[to]=max(dp[to],min(b[to]+dp[from],r));
                    }
                }
            }
            return (dp[n]>=0);
        };

        int l=0,r=1e9+7,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(mid)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }

        if(!pos(ans))cout<<-1<<endl;
        else cout<<ans<<endl;
    }
return 0;
}