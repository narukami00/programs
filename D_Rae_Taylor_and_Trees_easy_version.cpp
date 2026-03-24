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
        int n;
        cin>>n;
        vector<int>a(n),mn(n),mx(n);
        cin>>a;

        for(int i=0;i<n;i++){
            if(i==0)mn[i]=a[i];
            else mn[i]=min(mn[i-1],a[i]);
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1)mx[i]=a[i];
            else mx[i]=max(mx[i+1],a[i]);
        }

        bool f=1;
        for(int i=1;i<n;i++){
            if(mn[i-1]>mx[i]){
                f=0;break;
            }
        }

        if(f)yes;
        else no;
    }
return 0;
}