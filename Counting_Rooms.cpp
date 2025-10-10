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

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int n,m;
void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&vis){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];

        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='.'){
            dfs(nr,nc,grid,vis);
        }
    }
}

int32_t main(){
    Flashyy
    //tc
    {
        cin>>n>>m;
        vector<vector<char>>grid(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='.'){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }  
        }

        cout<<cnt<<endl;
    }
return 0;
}