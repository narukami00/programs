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
    const int N = 45;
    vector<int> fib(N + 1); 
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= N; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    tc
    {
        int n,x,y;
        cin>>n>>x>>y;
        x--;y--;
        bool f=1;
        while(n>1){
            if(fib[n-1]<=y && y<fib[n]){
                f=0;
                break;
            }
            if(y>=fib[n])y-=fib[n];
            swap(x,y);
            n--;
        }
        if(f)yes;
        else no;
    }
return 0;
}