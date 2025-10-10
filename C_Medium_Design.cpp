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

int fun(vector<pair<int,int>>&arr){
    vector<pair<int,int>>segs;
    for(auto &s:arr){
        segs.pb({s.f,+1});
        segs.pb({s.s+1,-1});
    }
    sort(all(segs));
    int cur=0,best=0;
    for(auto &s:segs){
        cur+=s.s;
        best=max(best,cur);
    }
    return best;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i].f>>arr[i].s;

        vector<pair<int,int>> not1;
        for(auto &s:arr){
            if(s.f>1)not1.pb(s);
        }
        int ans1=fun(not1);

        vector<pair<int,int>> notm;
        for(auto &s:arr){
            if(s.s<m)notm.pb(s);
        }
        int ans2=fun(notm);

        cout<<max(ans1,ans2)<<endl;
    }
return 0;
}