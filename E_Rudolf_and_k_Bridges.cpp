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
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[i][j];

        vector<int>cost(n);
        for(int i=0;i<n;i++){
            vector<int>dp(m,LLONG_MAX);
            deque<int>dq;
            dp[0]=arr[i][0]+1;
            dq.push_back(0);

            for(int j=1;j<m;j++){
                while(!dq.empty() && dq.front()<j-(d+1)){
                    dq.pop_front();
                }
                dp[j]=arr[i][j]+1+dp[dq.front()];
                while(!dq.empty() && dp[dq.back()]>=dp[j]){
                    dq.pop_back();
                }
                dq.push_back(j);
            }
            cost[i]=dp[m-1];
        }
        int cur=0;
        for(int i=0;i<k;i++){
            cur+=cost[i];
        }
        int ans=cur;
        for(int i=k;i<n;i++){
            cur+=cost[i];
            cur-=cost[i-k];
            ans=min(ans,cur);
        }
        cout<<ans<<endl;
    }
return 0;
}