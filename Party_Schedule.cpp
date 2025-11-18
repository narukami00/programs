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
    while(true)
    {
        int b,n;
        cin>>b>>n;
        if(b==0 && n==0)break;
        vector<int>cost(n),fun(n);
        for(int i=0;i<n;i++)cin>>cost[i]>>fun[i];
        vector<vector<int>>dp(n+1,vector<int>(b+1,0));

        for(int i=1;i<=n;i++){
            for(int j=0;j<=b;j++){
                int notTake=dp[i-1][j];
                int take=-1e9;
                if(j-cost[i-1]>=0)take=fun[i-1]+dp[i-1][j-cost[i-1]];
                dp[i][j]=max(take,notTake);
            }
        }

        int mxfun=dp[n][b];
        int mncost=0;
        for(int j=0;j<=b;j++){
            if(dp[n][j]==mxfun){
                mncost=j;
                break;
            }
        }

        cout<<mncost<<sp<<mxfun<<endl;
    }
return 0;
}