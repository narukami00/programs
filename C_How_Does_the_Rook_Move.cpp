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
const int mod=1e9+7;
int32_t main(){
    Flashyy
    int N=300000;
    vector<int>inv(N+1,0);
    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<=N;i++)inv[i]=(inv[i-1]+(2*(i-1)*inv[i-2])%mod)%mod;
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<bool>vis(n+1,0);
        for(int i=0;i<k;i++){
            int r,c;
            cin>>r>>c;
            vis[r]=1;
            if(r!=c)vis[c]=1;
        }
        int o=0;
        for(int i=1;i<=n;i++)if(vis[i])o++;
        int rem=n-o;
        cout<<inv[rem]%mod<<endl;
    }
return 0;
}