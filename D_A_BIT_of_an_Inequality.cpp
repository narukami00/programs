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

const int Z=30;
const int MAX=1e5+3;
int pre[Z][MAX][2],suf[Z][MAX][2];

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];

        for(int i=0;i<Z;i++){
            suf[i][n+1][0]=0;
            suf[i][n+1][1]=0;
        }

        for(int i=0;i<Z;i++){
            for(int j=1;j<=n;j++){
                int t=!!(arr[j] & (1<<i));
                for(int k=0;k<2;k++){
                    pre[i][j][k]=(t==k)+pre[i][j-1][k^t];
                }
            }
            for(int j=n;j>=1;j--){
                int t=!!(arr[j] & (1<<i));
                for(int k=0;k<2;k++){
                    suf[i][j][k]=(t==k)+suf[i][j+1][k^t];
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            int z=31-__builtin_clz(arr[i]);
            ans+=(pre[z][i-1][1])*(1+suf[z][i+1][0]);
            ans+=(1+pre[z][i-1][0])*(suf[z][i+1][1]);
        }

        cout<<ans<<endl;
    }
return 0;
}