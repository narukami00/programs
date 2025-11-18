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

int fun(int idx, int cur_prc, vector<int>&price, vector<int>&pages, vector<vector<int>>&dp){
    if(idx==0){
        if(price[0]<=cur_prc)return pages[0];
        else return 0;
    }
    if(dp[idx][cur_prc]!=-1)return dp[idx][cur_prc];
    int notTake=fun(idx-1,cur_prc,price,pages,dp);
    int take=-1e9;
    if(price[idx]<=cur_prc)take=pages[idx]+fun(idx-1,cur_prc-price[idx],price,pages,dp);
    return dp[idx][cur_prc]=max(take,notTake);
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,x;
        cin>>n>>x;
        vector<int>price(n);
        vector<int>pages(n);
        for(int i=0;i<n;i++)cin>>price[i];
        for(int i=0;i<n;i++)cin>>pages[i];
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        cout<<fun(n-1,x,price,pages,dp)<<endl;
    }
return 0;
}