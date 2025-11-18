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

        auto msa=[&](int n,int root,vector<tuple<int,int,int>>&edges,vector<int>&real)->int
        {
            int total=0;
            vector<int>par(n,-1);

            while(1){
                vector<int>in(n,inf);
                vector<int>pre(n,-1);
                for(auto &[u,v,w]:edges){
                    if(u!=v && w<in[v]){
                        in[v]=w;
                        pre[v]=u;
                        real[v]=u;
                    }
                }

                in[root]=0;
                pre[root]=root;

                for(int i=0;i<n;i++)if(in[i]==inf){
                    return -1;
                }

                int cntCyc=0;
                vector<int>id(n,-1),vis2(n,-1);

                for(int i=0;i<n;i++)total+=in[i];

                for(int i=0;i<n;i++){
                    int v=i;
                    while(vis2[v]!=i && id[v]==-1 && v!=root){
                        vis2[v]=i;
                        v=pre[v];
                    }
                    if(id[v]==-1 && v!=root){
                        for(int u=pre[v];u!=v;u=pre[u]){
                            id[u]=cntCyc;
                        }
                        id[v]=cntCyc++;
                    }
                }

                if(cntCyc==0){
                    par=pre;
                    return total;
                }

                for(int i=0;i<n;i++){
                    if(id[i]==-1){
                        id[i]=cntCyc++;
                    }
                }

                vector<tuple<int,int,int>>edges2;
                for(auto &[u,v,w]:edges){
                    int uu=id[u];
                    int vv=id[v];
                    if(uu!=vv){
                        edges2.pb({uu,vv,w-in[v]});
                    }
                }

                edges=edges2;
                n=cntCyc;
                root=id[root];
            }
        };

        vector<int>real(n,-1);
        vector<tuple<int,int,int>>orig_edges=edges;
        int res=msa(n,root_id,edges,real);

        if(res<0){
            cout<<"Root: "<<root<<endl;
            cout<<"No directed spanning aborescence exists (some nodes are unreachable)."<<endl;
        }

        cout<<"Root: "<<root<<endl;
        cout<<"Edges:\n";

        int total=0;
        for(int v=0;v<n;v++){
            if(v==root_id)continue;
            int u=real[v];
            if(u==-1)continue;

            int w=inf;
            for(auto &[uu,vv,ww]:orig_edges){
                if(u==uu && v==vv){
                    w=ww;
                    break;
                }
            }

            total+=w;
            cout<<rid[u]<<" -> "<<rid[v]<<" ( "<<w<<" )"<<endl;
        }
        
        cout<<"Total cost: "<<total<<endl;
    }
return 0;
}