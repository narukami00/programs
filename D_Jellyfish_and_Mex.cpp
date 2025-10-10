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
const int N=5005;
const int inf=1e18;
int arr[N],dp[N];
int n,m;

int32_t main(){
    Flashyy
    tc
    {
        for(int i=0;i<N;i++){
            arr[i]=0;
            dp[i]=inf;
        }n=0,m=0;

        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(x<n)arr[x]++;
        }
        while(arr[m])m++;
        dp[m]=0;
        for(int i=m;i>=1;i--){
            for(int j=0;j<i;j++){
                dp[j]=min(dp[j],dp[i]+i*(arr[j]-1)+j);
            }
        }
        cout<<dp[0]<<endl;
    }
return 0;
}