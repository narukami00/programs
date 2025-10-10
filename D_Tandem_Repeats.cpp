#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define con continue
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
        string s;
        cin>>s;
        int n=sz(s);
        int ans=0;
       
        for(int l=1;2*l<=n;l++){
            int len=n-l;
            vector<int>pref(len+1,0);
            for(int i=0;i<len;i++){
                int val= (s[i]==s[i+l] || s[i]=='?' || s[i+l]=='?')?1:0;
                pref[i+1]=pref[i]+val;
            }
            for(int i=0;i+2*l<=n;i++){
                int sum=pref[i+l]-pref[i];
                if(sum==l){
                    ans=max(ans,2*l);
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}