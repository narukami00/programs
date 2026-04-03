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
        int n,a,b;
        cin>>n>>a>>b;
        int g=__gcd(a,b);
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[i]=x%g;
        }
        sort(all(arr));

        int ans=arr[n-1]-arr[0];

        for(int i=0;i<n-1;i++){
            int mx=arr[i]+g;
            int mn=arr[i+1];
            ans=min(ans,mx-mn);
        }

        cout<<ans<<endl;
    }
return 0;
}