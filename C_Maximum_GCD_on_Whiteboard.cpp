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
        vector<int>a(n),freq(n+1,0),pre(n+1,0);
        cin>>a;
        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+freq[i];
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            int cand=n-pre[min(n,4*i-1)];
            if(i<=n)cand+=freq[i];
            if(2*i<=n)cand+=freq[2*i];
            if(3*i<=n)cand+=freq[3*i];
            if(cand>=n-k)ans=i;
        }
        cout<<ans<<endl;
    }
return 0;
}