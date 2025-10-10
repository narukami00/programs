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

const int M = 998244353;
 
int powm(int x, int n) {
    x %= M;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    int p = powm(x * x, n / 2);
    if (n % 2)
        return p * x % M;
    else
        return p;
}
 
int mod_div(int p, int q) { return p % M * powm(q, M - 2) % M; }
 
vector<int> fact, ifact;
void factCompute(int N = 1e6) {
    fact.assign(N + 1, 1);
    ifact.assign(N + 1, 1);
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % M;
    ifact[N] = mod_div(1, fact[N]);
    for (int i = N - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % M;
}


int32_t main(){
    Flashyy
    factCompute(1e6);
    tc
    {
        int n=0;
        vector<int>freq(27,0);
        for(int i=1;i<=26;i++){cin>>freq[i];n+=freq[i];}

        vector<vector<int>> dp(27,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=26;i++){
            for(int j=0;j<=n/2;j++){
                dp[i][j]=dp[i-1][j];
                if(freq[i]>0 && j-freq[i]>=0){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-freq[i]])%M;
                }
            }
        }
        int ans=dp[26][n/2]*fact[n/2]%M * fact[(n+1)/2]%M;

        for(int i=1;i<=26;i++){
            ans=mod_div(ans,fact[freq[i]]);
        }

        cout<<ans<<endl;
    }
return 0;
}