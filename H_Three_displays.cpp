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

int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cin>>n;
        vector<int>a(n);for(auto &it:a)cin>>it;
        vector<int>b(n);for(auto &it:b)cin>>it;

        int dp[n+1][3];
        int inf=1e17;
        int ans=inf;

        for(int i=0;i<n;i++){
            dp[i][0]=b[i];
            for(int j=1;j<3;j++){
                dp[i][j]=inf;
                for(int k=0;k<i;k++){
                    if(a[k]<a[i]){
                        dp[i][j]=min(dp[i][j],dp[k][j-1]+b[i]);
                    }
                }
            }
            ans=min(ans,dp[i][2]);
        }
        if(ans==inf)ans=-1;
        cout<<ans<<endl;
    }
return 0;
}