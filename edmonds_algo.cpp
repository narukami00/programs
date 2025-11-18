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

const int inf=1e15;

int32_t main(){
    Flashyy
    //tc
    {
        int n,m;char root;
        cin>>n>>m>>root;
        vector<tuple<int,int,int>>edges(m);
        map<char,int>id;
        map<int,char>rid;
        int idx=0;
        for(int i=0;i<m;i++){
            char u,v;
            int w;
            cin>>u>>v>>w;
            if(!id.count(u)){id[u]=idx;rid[idx]=u;idx++;}
            if(!id.count(v)){id[v]=idx;rid[idx]=v;idx++;}
            edges[i]={id[u],id[v],w};
        }n=idx;

        int root_id=id[root];
        vector<vector<pair<int,int>>>adj(n);
        for(auto &[u,v,w]:edges)adj[u].pb({v,w});

        vector<int>vis(n,0);
        queue<int>q;
        q.push(root_id);
        vis[root_id]=1;
        
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto &[v,w]:adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cout<<"Root: "<<root<<endl;
                cout<<"No directed spanning aborescence exists (some nodes are unreachable)."<<endl;
                return 0;
            }
        }

        vector<tuple<int,int,int>>o_edges=edges;
        map<pair<int,int>,int>edge_w;
        for(auto &[u,v,w]:o_edges){
            edge_w[{u,v}]=w;
        }
        
        int total=0;
        int o_n=n;
        
        map<int,pair<int,int>>sel; 
        
        vector<tuple<int,int,int,int,int>>w_edges;
        for(auto &[u,v,w]:edges){
            w_edges.pb({u,v,w,u,v});
        }
        
        while(1){
            vector<int>in(n,inf);
            vector<int>pre(n,-1);
            vector<pair<int,int>>edge_for(n,{-1,-1});  
            
            for(auto &[u,v,w,ou,ov]:w_edges){
                if(u!=v && w<in[v]){
                    in[v]=w;
                    pre[v]=u;
                    edge_for[v]={ou,ov};
                }
            }
            
            in[root_id]=0;
            pre[root_id]=root_id;
            
            for(int i=0;i<n;i++){
                if(in[i]==inf){
                    cout<<"Root: "<<root<<endl;
                    cout<<"No directed spanning aborescence exists (some nodes are unreachable)."<<endl;
                    return 0;
                }
            }
            
            for(int i=0;i<n;i++)total+=in[i];
            
            int cntCyc=0;
            vector<int>id(n,-1),vis(n,-1);
            
            for(int i=0;i<n;i++){
                int v=i;
                while(vis[v]!=i && id[v]==-1 && v!=root_id){
                    vis[v]=i;
                    v=pre[v];
                }
                if(id[v]==-1 && v!=root_id){
                    for(int u=pre[v];u!=v;u=pre[u]){
                        id[u]=cntCyc;
                    }
                    id[v]=cntCyc++;
                }
            }
            
            for(int v=0;v<n;v++){
                if(v!=root_id && edge_for[v].f!=-1){
                    int ov=edge_for[v].s;  
                    sel[ov]=edge_for[v];
                }
            }
            
            if(cntCyc==0){
                break;
            }
            
            for(int i=0;i<n;i++){
                if(id[i]==-1){
                    id[i]=cntCyc++;
                }
            }
            
            vector<tuple<int,int,int,int,int>>nw_edges;
            for(auto &[u,v,w,ou,ov]:w_edges){
                int uu=id[u];
                int vv=id[v];
                if(uu!=vv){
                    nw_edges.pb({uu,vv,w-in[v],ou,ov});
                }
            }
            
            w_edges=nw_edges;
            n=cntCyc;
            root_id=id[root_id];
        }
        
        cout<<"Root: "<<root<<endl;
        cout<<"Edges:\n";
        
        int res=0;
        for(auto &[ov,edge]:sel){
            auto [u,vv]=edge;
            int w=edge_w[{u,vv}];
            res+=w;
            cout<<rid[u]<<" -> "<<rid[vv]<<" ("<<w<<")"<<endl;
        }
        
        cout<<"Total cost: "<<res<<endl;
    }
return 0;
}