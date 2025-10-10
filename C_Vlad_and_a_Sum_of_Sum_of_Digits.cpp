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

int ans[200007];

int fun(int x){
    int res=0;
    while(x){
        res+=(x%10);
        x/=10;
    }
    return res;
}

int32_t main(){
    Flashyy
    for(int i=1;i<200007;i++) ans[i]=ans[i-1]+fun(i);
    tc
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
return 0;
}