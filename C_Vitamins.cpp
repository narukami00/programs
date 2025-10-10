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
        int dp[n+1][8];
        int inf =1e17;
        for(int i=0;i<=n;i++){
            for(int j=0;j<8;j++){
                dp[i][j]=inf;
            }
        }
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            int cost;
            string s;
            cin>>cost>>s;
            int mask=0;
            for(int pos=0;pos<3;pos++){
                char c='C'-pos;
                bool have=0;
                for(char d:s){
                    if(c==d)have=1;
                }
                if(have){
                    mask+=(1<<pos);
                }
            }
            for(int m=0;m<8;m++){
                dp[i+1][m]=min(dp[i+1][m],dp[i][m]);
                dp[i+1][m|mask]=min(dp[i+1][m|mask],dp[i][m]+cost);
            }
        }
        int ans=dp[n][7];
        if(ans==inf)ans=-1;
        cout<<ans<<endl;
    }
return 0;
}