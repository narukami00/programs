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
    //tc
    {
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        cin>>arr;
        sort(all(arr));
        int ans=0;
        int l=0,r=n-1;
        bool f=0,t=0;
        while(l<=r){
            if(arr[l]+arr[r]>m){
                ans+=arr[r]+1;
                r--;
                f=0;
                t=0;
                continue;
            }
            f=1;
            if(!t){
                ans+=arr[r];
                r--;
                t=1;
            }else{
                ans+=arr[l];
                l++;
                t=0;
            }
        }
        if(f)ans++;
        cout<<ans<<endl;
    }
return 0;
}