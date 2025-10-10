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

int MAX=1e5;

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>arr(n+2, 0);
        for(int i=1;i<=n;i++) cin>>arr[i];
        vector<int>pre(n+2, 0);
        for(int i=1;i<=n;i++) pre[i] = pre[i-1] + arr[i];

        int l=0,r=1e15;
        vector<int>dp(n+3, 0);
        int ans = 0;

        while(l<=r){
            int mid=(l+r)/2;
            deque<int>d;
            int j=0;
            for(int i=1;i<=n+1;i++){
                while(sz(d) && d.back() > dp[i-1]){
                    d.pop_back();
                }
                d.pb(dp[i-1]);
                while(pre[i-1] - pre[j] > mid){
                    if(d.front() == dp[j]){
                        d.pop_front();
                    }
                    j++;
                }
                dp[i] = d.front() + arr[i];
            }

            if(dp[n+1] > mid) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        cout<<ans<<endl;
    }
    return 0;
}
