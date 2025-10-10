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
    //tc
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>a(n);
        bool valid[26]={0};

        for(int i=0;i<k;i++){
            char c;
            cin>>c;
            valid[c-'a']=1;
        }

        for(int i=0;i<n;i++){
            if(valid[s[i]-'a'])a[i]=1;
            else a[i]=0;
        }
        int dp[n+1];
        int ans=0;

        dp[0]=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)dp[i+1]=0;
            else dp[i+1]=dp[i]+1;

            ans+=dp[i+1];
        }
        cout<<ans<<endl;
    }
return 0;
}