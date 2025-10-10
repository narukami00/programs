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

struct dsu{
    int n;
    vector<int> sizes,marks;
    vector<vector<int>> graph;

    void init(int rn){
        n=rn;
        sizes=vector<int>(n);
        fill(sizes.begin(),sizes.end(),1);
        marks=vector<int>(n);
        for(int i=0;i<n;i++)marks[i]=i;
        graph=vector<vector<int>>(n);
    }

    void mark(int m,int node){
        if(marks[node]==m) return;
        marks[node]=m;
        for(int i:graph[node])mark(m,i);
    }

    void merge(int a,int b){
        if(marks[a]==marks[b]) return;
        graph[a].push_back(b);
        graph[b].push_back(a);

        if(sizes[marks[a]]>sizes[marks[b]])swap(a,b);

        sizes[marks[b]]+=sizes[marks[a]];
        sizes[marks[a]]=0;
        mark(marks[b],a); 
    }

    int find(int n){return marks[n];}
};

int32_t main(){
    Flashyy
    tc
    {
        int n,a,b;
        cin>>n>>a>>b;
        --a,--b;
        vector<pair<int,int>>edges(n);
        for(int i=0;i<n;i++){
            cin>>edges[i].f>>edges[i].s;
            edges[i].f--;edges[i].s--;
        }
        
        dsu d;
        d.init(n);
        pair<int,int>extra={-1,-1};
        for(auto &e:edges){
            int u=e.f,v=e.s;
            if(d.find(u)==d.find(v)){
                extra={u,v};
            }else d.merge(u,v);
        }
        int u=extra.f,v=extra.s;

        vector<vector<int>>tree(n);
        for(auto &e:edges){
            if((e.f==u && e.s==v)||(e.f==v && e.s==u))continue;
            tree[e.f].pb(e.s);
            tree[e.s].pb(e.f);
        }

        vector<int>par(n,-1);
        queue<int>q;
        par[u]=u;
        q.push(u);
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int y:tree[x]){
                if(par[y]==-1){
                    par[y]=x;
                    q.push(y);
                }
            }
        }

        vector<bool>incyc(n,0);
        int cur=v;
        while(1){
            incyc[cur]=1;
            if(cur==u)break;
            cur=par[cur];
        }

        vector<vector<int>>adj(n);
        for(auto &e:edges){
            adj[e.f].pb(e.s);
            adj[e.s].pb(e.f);
        }

        auto bfs=[&](int src){
            vector<int>dis(n,-1);
            queue<int>q;
            dis[src]=0;
            q.push(src);
            while(!q.empty()){
                int x=q.front();q.pop();
                for(auto y:adj[x]){
                    if(dis[y]==-1){
                        dis[y]=dis[x]+1;
                        q.push(y);
                    }
                }
            }
            return dis;
        };

        if(a==b){no;continue;}
        auto da=bfs(a),db=bfs(b);
        int en=-1,best=LLONG_MAX;
        for(int i=0;i<n;i++){
            if(incyc[i] && db[i]>=0 && db[i]<best){
                best=db[i];
                en=i;
            }
        }
        if(en==-1 || da[en]<=best)no;
        else yes;
    }
return 0;
}