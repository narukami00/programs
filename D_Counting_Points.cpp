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

int isqrt(int x) {
    int r = sqrtl(x);
    while ((r + 1) * (r + 1) <= x) r++;
    while (r * r > x) r--;
    return r; 
}

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        map<int,int>cnt;
        vector<int>a(n),r(n);
        cin>>a>>r;

        for(int i=0;i<n;i++){
            int ca=a[i],cr=r[i];
            for(int x=ca-cr;x<=ca+cr;x++){
                cnt[x]=max(cnt[x],2*isqrt(cr*cr-(x-ca)*(x-ca))+1);
            }
        }

        int ans=0;
        for(auto [x,c]:cnt)ans+=c;
        cout<<ans<<endl;
    }
return 0;
}