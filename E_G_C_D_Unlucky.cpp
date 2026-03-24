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
        vector<int>p(n),s(n);
        cin>>p>>s;
        bool f=1;

        if(p[n-1]!=s[0]){f=0;}

        for(int i=1;i<n && f;i++){
            if(p[i-1]%p[i]!=0){f=0;break;}
        }

        for(int i=n-2;i>=0 && f;i--){
            if(s[i+1]%s[i]!=0){f=0;break;}
        }

        if(!f){no;continue;}

        int gcd=p[n-1];

        for(int i=1;i<n;i++){
            int x=p[i-1]/p[i];
            if(__gcd(x,s[i]/gcd)!=1){f=0;break;}
        }

        for(int i=n-2;i>=0 && f;i--){
            int x=s[i+1]/s[i];
            if(__gcd(x,p[i]/gcd)!=1){f=0;break;}
        }

        if(f)yes;
        else no;
    }
return 0;
}