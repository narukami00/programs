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
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(m);
        cin>>a;
        cin>>b;
        sort(rall(b));
        vector<int> ans;
        int i=0,j=0;

        while(i<n){
            while(j<m && b[j]>a[i]){
                ans.pb(b[j]);
                j++;
            }
            ans.pb(a[i]);
            i++;
        }
        while(j<m){
            ans.pb(b[j]);
            j++;
        }

        cout<<ans<<endl;
    }
return 0;
}