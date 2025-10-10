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
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>edges(m);
        vector<int>deg(n+1,0);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges[i]={u,v};
            deg[u]++;
            deg[v]++;
        }
        if(m==n*(n-1)/2){
            cout<<3<<endl;
            for(int i=0;i<m;i++){
                auto [u,v]=edges[i];
                int a=(u==1||v==1);
                int b=(u==2||v==2);
                cout<<((a|(b<<1))%3 +1)<<sp;
            }
            cout<<endl;
        }else{
            cout<<2<<endl;
            int p=1;
            while(deg[p]==n-1)p++;
            for(int i=0;i<m;i++){
                auto [u,v]=edges[i];
                cout<<((u==p||v==p)?1:2)<<sp;
            }
            cout<<endl;
        }
    }
return 0;
}