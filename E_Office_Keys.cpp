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
        int n,k,p;
        cin>>n>>k>>p;
        vector<int> a(n),b(k);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<k;i++)cin>>b[i];
        sort(all(a));
        sort(all(b));

        int dp[k+1][n+1];
        const int inf=1e17;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=inf;
            }
        }

        dp[0][0]=0;

        for(int i=0;i<k;i++){
            for(int j=0;j<=n;j++){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
                if(j<n){
                    dp[i+1][j+1]=min(dp[i+1][j+1],max(dp[i][j],abs(a[j]-b[i])+abs(b[i]-p)));
                }
            }
        }

        cout<<dp[k][n]<<endl;

    }
return 0;
}