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

const int mod=998244353;
const int mx=1e5+5;
int pow2[mx];

int32_t main(){
    Flashyy
    pow2[0]=1;
    for(int i=1;i<mx;i++)pow2[i]=(pow2[i-1]<<1)%mod;
    tc
    {
        int n;
        cin>>n;
        vector<int>p(n),q(n);
        cin>>p;cin>>q;
        vector<int>r(n);
        int mxp=-1,mxq=-1,indxp=-1,indxq=-1;

        for(int i=0;i<n;i++){
            if(p[i]>mxp){
                mxp=p[i];
                indxp=i;
            }
            if(q[i]>mxq){
                mxq=q[i];
                indxq=i;
            }
            int e,f;
            if(mxp>mxq){
                e=mxp;
                f=q[i-indxp];
            }else if(mxq>mxp){
                e=mxq;
                f=p[i-indxq];
            }else{
                e=mxp;
                f=max(q[i-indxp],p[i-indxq]);
            }
            
            r[i]=(pow2[e]+pow2[f])%mod;
        }

        cout<<r<<endl;
    }
return 0;
}