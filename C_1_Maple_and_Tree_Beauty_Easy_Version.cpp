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
        int n,k;
        cin>>n>>k;
        vector<int>a(n,-1), depth(n,0), no_child(n,1),cnt(n+1);
        cnt[0]++;
        for(int i=1;i<n;i++){
            cin>>a[i];
            a[i]--;
            depth[i]=depth[a[i]]+1;
            cnt[depth[i]]++;
            no_child[a[i]]=0;
        }

        int mx=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(no_child[i]){
                mx=min(mx,depth[i]);
            }
        }

        int sum=0;
        vector<int>dp(n+1);
        dp[0]=1;
        for(int i=0;i<=mx;i++){
            for(int j=sum;j>=0;j--){
                dp[j+cnt[i]]|=dp[j];
            }
            sum+=cnt[i];
        }

        bool ok=1;
        if(sum<=k || sum<=n-k){
            cout<<mx+1<<endl;
        }else{
            for(int i=0;i<=sum;i++){
                if(dp[i] && (i<=k && sum-i<=n-k)){
                    cout<<mx+1<<endl;
                    ok=0;
                    break;
                }
            }
            if(ok)cout<<mx<<endl;
        }
    }
return 0;
}