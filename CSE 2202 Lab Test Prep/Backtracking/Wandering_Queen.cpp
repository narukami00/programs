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

int dr[8]={-1,-1,-1,0,1,1,1,0};
int dc[8]={-1,0,1,1,1,0,-1,-1};

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        vector<string>grid(n);
        for(int i=0;i<n;i++)cin>>grid[i];

        pair<int,int>start,end;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='S')start={i,j};
                if(grid[i][j]=='F')end={i,j};
            }
        }

        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        q.push(start);
        dist[start.f][start.s]=0;

        while(!q.empty()){
            auto [r,c]=q.front();q.pop();
            for(int d=0;d<8;d++){
                int nr=r+dr[d],nc=c+dc[d];
                while(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='X'){
                    if(dist[nr][nc]!=-1 && dist[nr][nc]<=dist[r][c]){
                        break;
                    }
                    
                    if(dist[nr][nc]==-1){
                        dist[nr][nc]=dist[r][c]+1;
                        q.push({nr,nc});
                    }
                    nr+=dr[d];
                    nc+=dc[d];
                }
            }
        }
        cout<<dist[end.f][end.s]<<endl;
    }
return 0;
}