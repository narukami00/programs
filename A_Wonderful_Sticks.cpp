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
        deque<int>d;
        for(int i=1;i<=n;i++)d.pb(i);
        vector<int>ans;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='>'){
                ans.pb(d.back());
                d.pop_back();
            }else if(s[i]=='<'){
                ans.pb(d.front());
                d.pop_front();
            }
        }
        ans.pb(d.front());
        reverse(all(ans));
        cout<<ans<<endl;
    }
return 0;
}