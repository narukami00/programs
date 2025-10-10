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

int n, arr[100007],freq[100007],ans[100007];
int32_t main(){
    Flashyy
    //tc
    {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            freq[arr[i]]++;
        }
        ans[1]=freq[1];
        for(int i=2;i<100001;i++){
            ans[i]=max(ans[i-1],ans[i-2]+i*freq[i]);
        }
        cout<<ans[100000]<<endl;
    }
return 0;
}