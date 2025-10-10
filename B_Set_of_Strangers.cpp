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

int arr[705][705];

int32_t main(){
    Flashyy
    tc
    {
        int n,m;
        cin>>n>>m;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>arr[i][j];
            }
        }

        set<int> c,b;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i-1][j]==arr[i][j] || arr[i][j-1]==arr[i][j]) b.insert(arr[i][j]);
                c.insert(arr[i][j]);
            }
        }

        int ans=c.size()-1;
        if(!b.empty()){
            ans+=(b.size()-1);
        }
        
        cout<<ans<<endl;

    }
return 0;
}