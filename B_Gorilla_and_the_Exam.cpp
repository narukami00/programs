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
        int n,k;
        cin>>n>>k;
        
        set<int>arr;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            mp[x]++;arr.insert(x);
        }

        multiset<int>st;
        for(auto x:arr)st.insert(mp[x]);

        int ans=sz(st);
        for(auto x:st){
            if(k-x>=0){
                k-=x;
                ans--;
            }
        }

        if(ans==0)cout<<1<<endl;
        else cout<<ans<<endl;
    }
return 0;
}