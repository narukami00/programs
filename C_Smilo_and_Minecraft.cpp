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

int fun(int n,int m, vector<vector<int>>&pre,int r1,int c1,int r2,int c2){
    r1=max(r1,0ll);c1=max(c1,0ll);
    r2=min(r2,n-1);c2=min(c2,m-1);
    if(r1>r2 || c1>c2)return 0;
    return pre[r2+1][c2+1]-pre[r1][c2+1]-pre[r2+1][c1]+pre[r1][c1];
}

int32_t main(){
    Flashyy
    tc
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<string>grid(n);
        cin>>grid;

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='g')ans++;
            }
        }

        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i+1][j+1]=pre[i][j+1]+pre[i+1][j]-pre[i][j]+(grid[i][j]=='g');
            }
        }

        int best=ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='.'){
                    best=min(best,fun(n,m,pre,i-k+1,j-k+1,i+k-1,j+k-1));
                }
            }
        }

        cout<<ans-best<<endl;
    }
return 0;
}