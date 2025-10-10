#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
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

int fun(int n){
    int rem=n%4;
    if(rem==0)return n;
    if(rem==1)return 1;
    if(rem==2)return n+1;
    return 0;
}

int rng(int l,int r){
    return fun(r)^fun(l-1);
}

int32_t main(){
    Flashyy
    tc
    {
        int l,r,i,k;
        cin>>l>>r>>i>>k;
        int hi=rng((l-k+(1<<i)-1)>>i,(r-k)>>i)<<i;
        int lo=k*(((r-k)/(1<<i)-(l-k-1)/(1<<i))&1);
        cout<<(rng(l,r) ^ hi ^ lo)<<endl;
    }
return 0;
}