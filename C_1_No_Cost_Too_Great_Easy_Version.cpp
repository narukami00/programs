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
    const int N = 2e5 + 10;
    vector<vector<int>>pfact(N+1);
    for (int i = 2; i <= N; i++){
        if (!pfact[i].empty())
            continue;

        for (int j = i; j <= N; j += i)
            pfact[j].push_back(i);
    }
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        cin>>a>>b;

        int ans=2;
        map<int,int>cnt;
        for(int i=0;i<n;i++){
            for(auto x:pfact[a[i]]){
                if(cnt[x]>0)ans=0;
                cnt[x]++;
            }
        }

        for(int i=0;i<n;i++){
            for(auto x:pfact[a[i]]){
                cnt[x]--;
            }
            for(auto x:pfact[a[i]+1]){
                if(cnt[x]>0)ans=min(ans,1ll);
            }
            for(auto x:pfact[a[i]]){
                cnt[x]++;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}