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

const int MOD= 998244353;
int add(int x,int y){x+=y;if(x>=MOD)x-=MOD;return x;}
int mul(int x,int y){return (x*y)%MOD;}

int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        cin>>arr;

        int sum=accumulate(all(arr),0);
        vector<int>dp(sum+1);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=sum-arr[i];j>=0;j--){
                dp[j+arr[i]]=add(dp[j+arr[i]],dp[j]);
            }
        }
        
        int ans=0;
        for(int i=0;i<=sum;i++)ans=add(ans,mul((i+1)/2,dp[i]));
        for(int i=0;i<n;i++){
            for(int j=0;j<arr[i];j++){
                ans=add(ans,mul(arr[i]-(arr[i]+j+1)/2,dp[j]));
            }
        }
        cout<<ans<<endl;
    }
return 0;
}