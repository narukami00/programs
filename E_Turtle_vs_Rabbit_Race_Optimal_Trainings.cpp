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
        vector<int>a(n+1), pre(n+1,0);

        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }

        int q;
        cin>>q;
        while(q--){
            int l,u;
            cin>>l>>u;
            int target=pre[l-1]+u;

            auto it=lower_bound(all(pre),target);
            int mid=distance(pre.begin(),it);

            int best=l;
            int mx=LLONG_MIN;

            int r1=min(mid,n);
            int k1=pre[r1]-pre[l-1];
            int per1=(k1<=0)?LLONG_MIN:(k1*(2*u-k1+1))/2;

            
            int r2=min(mid-1,n);
            int k2=pre[r2]-pre[l-1];
            int per2=(k2<=0)?LLONG_MIN:(k2*(2*u-k2+1))/2;

            if(per2>=per1){
                cout<<r2<<sp;
            }else cout<<r1<<sp;
        }

        cout<<endl;
    }
return 0;
}