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
const int mod=998244353;
int32_t main(){
    Flashyy
    tc
    {
        int l,r;
        cin>>l>>r;
        int size=1,temp=l;
        while(temp<=r){
            temp*=2;
            if(temp<=r)size++;
        }
        int cnt=(r/(1<<(size-1)))-l+1;
        int n=((r/((1<<(size-2))*3))-l+1);
        if(size>1 && n>0) cnt+=(size-1)*n;
        cout<<size<<sp<<cnt<<endl;
    }
return 0;
}