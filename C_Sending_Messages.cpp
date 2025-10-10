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

int32_t main(){
    Flashyy
    tc
    {
        int n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<int> m(n+1);
        for(int i=1;i<=n;i++)cin>>m[i];
        m[0]=0;
        for(int i=1;i<=n;i++){
            int d= m[i]-m[i-1];
            if(d*a>=b)f-=b;
            else f-=d*a;
        }
        if(f<=0)no;
        else yes;

    }
return 0;
}