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
#define sz(x) x.size()
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

int fact[300006];
int mod=998244353;
int fast_mod_exp(int a,int b,int m){
    int res=1;
    while(b>0){
        if(b&1)res=(res*a)%m;
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}

int mod_inverse(int a,int m){
    return fast_mod_exp(a,m-2,m);
}

int ncr(int n,int r,int p){
    if(r==0)return 1;
    return ((fact[n]*mod_inverse(fact[n-r],p))%p*mod_inverse(fact[r],p))%p;
}

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first<p2.first) return true;
    else if(p1.first>p2.first) return false;
    else return p1.second>p2.second;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,k;
        cin>>n>>k;
        fact[0]=fact[1]=1;
        for(int i=1;i<=300002;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }
        vector<pair<int,int>> v;
        for(int i=1;i<=n;i++){
            int start,end;
            cin>>start>>end;
            v.eb(start,1);
            v.eb(end,0);
        }
        sort(all(v),cmp);

        int on_so_far=0;
        int ans=0;

        for(int i=0;i<sz(v);i++){
            if(v[i].second==1){
                if(on_so_far>=k-1){
                    ans=(ans+ncr(on_so_far,k-1,mod))%mod;
                }
                on_so_far++;
            }else on_so_far--;
        }

        cout<<ans<<endl;
    }
return 0;
}