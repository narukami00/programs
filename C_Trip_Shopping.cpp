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
        int n,k;
        cin>>n>>k;
        vector<int>a(n),b(n);
        cin>>a>>b;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(a[i]-b[i]);
            if(a[i]>b[i])swap(a[i],b[i]);
        }
        vector<pair<int,int>>ab;
        for(int i=0;i<n;i++)ab.pb({a[i],b[i]});
        sort(all(ab));
        int mn=LLONG_MAX;
        for(int i=1;i<n;i++){
            mn=min(mn,ab[i].f-ab[i-1].s);
        }
        cout<<ans+max(0ll,2*mn)<<endl;
    }
return 0;
}