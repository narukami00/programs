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
#define sz(x) x.size()
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
const int mod=1e9+7,N=2e5+15;
int r,g,h,ans;
int cnt[N];
int32_t main(){
    Flashyy
    //tc
    {
        cin>>r>>g;
        for(h=cnt[0]=1;h*(h+1)/2<=r+g;h++){
            for(int i=N-1;i>=h;i--){
                (cnt[i]+=cnt[i-h])%=mod;
            }
        }
        h--;
        for(int i=0;i<=r;i++){
            if(h*(h+1)/2 -i<=g){
                (ans+=cnt[i])%=mod;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}