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

vector<int>fibo={1,2,3,5,8,13,21,34,55,89};

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        while(m--){
            int w,l,h;
            cin>>w>>l>>h;

            if(min(w,l)<fibo[n-1] || h<fibo[n-1]){cout<<"0";continue;}

            if(w-fibo[n-1]<fibo[n-2] && l-fibo[n-1]<fibo[n-2] && h<fibo[n-1]+fibo[n-2]){cout<<"0";continue;}

            cout<<"1";
        }
        cout<<endl;
    }
return 0;
}