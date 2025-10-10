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
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a(n+2,vector<int>(m+2,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }

        vector<vector<int>>dp1(n+2,vector<int>(m+2,LLONG_MIN));
        vector<vector<int>>dp2(n+2,vector<int>(m+2,LLONG_MIN));
        vector<vector<int>>dp3(n+2,vector<int>(m+2,LLONG_MIN));
        vector<vector<int>>dp4(n+2,vector<int>(m+2,LLONG_MIN));

        dp1[1][1]=a[1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1)continue;
                dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
            }
        }

        dp2[n][m]=a[n][m];
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                if(i==n && j==m)continue;
                dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+a[i][j];
            }
        }

        dp3[n][1]=a[n][1];
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i==n && j==1)continue;
                dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+a[i][j];
            }
        }

        dp4[1][m]=a[1][m];
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(i==1 && j==m)continue;
                dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+a[i][j];
            }
        }

        int ans=0;
        for(int i=2;i<=n-1;i++){
            for(int j=2;j<=m-1;j++){
                int t1=dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1];
                int t2=dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j];
                ans=max({ans,t1,t2});
            }
        }
        cout<<ans<<endl;
    }
return 0;
}