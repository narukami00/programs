#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
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

int mod=998244353;

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int> dp(4, 0);
        dp[0]=1;
        while(n--){
            int x;
            cin>>x;
            if(x==2) dp[x]=(dp[x]+dp[x])%mod;
            dp[x]=(dp[x]+dp[x-1])%mod;
        }
        cout<<dp[3]<<endl;
    }
return 0;
}