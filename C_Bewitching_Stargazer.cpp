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

int n,k;
map<int,pair<int,int>>dp;

pair<int,int> ans(int l,int r){
    int len=r-l+1;
    if(len<k) return make_pair(0,0);

    if(dp.find(len)!=dp.end()){
        return make_pair(dp[len].first+(l-1)*dp[len].second,dp[len].second);
    }

    if(len&1){
        if(len!=1){
            auto a=ans(l,l+len/2-1);
            auto b=ans(l+len/2+1,r);
            pair<int,int> t=make_pair(a.first+b.first+l+len/2,a.second+b.second+1);
            dp[len]=make_pair(t.first-t.second*(l-1),t.second);
            return t;
        }else{
            dp[1]=make_pair(1,1);
            return make_pair(1,1);
        }
    }else{
        auto a=ans(l,l+len/2-1);
        auto b=ans(l+len/2,r);
        pair<int,int> t=make_pair(a.first+b.first,a.second+b.second);
        dp[len]=make_pair(t.first-t.second*(l-1),t.second);
        return t;
    }
}

int32_t main(){
    Flashyy
    tc
    {
        cin>>n>>k;
        dp.clear();
        cout<<ans(1,n).first<<endl;
    }
return 0;
}