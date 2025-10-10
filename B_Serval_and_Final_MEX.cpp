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
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];
        vector<pair<int,int>> ans;
        int l=-1,r=-1;
        bool f=0;
        for(int i=n;i>=1;i--){
            if(arr[i]==0 && !f){
                r=i;
                f=1;
                continue;
            }
            if(arr[i]==0 && f){
                l=i;
            }
        }
        if(l==-1 && r==-1){
            cout<<1<<endl;
            cout<<1<<sp<<n<<endl;
        }else if(l==-1){
            cout<<2<<endl;
            if(r==1)cout<<r<<sp<<r+1<<endl;
            else cout<<r-1<<sp<<r<<endl;
            cout<<1<<sp<<n-1<<endl;
        }else if(l==1 && r==n){
            cout<<3<<endl;
            cout<<n/2+1<<sp<<n<<endl;
            cout<<1<<sp<<n/2<<endl;
            cout<<1<<sp<<2<<endl;
        }else{
            cout<<2<<endl;
            cout<<l<<sp<<r<<endl;
            cout<<1<<sp<<n-(r-l)<<endl;
        }

    }
return 0;
}