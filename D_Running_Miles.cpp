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
        vector<int>arr(n);
        cin>>arr;
        vector<int>pre(n+1),suf(n+1);
        pre[0]=LLONG_MIN;
        for(int i=1;i<n-1;i++){
            pre[i]=max(pre[i-1],arr[i-1]+i-1);
        }
        suf[n-1]=LLONG_MIN;
        for(int i=n-2;i>0;i--){
            suf[i]=max(suf[i+1],arr[i+1]-i-1);
        }
        int ans=LLONG_MIN;
        for(int i=1;i<n-1;i++){
            ans=max(ans,arr[i]+pre[i]+suf[i]);
        }
        cout<<ans<<endl;
    }
return 0;
}