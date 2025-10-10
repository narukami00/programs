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
#define sz(x) x.size()
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
        vector<int> arr(n),pre(n),suf(n),ans(n);
        cin>>arr;

        pre[0]=arr[0];
        for(int i=1;i<n;i++) pre[i]=max(pre[i-1],arr[i]);

        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) suf[i]=min(suf[i+1],arr[i]);

        ans[n-1]=pre[n-1];
        for(int i=n-2;i>=0;i--){
            if(pre[i]>suf[i+1]) ans[i]=ans[i+1];
            else ans[i]=pre[i];
        }

        cout<<ans<<endl;
     }
return 0;
}