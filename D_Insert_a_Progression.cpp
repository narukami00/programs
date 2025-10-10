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
        int n,x;
        cin>>n>>x;
        vector<int>arr(n);
        cin>>arr;
        int cost=0;
        for(int i=0;i<n-1;i++)cost+=abs(arr[i]-arr[i+1]);
        int t=2;
        int ans=LLONG_MAX;
        while(t--){
            int mn=abs(arr[0]-1);
            ans=min(ans,cost+abs(arr[0]-x)+x-1);
            for(int i=0;i<n-1;i++){
                ans=min({ans,cost+mn-abs(arr[i]-arr[i+1])+abs(arr[i]-x)+abs(arr[i+1]-x),cost-abs(arr[i]-arr[i+1])+abs(arr[i]-x)+abs(arr[i+1]-1)+x-1});
                mn=min(mn,abs(arr[i]-1)+abs(arr[i+1]-1)-abs(arr[i]-arr[i+1]));
            }
            ans=min(ans,cost+mn+abs(arr[n-1]-x));
            reverse(all(arr));
        }
        cout<<ans<<endl;
    }
return 0;
}