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

        vector<vector<pair<int,int>>>edges(n+1);
        for(int i=0;i<m;i++){
            int a,b,d;
            cin>>a>>b>>d;
            edges[a].pb({b,d});
            edges[b].pb({a,-d});
        }

        vector<bool>vis(n+1,0);
        vector<int>pos(n+1,0);
        bool f=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                queue<int>q;
                vis[i]=1;
                pos[i]=0;
                q.push(i);
                while(!q.empty() && f){
                    int cur=q.front();
                    q.pop();
                    for(auto &edge:edges[cur]){
                        int nxt=edge.f;
                        int dis=edge.s;
                        if(!vis[nxt]){
                            vis[nxt]=1;
                            pos[nxt]=pos[cur]+dis;
                            q.push(nxt);
                        }else{
                            if(pos[nxt]!=pos[cur]+dis){
                                f=0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(f)yes;
        else no;
    }
return 0;
}