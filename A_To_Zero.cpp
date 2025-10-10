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

int myceil(int a, int b) {
    if (a % b == 0) return (a / b);
    bool positive = !((a < 0) ^ (b < 0));
    return a / b + positive;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        int odd,even;
        if(k%2==0){
            even=k;
            odd=k-1;
        }else{
            odd=k;
            even=k-1;
        }
        int ans=1;
        if(n%2==0){
            n-=even;
        }else n-=odd;
        ans+=myceil(n,even);
        cout<<ans<<endl;
    }
return 0;
}