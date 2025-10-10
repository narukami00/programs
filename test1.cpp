// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define double long double
// #define endl '\n'
// #define no cout<<"NO\n"
// #define yes cout<<"YES\n"
// #define sp " "
// #define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
// #define all(x) x.begin(), x.end()
// #define rall(x) x.rbegin(), x.rend()
// #define sz(x) x.size()
// #define f first
// #define s second
// #define pb push_back
// #define eb emplace_back

// template <typename T>
// istream &operator>>(istream &istream, vector<T> &v)
// {
//     for (auto &it : v)
//         cin >> it;
//     return istream;
// }
// template <typename T>
// ostream &operator<<(ostream &ostream, const vector<T> &c)
// {
//     for (auto &it : c)
//         cout << it << " ";
//     return ostream;
// }

// struct dijkstra {
//     int n;
//     const int inf = 4e18;
//     vector<int> dists; /* for a single run */
//     vector<int> par;
//     vector<bool> vis;
//     vector<vector<pair<int, int> > > edges; /* weight, to */
    
//     void init(int s) {
//       n = s;
//       dists = vector<int>(n);
//         vis = vector<bool>(n);
//       par = vector<int>(n);
//       edges = vector<vector<pair<int, int> > >(n);
//     }
  
//     void edge(int a, int b, int wt) {
//       edges[a].push_back(make_pair(wt, b));
//       edges[b].push_back(make_pair(wt, a));
//     }
  
//     using ptype = pair<int, int>;
//     void run(int src) {
//       fill(dists.begin(), dists.end(), inf);
//         fill(vis.begin(), vis.end(), false);
//       fill(par.begin(), par.end(), -1);
  
//       priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
//       dists[src] = 0;
//       pq.push(make_pair(0, src));
//       while (!pq.empty()) {
//         ptype foc = pq.top();
//         pq.pop();
        
//           if (vis[foc.s]) continue;
//           vis[foc.s] = 1;
        
//         dists[foc.s] = min(dists[foc.s], foc.f);
//         for (ptype x: edges[foc.s]) {
//           int d = dists[foc.s] + x.f;
//           if (d < dists[x.s]) {
//             dists[x.s] = d;
//             par[x.s] = foc.s;
//             pq.push(make_pair(d, x.s));
//           }
//         }
//       }
//     }
//   };

// int32_t main(){
//     Flashyy
//     //tc
//     {
//         dijkstra dj;
//         dj.init(5); 
//         dj.edge(0, 1, 10);
//         dj.edge(0, 2, 3);
//         dj.edge(1, 2, 1);
//         dj.edge(1, 3, 2);
//         dj.edge(2, 3, 8);
//         dj.edge(3, 4, 7);
    
//         dj.run(0); 
    
//         for (int i = 0; i < 5; i++) {
//             cout << "Dist to " << i << " = " << dj.dists[i] << '\n';
//         }

//     }
// return 0;
// }

for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = (i == j ? 0 : INF);
for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    dist[u][v] = min(dist[u][v], w); 
}
for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (dist[i][k] < INF && dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);