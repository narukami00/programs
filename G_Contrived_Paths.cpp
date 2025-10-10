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
#define sz(x) x.size()
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

int n,m,k;
vector<pair<int,int>>edges[100005];
int dis[100005];
bool vis[100005];

void dijkstra(int src){
    for(int i=0;i<n;i++){dis[i]=1e18;vis[i]=0;}

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    dis[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        pair<int,int> cur=pq.top();
        pq.pop();

        int dist=cur.first,targ=cur.second;
        if(vis[targ])continue;

        vis[targ]=1;
        for(pair<int,int>x:edges[targ]){
            int ndist=dist+x.second;
            if(ndist<dis[x.first]){
                dis[x.first]=ndist;
                pq.push({dis[x.first],x.first});
            }
        }

    }
}
int32_t main(){
    Flashyy
    //tc
    {

        cin>>n>>m>>k;
        vector<int>arr(n);
        cin>>arr;

        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            --x,--y;
            edges[x].pb({y,z});
            edges[y].pb({x,z});
        }

        for(int  i=0;i<n;i++){
            edges[i].pb({n,arr[i]});
            edges[n].pb({i,arr[i]});
        }
        n++;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            x--;
            dijkstra(x);
            for(int j=0;j<n-1;j++)cout<<dis[j]<<sp;
            cout<<endl;
        }
    }
return 0;
}