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
    tc
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s=" "+s;
        vector<int>top(n+1,0),bot(n+1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                top[i]=bot[i-1]+1;
            }else{
                top[i]=top[i-1]+(i-1);
                bot[i]=bot[i-1]+(n-i);
            }
            ans=max(ans,max(top[i],bot[i]));
        }
        cout<<ans<<endl;
    }
return 0;
}