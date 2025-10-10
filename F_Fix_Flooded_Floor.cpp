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

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<string>grid(2);
        for(int i=0;i<2;i++)cin>>grid[i];

        vector<vector<bool>> covered(2,vector<bool>(n,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='#'){
                    covered[i][j]=1;
                }
            }
        }

        bool mul=0,pos=1;

        for(int c=0;c<n;c++){
            bool top=covered[0][c];
            bool bottom=covered[1][c];

            if(top && bottom)continue;
            else if(top!=bottom){
                int r=(top?1:0);
                if(c+1>=n || covered[r][c+1]){
                    pos=0;
                    break;
                }
                covered[r][c]=1;
                covered[r][c+1]=1;
            }else{
                if(c+1<n){
                    if(!covered[0][c+1] && !covered[1][c+1]){
                        mul=1;
                    }
                }
                covered[0][c]=1;
                covered[1][c]=1;
            }
        }

        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                if(!covered[i][j]){
                    pos=0;
                    break;
                }
            }
        }
        if(!pos)cout<<"None\n";
        else if(mul)cout<<"Multiple\n";
        else cout<<"Unique\n";
    }
return 0;
}