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

int32_t main(){
    Flashyy
    tc
    {
        string s;
        cin>>s;
        int ans=1;
        bool f=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0' && s[i-1]=='1'){
                ans++;
                continue;
            }
            if(s[i]=='1' && s[i-1]=='0' && f==0){
                f=1;
                continue;
            }
            if(s[i]!=s[i-1] && f==1){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}