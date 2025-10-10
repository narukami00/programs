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
    //tc
    {
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;

        char p[6][3]={{'a','b','c'},{'a','c','b'},{'b','a','c'},{'b','c','a'},{'c','a','b'},{'c','b','a'}};
        int cost[n+1][6];
        for(int i=0;i<6;i++)cost[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<6;j++){
                char need=p[j][(i-1)%3];
                cost[i][j]=cost[i-1][j]+(s[i-1]!=need);
            }
        }

        while(m--){
            int l,r;
            cin>>l>>r;
            int ans=LLONG_MAX;
            for(int i=0;i<6;i++){
                int cnt=cost[r][i]-cost[l-1][i];
                ans=min(ans,cnt);
            }
            cout<<ans<<endl;
        }
    }
return 0;
}