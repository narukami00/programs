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

int fun(int x,int y){
    if(x==0)return 0;
    if(y==0)return 1;
    if(x>=y){
        int a=x%y;
        int b=x/y;
        if(b%2==1)return fun(y,a)+b+b/2;
        else return fun(a,y)+b+b/2;
    }
    return 1+fun(y,abs(x-y));
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        cin>>a;
        cin>>b;
        bool f=1;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(a[i]==0 && b[i]==0)continue;
            int cur=fun(a[i],b[i])%3;
            if(prev==-1){prev=cur;continue;}
            if(prev!=cur){
                f=0;
                break;
            }
        }
        if(f)yes;
        else no;
    }
return 0;
}