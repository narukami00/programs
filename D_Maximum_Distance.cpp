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

    bool merge(int a,int b){
        if(marks[a]==marks[b]) return 0;
        graph[a].push_back(b);
        graph[b].push_back(a);

        if(sizes[marks[a]]>sizes[marks[b]])swap(a,b);

        sizes[marks[b]]+=sizes[marks[a]];
        sizes[marks[a]]=0;
        mark(marks[b],a); 
        return 1;
    }

    int find(int n){return marks[n];}
};

int n,m,k,ans=0;
const int temp_arr_size=1e6+9097;
int b[temp_arr_size];
vector<pair<int, pair<int,int>>>elist;
vector<pair<int,int>>edges[100005];
dsu d;

int dp[100005];
int spec[100005];

void dfs(int v,int p,int wt){
    dp[v]=spec[v];

    for(auto x:edges[v]){
        if(x.first!=p){
            dfs(x.first,v,x.second);
            dp[v]+=dp[x.first];
        }
    }

    if(min(dp[v],k-dp[v])>0)ans=max(ans,wt);

}

int32_t main(){
    Flashyy
    //tc
    {
        cin>>n>>m>>k;
        d.init(n);
        for(int i=0;i<k;i++){
            cin>>b[i];
            --b[i];
            spec[b[i]]=1;
        }

        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            --u,--v;
            elist.pb({w,{u,v}});
        }
        sort(all(elist));

        for(auto x:elist){
            if(d.merge(x.second.first,x.second.second)){
                edges[x.second.first].pb({x.second.second,x.first});
                edges[x.second.second].pb({x.second.first,x.first});
            }
        }

        dfs(0,-1,0);
        for(int i=0;i<k;i++)cout<<ans<<sp;
    }
return 0;
}