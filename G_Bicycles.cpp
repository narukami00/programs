#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    tc
    {
        int n,m; //nodes, edges
        cin>>n>>m;
        vector<pair<int,int>> v[n];
        for(int i=0;i<m;i++){
            int x,y,w; //node1, node2, weight
            cin>>x>>y>>w;
            x--,y--; //0 base index
            v[x].push_back({y,w});
            v[y].push_back({x,w}); //undirected
        }

        int slow[n];
        for(int i=0;i<n;i++)cin>>slow[i]; //slowness of bikes at each node

        vector<vector<int>> vis(n,vector<int>(n,0));

        vector<vector<int>> time(n,vector<int>(n,1e16)); //time it took to go from starting node to any other node using any bike
        time[0][0]=0;

        set<pair<pair<int,int>,int>> st; //time ,vertex ,bike
        st.insert({{0,0},0});

        //Modified Dijkstra
        while(st.size()>0){
            auto node= *st.begin();
            int prev_time=node.first.first;
            int vertex=node.first.second;
            int bike=node.second;
            st.erase(st.begin());
            if(vis[vertex][bike]==1)continue; //already 1 means it's been minimized before
            vis[vertex][bike]=1;

            for(auto child:v[vertex]){
                int wt=child.second;
                int new_vertex=child.first; //new vertex has a new bike
                if(slow[bike]<slow[new_vertex]){ //use same bike 
                    if(prev_time+slow[bike]*wt<time[new_vertex][bike]){
                        time[new_vertex][bike]=prev_time+slow[bike]*wt;
                        st.insert({{time[new_vertex][bike],new_vertex},bike});
                    }
                }
                else{ //change bike
                    if(prev_time+slow[bike]*wt<time[new_vertex][new_vertex]){
                        time[new_vertex][new_vertex]=prev_time+slow[bike]*wt;
                        st.insert({{time[new_vertex][new_vertex],new_vertex},new_vertex});
                    }
                }
            }
        }

        int ans=1e16;
        for(int i=0;i<n;i++){
            ans=min(ans,time[n-1][i]); //'i'th bike got us to the end vertex. Take the time which is minimum
        }
        cout<<ans<<endl;
    }
return 0;
}