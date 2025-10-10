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

int32_t main(){
    Flashyy
    tc
    {
        int n,q;
        cin>>n>>q;
        vector<int> arr(n+1),x(q+1);

        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<=q;i++) cin>>x[i];
        int mini=30;
        for(int i=1;i<=q;i++){
            if(x[i]>=mini){
                continue;
            }
            mini=x[i];
            for(int j=1;j<=n;j++){
                if(arr[j] % (1<<x[i]) == 0){
                    arr[j]+=(1<<(x[i]-1));
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<arr[i]<<sp;
        }
        cout<<endl;

    }
return 0;
}