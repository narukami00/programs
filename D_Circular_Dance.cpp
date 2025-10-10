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
    //tc
    {
        int n;
        cin>>n;
        vector<pair<int,int>>arr(n+1);
        vector<bool>vis(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>arr[i].f>>arr[i].s;
        }
        cout<<1<<sp;vis[1]=1;
        for(int i=1,j=1;j<n;j++){
            int n1=arr[i].f;
            int n2=arr[i].s;

            if((arr[n1].f==n2 || arr[n1].s==n2) && !vis[n1]){
                cout<<n1<<sp;
                i=n1;
                vis[n1]=1;
            }else{
                cout<<n2<<sp;
                i=n2;
                vis[n2]=1;
            }
        }
        cout<<endl;
    }
return 0;
}