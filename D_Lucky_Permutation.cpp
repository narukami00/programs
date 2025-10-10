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

struct dsu {
  int n;
  vector<int> sizes, marks, nedges;
  vector<vector<int> > graph;

  void init(int rn) {
    n = rn;
    sizes = vector<int>(n);
    nedges = vector<int>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<int>(n);
    for (int i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<int> >(n);
  }

  void mark(int m, int node) {
    if (marks[node] == m) return;

    marks[node] = m;

    for (int i: graph[node]) mark(m, i);
  }

  void merge(int a, int b) {
    if (marks[a] == marks[b]) {
        nedges[marks[b]] ++;
        return;
    }
    graph[a].push_back(b);
    graph[b].push_back(a);

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);

    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    nedges[marks[b]] += (nedges[marks[a]] + 1);
    nedges[marks[a]] = 0;
    mark(marks[b], a);
  }

  int find(int n) { return marks[n]; }
};

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto &i:a){cin>>i;i--;}
        dsu d;
        d.init(n);
        for(int i=0;i<n;i++)d.merge(i,a[i]);

        vector<bool>vis(n,0);
        int cyc=0;
        for(int i=0;i<n;i++){
            int id=d.find(i);
            if(!vis[id]){
                vis[id]=1;
                cyc++;
            }
        }

        bool f=0;
        for(int i=1;i<n;i++){
            if(d.find(i-1)==d.find(i)){
                f=1;
                break;
            }
        }

        int ans;
        if(f)ans=n-cyc-1;
        else ans=n-cyc+1;

        cout<<ans<<endl;
    }
return 0;
}