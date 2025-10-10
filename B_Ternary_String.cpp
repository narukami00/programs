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
        string s;
        cin>>s;
        int ans=LLONG_MAX;
        vector<pair<char,int>>arr;
        arr.pb({s[0],1});
        for(int i=1;i<sz(s);i++){
            if(s[i]==arr.back().f)arr.back().s++;
            else arr.pb({s[i],1});
        }

        for(int i=2;i<sz(arr);i++){
            char frst=arr[i-2].f;
            char sec=arr[i-1].f;
            char thrd=arr[i].f;

            if(frst!=sec && sec!=thrd && thrd!=frst){
                int res=2+arr[i-1].s;
                ans=min(ans,res);
            }
        }
        if(ans==LLONG_MAX)ans=0;
        cout<<ans<<endl;
    }
return 0;
}