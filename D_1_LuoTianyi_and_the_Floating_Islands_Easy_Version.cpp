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

const int mod=1e9+7;
int modexp(int base, int exp) {
    int res = 1;
    while(exp) {
        if(exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int inv(int x) {
    return modexp(x, mod - 2);
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        if(k==1 || k==3){
            cout<<1<<endl;
            return 0;
        }

        vector<int>par(n+1,0),order;
        stack<int>st;
        st.push(1);
        par[1]=-1;
        while(!st.empty()){
            int u=st.top();st.pop();
            order.pb(u);
            for(int v:adj[u]){
                if(v!=par[u]){
                    par[v]=u;
                    st.push(v);
                }
            }
        }

        vector<int>sub(n+1,1);
        int sum=0;
        for(int i=n-1;i>=0;i--){
            int u=order[i];
            if(par[u]>0){
                int a=sub[u];
                int b=n-a;
                sum=(sum+a%mod*(b%mod))%mod;
                sub[par[u]]+=sub[u];
            }
        }
        int d=n*(n-1)%mod;
        int id=inv(d);
        int f=sum*2%mod*id%mod;
        int ans=(1+f)%mod;
        cout<<ans<<endl;
    }
return 0;
}