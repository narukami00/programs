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
        vector<int>ans(n+1);
        ans[n]=1;
        for(int i=1;i<=n;i++){
            cout<<"? ";
            for(int j=1;j<n;j++)cout<<n<<sp;
            cout<<i<<endl;
            cout.flush();
            int t;
            cin>>t;
            if(t){
                ans[n]=n-i+1;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<"? ";
            for(int j=1;j<n;j++)cout<<ans[n]<<sp;
            cout<<i<<endl;
            cout.flush();
            int t;
            cin>>t;
            ans[t]=i;
        }
        cout<<"! ";
        for(int i=1;i<=n;i++)cout<<ans[i]<<sp;
        cout<<endl;
        cout.flush();
    }
return 0;
}