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

char mat[52][52];
int dp[52][52][52][52];

int32_t main(){
    Flashyy
    //tc
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>mat[i][j];
            }
        }

        vector<vector<int>>pref(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+(mat[i][j]=='#');
            }
        }

        auto black=[&](int x1,int y1,int x2,int y2){
            int sum=pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
            return sum>0;
        };

        for(int h=1;h<=n;h++){
            for(int w=1;w<=n;w++){
                for(int x1=1;x1<=n-h+1;x1++){
                    for(int y1=1;y1<=n-w+1;y1++){
                        int x2=x1+h-1,y2=y1+w-1;
                        if(!black(x1,y1,x2,y2))dp[x1][y1][x2][y2]=0;
                        else{
                            dp[x1][y1][x2][y2]=max(h,w);
                            for(int xm=x1;xm<x2;xm++){
                                dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],dp[x1][y1][xm][y2]+dp[xm+1][y1][x2][y2]);
                            }
                            for(int ym=y1;ym<y2;ym++){
                                dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],dp[x1][y1][x2][ym]+dp[x1][ym+1][x2][y2]);
                            }
                        }
                    }
                }
            }
        }

        cout<<dp[1][1][n][n]<<endl;
    }
return 0;
}