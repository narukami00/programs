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
        int ans=-1;
        x++;

        for(int i=30;i>=0;i--){
            vector<int>lr;
            bool f=0;
            for(int j=0;j<sz(arr);j++){
                if(!f)lr.pb(arr[j]);
                else lr.back()^=arr[j];

                if(arr[j]&(1<<i))f=!f;
            }

            if(!(x&(1<<i))){
                if(f) break;
                arr=lr;
            }else if(!f){
                ans=max(ans,(int)sz(lr));
            }
        }

        cout<<ans<<endl;
    }
return 0;
}