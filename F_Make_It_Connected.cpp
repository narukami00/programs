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

int n,m,ans=0;
const int temp_arr_size=1e6+9097;
int a[temp_arr_size];
vector<pair<int, pair<int,int>>>elist;
dsu d;


int32_t main(){
    Flashyy
    //tc
    {
        cin>>n>>m;
        d.init(n);

        for(int i=0;i<n;i++)cin>>a[i];

        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            --u,--v;
            elist.pb({w,{u,v}});
        }

        int mnv=1e18,mnpos=-1;
        for(int i=0;i<n;i++){
            if(a[i]<mnv){
                mnv=a[i];
                mnpos=i;
            }
        }

        for(int i=0;i<n;i++)elist.pb({mnv+a[i],{mnpos,i}});
        sort(all(elist));
        for(auto x:elist){
            if(d.merge(x.second.first,x.second.second)){
                ans+=x.first;
            }
        }

        cout<<ans<<endl;;
    }
return 0;
}