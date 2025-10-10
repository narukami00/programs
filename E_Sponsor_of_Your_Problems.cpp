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
        string l,r;
        cin>>l>>r;
        int n=sz(l);

        int dp[10][2][2];
        dp[n][0][0]=0;
        dp[n][0][1]=0;
        dp[n][1][0]=0;
        dp[n][1][1]=0;

        for(int p=n-1;p>=0;p--){
            int ldig=l[p]-'0';
            int rdig=r[p]-'0';

            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    int best=LLONG_MAX;
                    int L=i?ldig:0;
                    int R=j?rdig:9;

                    for(int dig=L;dig<=R;dig++){
                        int cost=(dig==ldig)+(dig==rdig);
                        int fl=i&&(dig==ldig);
                        int fr=j&&(dig==rdig);

                        best=min(best,cost+dp[p+1][fl][fr]);
                    }

                    dp[p][i][j]=best;
                }
            }
        }
        
        cout<<dp[0][1][1]<<endl;
    }
return 0;
}