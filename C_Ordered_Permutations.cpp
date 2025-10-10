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

void fun(int i,int l,int r,int k,vector<int>& ans){
    if(l==r){
        ans[l]=i;
        return;
    }
    int sz=r-l-1;
    if(sz<60 && (1ll<<sz)<k){
        ans[r]=i;
        fun(i+1,l,r-1,k-(1ll<<sz),ans);
    }else{
        ans[l]=i;
        fun(i+1,l+1,r,k,ans);
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    if(n-1<60 && (1ll<<(n-1))<k){
        cout<<"-1"<<endl;
        return;
    }
    vector<int>ans(n);
    fun(1,0,n-1,k,ans);
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
}

int32_t main(){
    Flashyy
    tc
    {
        solve();
    }
return 0;
}