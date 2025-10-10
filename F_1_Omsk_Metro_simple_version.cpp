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

const int N=2e5+5;
int par[N],sum[N],premn[N],premx[N],low[N],high[N];

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        int cnt=1;
        par[1]=0,sum[1]=1,premn[1]=0,premx[1]=1,low[1]=1,high[1]=1;

        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            if(c=='+'){
                int v,x;
                cin>>v>>x;
                cnt++;
                par[cnt]=v;
                sum[cnt]=sum[v]+x;

                premn[cnt]=min(premn[v],sum[cnt]);
                premx[cnt]=max(premx[v],sum[cnt]);

                low[cnt]=min(low[v],sum[cnt]-premx[v]);
                high[cnt]=max(high[v],sum[cnt]-premn[v]);
            }else{
                int u,v,k;
                cin>>u>>v>>k;
                bool ans=0;
                if(k==0)ans=1;
                else{
                    if(k>=low[v] && k<=high[v]){
                        ans=1;
                    }
                }
                if(ans)yes;
                else no;
            }
        }
    }
return 0;
}