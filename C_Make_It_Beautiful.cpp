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
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        cin>>arr;

        int ans=0;
        for(auto a:arr)ans+=__builtin_popcountll(a);

        vector<int>cost;
        for(auto a:arr){
            int t=a;
            while(1){
                int c=(~t)&(t+1);
                if(c==0 || c>k)break;
                cost.pb(c);
                t+=c;
            }
        }

        sort(all(cost));
        int tk=0;
        for(auto c:cost){
            if(tk+c<=k){
                tk+=c;
                ans++;
            }else break;
        }

        cout<<ans<<endl;
    }
return 0;
}