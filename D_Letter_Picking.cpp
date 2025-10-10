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

int comp(char c, char d){
    if(c==d)return 0;
    if(c>d)return 1;
    if(c<d)return -1;
}

int32_t main(){
    Flashyy
    tc
    {
        string s;
        cin>>s;
        int n=sz(s);
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int len=2;len<=n;len+=2){
            for(int l=0;l<n-len+1;l++){
                int r=l+len;
                dp[l][r]=1;
                {
                    int res=-1;

                    if(dp[l+1][r-1]!=0)res=max(res,dp[l+1][r-1]);
                    else res=max(res,comp(s[l],s[r-1]));

                    if(dp[l+2][r]!=0)res=max(res,dp[l+2][r]);
                    else res=max(res,comp(s[l],s[l+1]));
                    
                    dp[l][r]=min(dp[l][r],res);
                }
                {
                    int res=-1;

                    if(dp[l+1][r-1]!=0)res=max(res,dp[l+1][r-1]);
                    else res=max(res,comp(s[r-1],s[l]));

                    if(dp[l][r-2]!=0)res=max(res,dp[l][r-2]);
                    else res=max(res,comp(s[r-1],s[r-2]));
                    
                    dp[l][r]=min(dp[l][r],res);
                }
                }
            }

        if(dp[0][n]==-1)cout<<"Alice\n";
        else if(dp[0][n]==0)cout<<"Draw\n";
        else cout<<"Bob\n";
    }
return 0;
}