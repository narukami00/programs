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
        cout << it ;
    return ostream;
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>>grid(n,vector<char>(m));
        int sr=0,sc=0,er=0,ec=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='A'){
                    sr=i;
                    sc=j;
                }
                if(grid[i][j]=='B'){
                    er=i;
                    ec=j;
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        char ops[]={'U','R','D','L'};
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{sr,sc},0});
        vis[sr][sc] = 1;

        vector<vector<pair<int,int>>>par(n,vector<pair<int,int>>(m,{-1,-1}));
        vector<vector<char>>mov(n,vector<char>(m,' '));

        bool pos=0;
        int dis=0;

        while(!q.empty()){
            int r=q.front().f.f;
            int c=q.front().f.s;
            int d=q.front().s;
            q.pop();

            if(r==er && c==ec){
                pos=1;
                dis=d;
                break;
            }
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='#' && !vis[nr][nc]){ 
                    vis[nr][nc]=1;
                    par[nr][nc]={r,c};
                    mov[nr][nc]=ops[i];
                    q.push({{nr,nc},d+1});
                }
            }
        }

        if(!pos)no;
        else{
            yes;
            cout<<dis<<endl;
            vector<char>path;
            int nr=er,nc=ec;
            for(int i=0;i<dis;i++){
                path.pb(mov[nr][nc]);
                auto it=par[nr][nc];
                nr=it.f;
                nc=it.s;
            }
            reverse(all(path));
            cout<<path<<endl;
        }
    }
return 0;
}