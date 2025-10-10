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

map<int,int> dp;
int n,a[200005],ans,cur;
vector<int>arr;

int32_t main(){
    Flashyy
    //tc
    {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);

            if(dp[a[i]]>ans){
                ans=dp[a[i]];
                cur=a[i];
            }
        }
        cout<<ans<<endl;
        for(int i=n-1;i>=0;i--){
            if(a[i]==cur){
                cur--;
                arr.push_back(i);
            }
        }
        reverse(all(arr));
        for(auto it:arr)cout<<it+1<<sp;
        cout<<endl;
    }
return 0;
}