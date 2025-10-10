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
int dp[2024][2024];
int32_t main(){
    Flashyy
    dp[0][0]=1;
    dp[1][0]=5;
    dp[1][1]=10;

    for(int i=2;i<2024;i++){
        int t=i*(i+1)/2 +1;
        dp[i][0]=t*t+dp[i-1][0];
        dp[i][i]=(t+i)*(t+i)+dp[i-1][i-1];
        for(int j=1;j<i;j++){
            dp[i][j]=(t+j)*(t+j)+dp[i-1][j-1]+dp[i-1][j]-dp[i-2][j-1];
        }
    }
    tc
    {
        int n;
        cin>>n;
        int r=0;
        while(1){
            int L=r*(r+1)/2 +1;
            int R=L+r;

            if(n>=L && n<=R)break;
            r++;
        }
        int c=n-(r*(r+1)/2 +1);
        cout<<dp[r][c]<<endl;
    }
return 0;
}