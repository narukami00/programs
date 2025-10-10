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

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n,-1));

        int x=(n%2?n/2:n/2-1);
        int y=x;
        int val=0;
        grid[x][y]=val++;
        int step=1;
        int dir=0;
        
        while(val<n*n){
            for(int i=0;i<2 && val<n*n;i++,dir=(dir+1)&3){
                for(int j=0;j<step && val<n*n;j++){
                    x+=dx[dir],y+=dy[dir];
                    grid[x][y]=val++;
                }
            }
            step++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<sp;
            }cout<<endl;
        }
    }
return 0;
}