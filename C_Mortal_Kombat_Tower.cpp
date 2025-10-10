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
        int n;
        cin>>n;
        vector<int>arr(n);
        cin>>arr;
        vector<int> frnd(n+1);
        vector<int> me(n+1);
        frnd[n]=me[n]=0;

        for(int i=n-1;i>=0;i--){
            {
            frnd[i]=me[i+1]+arr[i];
            if(i+2<=n) frnd[i]=min(frnd[i],me[i+2]+arr[i]+arr[i+1]);
            }

            {
            me[i]=frnd[i+1];
            if(i+2<=n) me[i]=min(me[i],frnd[i+2]);
            }
        }

        cout<<frnd[0]<<endl;
    }
return 0;
}