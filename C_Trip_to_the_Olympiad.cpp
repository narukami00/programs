#include<bits/stdc++.h>
using namespace std;
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

int main(){
    Flashyy
    tc
    {
        int l,r;
        cin>>l>>r;
        int k=31-__builtin_clz(l^r);
        int a=l|((1<<k)-1);
        int b=a+1;
        int c=(a==l?r:l);
        cout<<a<<sp<<b<<sp<<c<<endl;
    }
return 0;
}