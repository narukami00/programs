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
        int w,h,a,b;
        cin>>w>>h>>a>>b;
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        int rx1=((x1%a)+a)%a;
        int rx2=((x2%a)+a)%a;
        int ry1=((y1%b)+b)%b;
        int ry2=((y2%b)+b)%b;

        int l1=max(0ll,x1);
        int r1=min(w,x1+a);
        int l2=max(0ll,x2);
        int r2=min(w,x2+a);
        bool f1=(r1<=l2)||(r2<=l1);

        l1=max(0ll,y1);
        r1=min(h,y1+b);
        l2=max(0ll,y2);
        r2=min(h,y2+b);
        bool f2=(r1<=l2)||(r2<=l1);

        bool f=0;
        if(rx1==rx2 && f1)f=1;
        if(ry1==ry2 && f2)f=1;

        if(f)yes;
        else no;
    }
return 0;
}