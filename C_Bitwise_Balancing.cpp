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
        int b,c,d;
        cin>>b>>c>>d;
        int ans=0;
        for(int i=0;i<=61;i++){
            int last_b=(b>>i)&1;
            int last_c=(c>>i)&1;
            int last_d=(d>>i)&1;

            if(last_b==last_c && last_c==!last_d){
                ans+=(1LL<<i);
            }else if(last_b==last_d && last_d==!last_c){
                ans+=(1LL<<i);
            }else if(last_c==last_d && last_d==!last_b){
                ans=-1;
                break;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}