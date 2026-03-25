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
        vector<int>a(n);
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if((i+1)&1)ans+=a[i];
            else ans-=a[i];
        }

        if(n==1){
            cout<<ans<<endl;
            continue;
        }

        int mx_cost=(n&1)?n-1:n-2;

        int odd_mn=LLONG_MAX,odd_mx=LLONG_MIN;
        int even_mn=LLONG_MAX,even_mx=LLONG_MIN;

        for(int i=1;i<=n;i++){
            int val=a[i-1];
            if(i&1){
                odd_mn=min(odd_mn,i+2*val);
                odd_mx=max(odd_mx,i-2*val);
            }else{
                even_mn=min(even_mn,i-2*val);
                even_mx=max(even_mx,i+2*val);
            }
        }

        int gain=max(mx_cost,max(even_mx-odd_mn,odd_mx-even_mn));
        cout<<ans+gain<<endl;
    }
return 0;
}