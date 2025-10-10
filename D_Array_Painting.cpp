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
        
        int ans=0;
        int l=0;
        while(l<n){
            int r=l+1;
            bool two=(arr[l]==2);
            bool midzero=0;
            while(r<n){
                if(r-1>l && arr[r-1]==0)midzero=1;
                if(arr[r]==2)two=1;
                bool pos=(!midzero) && (two || arr[l]!=0 ||arr[r]!=0);
                if(!pos)break;r++;
            }l=r;ans++;
        }
        cout<<ans<<endl;
    }
return 0;
}