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
    int n,case_no=1;
    while(cin>>n && n)
    {
        vector<pair<int,int>>stones(n);
        for(int i=0;i<n;i++)cin>>stones[i].f>>stones[i].s;
        vector<double>d(n,1e9);
        vector<bool>vis(n,false);
        d[0]=0;
        for(int i=0;i<n;i++){
            double mn=1e9;
            int u=-1;
            for(int j=0;j<n;j++){
                if(!vis[j] && d[j]<mn){
                    mn=d[j];
                    u=j;
                }
            }
            vis[u]=1;
            for(int v=0;v<n;v++){
                if(!vis[v]){
                    double dx=stones[u].f-stones[v].f;
                    double dy=stones[u].s-stones[v].s;
                    double dist=sqrt(dx*dx+dy*dy);
                    d[v]=min(d[v],dist);
                }
            }
        }
        cout<<"Scenario #"<<case_no++<<"\n";
        cout<<"Frog Distance = "<<fixed<<setprecision(3)<<d[1]<<"\n";
    }
return 0;
}