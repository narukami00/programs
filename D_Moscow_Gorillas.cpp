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

int fun(int l,int r,int n){
    int r1=max(r,1ll);
    if(r1>n)return 0;
    int ans=0;
    int r2=min(n,l-1);
    if(r1<=r2)ans+=(r1+r2)*(r2-r1+1)/2;
    if(n>=max(r1,l))ans+=l*(n-max(r1,l)+1);
    return ans;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n;cin>>n;
        vector<int>p(n+1),q(n+1),posp(n+1),posq(n+1);
        for(int i=1;i<=n;i++){cin>>p[i];posp[p[i]]=i;}
        for(int i=1;i<=n;i++){cin>>q[i];posq[q[i]]=i;}

        int ans=1;
        int l=n+1,r=0;
        for(int k=1;k<=n;k++){
            int kp=posp[k];
            int kq=posq[k];
            int u=min(kp,kq);
            int v=max(kp,kq);
            ans+=(fun(l,r,n)-fun(min(l,kp),max(r,kp),n)-fun(min(l,kq),max(r,kq),n)+fun(min(l,u),max(r,v),n));
            l=min(l,u);
            r=max(r,v);
        }
        cout<<ans<<endl;
    }
return 0;
}