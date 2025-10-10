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
        int p1=0,p2=0,o1=0,o2=0;
        int ans=LLONG_MAX;

        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){p2++;o2=i;}
            if(arr[i]>arr[i-1]){p1++;o1=i;}
        }

        if(p2==1 && arr[n-1]<=arr[0]){
            ans=min(ans,min(o2+2,n-o2));
        }
        if(p1==1 && arr[n-1]>=arr[0]){
            ans=min(ans,min(o1+1,n-o1+1));
        }

        if(p2==0)ans=min(ans,0ll);
        if(p1==0)ans=min(ans,1ll);
        if(ans==LLONG_MAX)ans=-1;

        cout<<ans<<endl;
    }
return 0;
}