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
        int n;
        cin>>n;
        vector<int>arr(n);
        cin>>arr;

        vector<int> l(n),r(n);
        for(int i=0;i<n;i++){
            l[i]=arr[i]+(n-1-i);
            r[i]=arr[i]+i;
        }

        vector<int>pre(n),suf(n);
        pre[0]=l[0],suf[n-1]=r[n-1];

        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],l[i]);
        for(int i=n-2;i>=0;i--)suf[i]=max(suf[i+1],r[i]);

        int ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            int can=arr[i];
            if(i>0)can=max(can,pre[i-1]);
            if(i<n-1)can=max(can,suf[i+1]);
            ans=min(ans,can);
        }
        
        cout<<ans<<endl;
    }
return 0;
}