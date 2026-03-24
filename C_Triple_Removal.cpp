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
        int n,q;
        cin>>n>>q;
        vector<int>a(n);
        cin>>a;
        vector<pair<int,int>>pre(n,{0,0});
        vector<int>diff(n,0),diffsum(n,0);
        for(int i=0;i<n;i++){
            if(a[i]==0)pre[i].first++;
            else pre[i].second++;
            if(i>0){
                pre[i].first += pre[i-1].first;
                pre[i].second += pre[i-1].second;
                if(a[i]!=a[i-1])diff[i]=1;
                diffsum[i]=diffsum[i-1]+diff[i];
            }
        }

        while(q--){
            int l,r;
            cin>>l>>r;
            --l;r--;
            int zero=pre[r].first-(l>0?pre[l-1].first:0);
            int one=pre[r].second-(l>0?pre[l-1].second:0);
            if(zero%3!=0 || one%3!=0){
                cout<<"-1\n";
                continue;
            }
            int ans=one/3+zero/3;
            if(diffsum[r]-diffsum[l]==r-l)ans++;
            cout<<ans<<endl;
        }
    }
return 0;
}