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

const int MAX=1e15;
int32_t main(){
    Flashyy
    tc
    {
        int n,k;
        cin>>n>>k;
        vector<int>p(n),del(n);
        cin>>p;cin>>del;

        vector<pair<int,int>> indx(n),dis(n);

        for(int i=0;i<n;i++){
            if(i+1<n){
                indx[i].f=i+1;
                dis[i].f=p[i+1]-p[i];
            }else{
                indx[i].f=-1;
                dis[i].f=MAX;
            }

            if(i-1>=0){
                indx[i].s=i-1;
                dis[i].s=p[i]-p[i-1];
            }else{
                indx[i].s=-1;
                dis[i].s=p[i];
            }
        }

        vector<int> next(2*n*k,-1),state(2*n*k,0);
        for(int i=0;i<n;i++){
            for(int d=0;d<2;d++){
                for(int t=0;t<k;t++){
                    int s=(2*i+d)*k+t;

                    int cur=d;
                    if(t==del[i])cur^=1;

                    int dist;
                    if(cur==0)dist=dis[i].f;
                    else dist=dis[i].s;

                    int time=(t+(dist%k))%k;

                    int go;
                    if(cur==0)go=indx[i].f;
                    else go=indx[i].s;

                    if(go<0)next[s]=-1;
                    else next[s]=(2*go+cur)*k+time;
                }
            }
        }

        function<void(int)>dfs=[&](int u){
            state[u]=1;
            int v=next[u];
            if(v<0)state[u]=2;
            else if(state[v]==0){
                dfs(v);
                if(state[v]==2)state[u]=2;
                else state[u]=3;
            }else if(state[v]==1) state[u]=3;
            else{
                if(state[v]==2)state[u]=2;
                else state[u]=3;
            }
        };

        for(int u=0;u<2*n*k;u++)if(state[u]==0)dfs(u);

        int q;
        cin>>q;
        while(q--){
            int pos;
            cin>>pos;
            auto it=lower_bound(all(p),pos);
            if(it!=p.end() && *it==pos){
                int idx=it-p.begin();
                int st=2*idx*k;
                if(state[st]==2)yes;
                else no;
            }else{
                auto it1=lower_bound(all(p),pos+1);
                if(it1==p.end())yes;
                else{
                    int idx=it1-p.begin();
                    int dist=p[idx]-pos;
                    int time=dist%k;
                    int st=2*idx*k+time;
                    if(state[st]==2)yes;
                    else no;
                }
            }
        }
    }
return 0;
}