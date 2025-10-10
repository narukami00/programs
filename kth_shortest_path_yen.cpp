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

struct path
{
    vector<int>nodes;
    int cost;
};

string path_key(vector<int>&path){
    string s;
    for(auto it:path)s+=to_string(it)+"-";
    return s;
}

pair<int,vector<int>> dijkstra(int n, int src, int des, vector<vector<pair<int,int>>>&adj,const unordered_set<int>&rem_edge,const unordered_set<int>&rem_node){
    vector<int> dist(n,LLONG_MAX);
    vector<int>parent(n,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(d!=dist[u])continue;
        if(u==des)break;

        for(auto [v,w]:adj[u]){
            if(rem_node.count(v))continue;
            if(rem_edge.count((u<<32)|v))continue;

            if(dist[v]>d+w){
                dist[v]=d+w;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
    return {dist[des],parent};
}

vector<int> build_path(vector<int>&parent,int src,int des){
    vector<int>path;
    for(int v=des;v!=-1;v=parent[v]){
        path.pb(v);
        if(v==src)break;
    }
    if(path.back()!=src||path.size()==1)return {};
    reverse(all(path));
    return path;
}

vector<path> yens(int n, int src,int des, int K, vector<vector<pair<int,int>>>&adj){
    vector<path>res;

    auto [dist0,par0]=dijkstra(n,src,des,adj,{},{});
    if(dist0==LLONG_MAX)return res;
    res.pb({build_path(par0,src,des),dist0});

    auto cmp_path=[](const path&a,const path&b){
        if(a.cost!=b.cost)return a.cost>b.cost;
        return a.nodes>b.nodes;
    };

    priority_queue<path,vector<path>,decltype(cmp_path)>pq(cmp_path);
    unordered_set<string>seen;

    for(int k=1;k<K;k++){
        path& prev_path=res[k-1];
        int path_len=prev_path.nodes.size();

        for(int i=0;i<path_len-1;i++){
            int s_node=prev_path.nodes[i];
            vector<int>r_path(prev_path.nodes.begin(),prev_path.nodes.begin()+i+1); 
            int r_cost=0;

            for(int r=0;r+1<r_path.size();r++){
                int u=r_path[r],v=r_path[r+1];
                for(auto [x,w]:adj[u]){
                    if(x==v){
                        r_cost+=w;
                        break;
                    }
                }
            }

            unordered_set<int>rem_node,rem_edge;
            for(auto it:r_path)if(it!=s_node)rem_node.insert(it);

            for(path& p:res){
                if(p.nodes.size()>i && equal(r_path.begin(),r_path.end(),p.nodes.begin())){
                    int u=p.nodes[i],v=p.nodes[i+1];
                    rem_edge.insert((u<<32)|v);
                }
            }

            auto [s_dist,s_par]=dijkstra(n,s_node,des,adj,rem_edge,rem_node);
            if(s_dist==LLONG_MAX)continue;

            vector<int>s_path=build_path(s_par,s_node,des);
            if(s_path.empty())continue;

            vector<int>total_path=r_path;
            total_path.insert(total_path.end(),s_path.begin()+1,s_path.end());
            int total_cost=r_cost+s_dist;

            string key=path_key(total_path);
            bool dup=0;
            for(path&p:res){
                if(path_key(p.nodes)==key){
                    dup=1;
                    break;
                }
            }

            if(dup||seen.count(key))continue;

            pq.push({total_path,total_cost});
            seen.insert(key);
        }

        if(pq.empty())break;
        res.pb(pq.top());
        pq.pop();
    }

    return res;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,m,k;
        cin>>n>>m>>k;

        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        int src,des;
        cin>>src>>des;

        vector<path>res=yens(n,src,des,k,adj);

        if(res.empty()){
            cout<<-1<<endl;
            return 0;
        }

        for(int i=0;i<res.size();i++){
            cout<<"Path "<<i+1<<" : ";
            for(int j=0;j<res[i].nodes.size();j++){
                cout<<res[i].nodes[j];
                if(j+1<res[i].nodes.size())cout<<"->";
            }
            cout<<" | Cost : "<<res[i].cost<<endl;
        }

        if(res.size()<k){
            int i=k-res.size();
            int j=1;
            while(i--){
                cout<<"Path "<<res.size()+j<<" : -1"<<endl;
                j++;
            }
        }    
    }
return 0;
}