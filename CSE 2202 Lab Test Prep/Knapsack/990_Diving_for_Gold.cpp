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

int n,t,w;
vector<vector<int>>dp;
vector<int>d,g;
int solve(int i, int rem_time){
    if(i==n)return 0;
    if(dp[i][rem_time]!=-1)return dp[i][rem_time];

    int cost=3*w*d[i];
    int not_take=solve(i+1,rem_time);
    int take=-1e9;
    if(rem_time-cost>=0){
        take=g[i]+solve(i+1,rem_time-cost);
    }
    return dp[i][rem_time]=max(take,not_take);
}

void recon(int i,int rem_time,vector<pair<int,int>>&res){
    if(i==n)return;
    int cost=3*w*d[i];
    if(rem_time-cost>=0 && dp[i][rem_time]==g[i]+dp[i+1][rem_time-cost]){
        res.pb({d[i],g[i]});
        recon(i+1,rem_time-cost,res);
    }
    else{
        recon(i+1,rem_time,res);
    }
}

int32_t main(){
    Flashyy
    //tc
    string line;
    bool first=true;
    while(getline(cin,line)){
    {
        if(line.empty())continue;
        stringstream ss(line);
        int t,w,n;
        ss>>t>>w;
        cin>>n;
        vector<int>d(n),g(n);
        for(int i=0;i<n;i++)cin>>d[i]>>g[i];

        // vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        // for(int i=1;i<=n;i++){
        //     int time=3*w*d[i-1];
        //     for(int j=0;j<=t;j++){
        //         dp[i][j]=dp[i-1][j];
        //         if(j-time>=0){
        //             dp[i][j]=max(dp[i][j],g[i-1]+dp[i-1][j-time]);
        //         }
        //     }
        // }
        // cout<<dp[n][t]<<endl;
        // vector<pair<int,int>>res;
        // int cur=t;
        // for(int i=n;i>=1;i--){
        //     int time=3*w*d[i-1];
        //     if(cur-time>=0 && dp[i][cur]==g[i-1]+dp[i-1][cur-time]){
        //         res.pb({d[i-1],g[i-1]});
        //         cur-=time;
        //     }
        // }
        // reverse(all(res));
        // cout<<sz(res)<<endl;
        // for(auto &[dd,gg]:res){
        //     cout<<dd<<sp<<gg<<endl;
        // }

        vector<int>prev(t+1,0);
        for(int i=1;i<=n;i++){
            for(int j=t;j>=0;j--){
                int time=3*w*d[i-1];
                int not_take=prev[j];
                int take=-1e9;
                if(j-time>=0){
                    take=g[i-1]+prev[j-time];
                }
                prev[j]=max(take,not_take);
            }
        }
        cout<<prev[t]<<endl;

        cin.ignore();
    }
}
return 0;
}