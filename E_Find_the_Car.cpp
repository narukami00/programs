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
        int n,k,q;
        cin>>n>>k>>q;
        vector<int>a(k+1);
        vector<int>b(k+1);
        a[0]=0,b[0]=0;
        for(int i=1;i<=k;i++)cin>>a[i];
        for(int i=1;i<=k;i++)cin>>b[i];

        while(q--){
            int d;
            cin>>d;

            if(d==0) {
                cout<<0<<sp;
                continue;
            }

            if(d==n) {
                cout<<b[k]<<sp;
                continue;
            }

            int idx=upper_bound(all(a),d)-a.begin();
            int ans=b[idx-1]+((d-a[idx-1])*(b[idx]-b[idx-1]))/(a[idx]-a[idx-1]);
            cout<<ans<<sp;
        }

        cout<<endl;
    }
return 0;
}