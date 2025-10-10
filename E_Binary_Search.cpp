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
        int s1=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==x)s1=i;
        }
        int l=0,r=n;
        while(r-l>1){
            int m=(l+r)/2;
            if(arr[m]<=x)l=m;
            else r=m;
        }
        cout<<1<<endl;
        cout<<s1+1<<sp<<l+1<<endl;
    }
return 0;
}