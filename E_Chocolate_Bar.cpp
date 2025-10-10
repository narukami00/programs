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

const int inf=LLONG_MAX;
int dp[31][31][51];

int32_t main(){
    Flashyy
    for(int i=1;i<=30;i++){
        for(int j=1;j<=30;j++){
            int cells=min(i*j,50ll);
            for(int k=0;k<=cells;k++){
                if(k==0 || k==i*j)dp[i][j][k]=0;
                else{
                    dp[i][j][k]=inf;
                    for(int x=1;x<i;x++){
                        int left=x*j;
                        for(int used=max(0ll,k-(i-x)*j);used<=min(k,left);used++){
                            dp[i][j][k]=min(dp[i][j][k],dp[x][j][used]+dp[i-x][j][k-used]+j*j);
                        }
                    }
                    for(int y=1;y<j;y++){
                        int top=i*y;
                        for(int used=max(0ll,k-i*(j-y));used<=min(k,top);used++){
                            dp[i][j][k]=min(dp[i][j][k],dp[i][y][used]+dp[i][j-y][k-used]+i*i);
                        }
                    }
                }
            }
        }
    }
    tc
    {
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp[n][m][k]<<endl;
    }
return 0;
}