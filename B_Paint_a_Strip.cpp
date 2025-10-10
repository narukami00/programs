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

int myCeil(double x) {
    int intPart = static_cast<int>(x);
    return (x > intPart) ? intPart + 1 : intPart;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        double f= log2((n+2.0)/3.0);
        int ans=myCeil(f)+1;
        cout<<ans<<endl;
    }
return 0;
}