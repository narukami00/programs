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
        int m;
        cin>>m;
        vector<int>coins(m+1);
        int S=0;
        for(int i=1;i<=m;i++){
            cin>>coins[i];
            S+=coins[i];
        }

        int half=S/2;
        vector<vector<char>>dp(m+1,vector<char>(S+1,0));
        dp[0][0]=1;

        for(int i=1;i<=m;i++){
            for(int j=0;j<=S;j++){
                dp[i][j]=dp[i-1][j];
                if(j-coins[i]>=0 && dp[i-1][j-coins[i]]){
                    dp[i][j]=1;
                }
            }   
        }

        int ans=0;
        for(int j=half;j>=0;j--){
            if(dp[m][j]){
                ans=j;
                break;
            }
        }

        cout<<S-2*ans<<endl;

        vector<int>res;
        int cur_sum=ans;

        for(int i=m;i>=1;i--){
            if(!dp[i-1][cur_sum]){
                res.pb(coins[i]);
                cur_sum-=coins[i];
            }
        }
        cout<<res<<endl; //only one person's coins
    }
return 0;
}