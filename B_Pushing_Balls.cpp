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
        int n,m;
        cin>>n>>m;
        vector<string> arr(n);
        vector<bool>c(m);
        for(int i=0;i<n;i++)cin>>arr[i];

        bool f=1;
        for(int i=0;i<n;i++){
            bool r=0;
            for(int j=0;j<m;j++){
                if(arr[i][j]=='0')r=c[j]=1;
                else if(r && c[j])f=0;
            }
        }
        if(f)yes;
        else no;
    }
return 0;
}