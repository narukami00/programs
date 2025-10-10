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

        if(n%2==0){
            for(int i=(n/2);i<n;i++)cout<<i<<sp;
            for(int i=n+1;i<=((3*n)/2);i++)cout<<i<<sp;
            cout<<endl;
            continue;
        }

        vector<int>ans;
        for(int i=((n+1)/2);i<=((3*n)/2);i++)ans.pb(i+2);
        ans[0]-=1;ans[sz(ans)-1]+=1;ans[sz(ans)-2]+=1;
        cout<<ans<<endl;
    }
return 0;
}