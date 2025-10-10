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
int pow10(int p){
    int res=1;
    while(p--)res*=10;
    return res;
}
int fun(string &s,int r0){
    int res=0;
    for(int i=0;i<r0;i++){
        res=res*10+(s[i]-'0');
    }return res;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        string s=to_string(n);
        int k=sz(s);

        vector<pair<int,int>>ans;

        if(n==k){
            for(int a=2;a<=10000;a++){
                int b=a-1;
                if(b>=1 && b<=min(10000ll,a)){
                    ans.pb({a,b});
                }
            }
        }else{
            for(int q=1;q<=20;q++){
                int exp=q*k;
                int powa=pow10(exp);
                int deno=pow10(k)-1;
                int rep=(powa-1)/deno;

                for(int r0=0;r0<k;r0++){
                    int f;
                    if(r0==0)f=n*rep;
                    else{
                        int fact=pow10(r0);
                        int pre=fun(s,r0);
                        f=n*rep*fact+pre;
                    }

                    int num=f-(q*k+r0);
                    int dif=n-k;
                    if(num<0)continue;
                    if(num%dif!=0)continue;
                    int a=num/dif;
                    if(a<=q)continue;
                    if(a<1 || a>10000)continue;
                    int b=a*k-(q*k+r0);
                    if(b<1 || b>min(10000ll,n*a))continue;

                    ans.pb({a,b});
                }
                int f0=n*rep;
                int num0=f0-q*k;
                if(num0<0)continue;
                int a0=num0/(n-k);
                if(a0>10000)break;
            }
        }

        cout<<sz(ans)<<endl;
        for(auto &it:ans)cout<<it.f<<sp<<it.s<<endl;
    }
return 0;
}