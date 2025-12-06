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

double f(double x){
    return 1/(1+x*x);
}

int32_t main(){
    Flashyy
    //tc
    {
        double a=0,b=1;
        int n=12; //n must be multiple of 3

        if(n%3!=0) n+=(3-n%3);

        double h=(b-a)/n;
        double res=f(a)+f(b);

        for(int i=1;i<n;i++){
            double x=a+i*h;
            if(i%3==0) res+=2*f(x);
            else res+=3*f(x);
        }

        res=res*(3*h/8.0);
        cout<<fixed<<setprecision(6)<<res<<endl;
    }
return 0;
}