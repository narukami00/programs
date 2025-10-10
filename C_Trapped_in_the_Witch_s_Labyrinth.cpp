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
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;
        string arr[n+1];

        for(int i=1;i<=n;i++){
            cin>>arr[i];
            arr[i]= "-" + arr[i];
        }

        vector<pair<int,int>> dir[n+2][m+2];

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(arr[i][j]=='U') dir[i-1][j].push_back({i,j});
                if(arr[i][j]=='R') dir[i][j+1].push_back({i,j});
                if(arr[i][j]=='D') dir[i+1][j].push_back({i,j});
                if(arr[i][j]=='L') dir[i][j-1].push_back({i,j});
                
            }
        }

        int vis[n+2][m+2]={};

        queue<pair<int,int>> q;

        for(int j=0;j<=m+1;j++) vis[0][j]=1,q.push({0,j});
        for(int i=0;i<=n+1;i++) vis[i][0]=1,q.push({i,0});
        for(int j=0;j<=m+1;j++) vis[n+1][j]=1,q.push({n+1,j});
        for(int i=1;i<=n;i++) vis[i][m+1]=1,q.push({i,m+1});

        while(q.size()){
            auto [i,j] = q.front();
            q.pop();
            for(auto [a,b]: dir[i][j]){
                if(vis[a][b]==0){
                    vis[a][b]=1;
                    q.push({a,b});
                }
            }
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j]=='?' && vis[i-1][j] && vis[i+1][j] && vis[i][j-1] && vis[i][j+1]){
                    vis[i][j]=1;
                }
            }
        }
        int ans=n*m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==1) ans--;
            }
        }
        cout<<ans<<endl;
        
    }
return 0;
}