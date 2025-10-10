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
const int N=1e5+5;
int n,q,ans[N],arr[N];
bool pos(int mid){
    for(int i=1;i<=n;i++)ans[i]=0;
    int tq=q;
    for(int i=1;i<mid;i++)if(arr[i]<=tq)ans[i]=1;
    for(int i=mid;i<=n;i++){ans[i]=1;if(tq==0)return 0;if(arr[i]>tq)tq--;}
    if(tq<0)return 0;
    return 1;
}
int32_t main(){
    Flashyy
    tc
    {
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>arr[i];
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(pos(mid))r=mid-1;
            else l=mid+1;
        }
        pos(r+1);
        for(int i=1;i<=n;i++)cout<<ans[i];
        cout<<endl;
    }
return 0;
}