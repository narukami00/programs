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

int n;
const int mx=500+3;
int arr[mx][mx];
int vis[mx][mx];

bool check(int i, int j){
    if(i>=0 && i<n && j>=0 && j<n)return true;
    return false;
}

vector<pair<int,int>> nxt={{0,1},{1,0},{0,-1},{-1,0}};

int fun(int i, int j){
    int mini=arr[i][j];
    pair<int,int> minip;

    for(int k=0;k<4;k++){
        int x=i+nxt[k].first;
        int y=j+nxt[k].second;
        if(check(x,y)){
            if(arr[x][y]<mini){
                mini=arr[x][y];
                minip.first=x;
                minip.second=y;
            }
        }
    }

    if(mini!=arr[i][j]){
        if(vis[minip.first][minip.second]!=0){
            vis[i][j]=vis[minip.first][minip.second];
        }else{
            vis[i][j]=fun(minip.first,minip.second);
        }
    }else{
        vis[i][j]=mini;
    }
    return vis[i][j];
}

int32_t main(){
    Flashyy
    //tc
    {
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    fun(i,j);
                }
            }
        }
        int q;
        cin>>q;
        while(q--){
            int i,j;
            cin>>i>>j;
            cout<<vis[i-1][j-1]<<endl;
        }
    }
return 0;
}