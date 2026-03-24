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
        vector<int>a1(n),a2(n);
        cin>>a1>>a2;
        vector<int>pre_mx(n,0),suf_mx(n),pre_mn(n,2*n+1),suf_mn(n,2*n+1);
        pre_mx[0]=a1[0];
        pre_mn[0]=a1[0];
        suf_mx[n-1]=a2[n-1];
        suf_mn[n-1]=a2[n-1];
        for(int i=1;i<n;i++){
            pre_mx[i]=max(pre_mx[i-1],a1[i]);
            pre_mn[i]=min(pre_mn[i-1],a1[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf_mx[i]=max(suf_mx[i+1],a2[i]);
            suf_mn[i]=min(suf_mn[i+1],a2[i]);
        }
        int ans=0;
        vector<pair<int,int>>prs;
        for(int i=0;i<n;i++){
            int l=min(pre_mn[i],suf_mn[i]);
            int r=2*n-max(pre_mx[i],suf_mx[i])+1;
            prs.pb({l,r});
        }
        sort(rall(prs));
        int mx_r=0;
        for(auto [l,r]:prs){
            if(r>mx_r){
                ans+=l*(r-mx_r);
                mx_r=r;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}