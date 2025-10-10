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

bool fun(auto x,auto y){
    if(x.f>y.f)swap(x,y);
    return x.s>y.f && x.s<y.s;
}

int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>lines;
        vector<bool>used(2*n+1,0);
        for(int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            if(x>y)swap(x,y);
            lines.pb({x,y});
            used[x]=used[y]=1;
        }
        vector<int>unused;
        for(int i=1;i<=2*n;i++)if(!used[i])unused.pb(i);
        for(int i=0;i<n-k;i++)lines.pb({unused[i],unused[i+n-k]});
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans+=fun(lines[i],lines[j]);
            }
        }
        cout<<ans<<endl;
    }
return 0;
}