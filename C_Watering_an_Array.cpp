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
        int n,k,d;
        cin>>n>>k>>d;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        vector<int>days(k);
        for(int i=0;i<k;i++) cin>>days[i];
        int ans=0;
        for(int i=0;i<min(2*n+1,d);i++){
            int res=0;
            for(int j=1;j<=n;j++){
                if(arr[j]==j)res++;
            }
            ans=max(ans,res+(d-i-1)/2);
            for(int j=1;j<=days[i%k];j++)arr[j]++;
        }
        
        cout<<ans<<endl;
    }
return 0;
}