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

int fun(int idx, int cur_wt, vector<int>&wt, vector<int>&val, vector<vector<int>>&dp){
    if(idx==0){
        if(wt[0]<=cur_wt)return val[0];
        else return 0;
    }
    if(dp[idx][cur_wt]!=-1)return dp[idx][cur_wt];
    int notTake=fun(idx-1,cur_wt,wt,val,dp);
    int take=-1e9;
    if(wt[idx]<=cur_wt)take=val[idx]+fun(idx-1,cur_wt-wt[idx],wt,val,dp);
    return dp[idx][cur_wt]=max(take,notTake);
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,W;
        //cin>>n>>W;
        cin>>W>>n;
        vector<int>wt(n),val(n);
        for(int i=0;i<n;i++){
            //cin>>wt[i]>>val[i];
            cin>>val[i]>>wt[i];
        }
        // for(int i=0;i<n;i++)cin>>wt[i];
        // for(int i=0;i<n;i++)cin>>val[i];
        vector<int>prev(W+1,0);
        //for(int w=wt[0];w<=W;w++)prev[w]=val[0];
        for(int i=1;i<=n;i++){
            for(int w=W;w>=0;w--){
                int notTake=prev[w];
                int take=-1e9;
                if(wt[i-1]<=w)take=val[i-1]+prev[w-wt[i-1]];
                prev[w]=max(take,notTake);
            }   
        }
        cout<<prev[W]<<endl;
        // vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        // for(int w=wt[0];w<=W;w++)dp[0][w]=val[0];
        // for(int i=1;i<n;i++){
        //     for(int w=0;w<=W;w++){
        //         int notTake=dp[i-1][w];
        //         int take=-1e9;
        //         if(w-wt[i]>=0)take=val[i]+dp[i-1][w-wt[i]];
        //         dp[i][w]=max(take,notTake);
        //     }
        // }
        // cout<<dp[n-1][W]<<endl;
    }
return 0;
}