#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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

int query(int x,int y){
    cout<<"? "<<x<<sp<<y<<endl;
    int m;cin>>m;
    return m;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;

        int a=query(1,1);
        int b=query(n,1);
        int c=query(1,m);

        int x1=(a-b+n+1)/2;
        int y1=(a+b-n+3)/2;
        int x2=(a+c-m+3)/2;
        int y2=(a-c+m+1)/2;

        if(x1>=1 && x1<=n && y1>=1 && y1<=m && query(x1,y1)==0)cout<<"! "<<x1<<sp<<y1<<endl;
        else cout<<"! "<<x2<<sp<<y2<<endl;
    }
return 0;
}