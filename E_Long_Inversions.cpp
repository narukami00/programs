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

bool pos(string s, int n, int k){
    vector<int> flips(n,0);
    int cur=0;
    for(int i=0;i<=n-k;i++){
        if(i>=k)cur^=flips[i-k];
        int eff=(s[i]-'0')^cur;
        if(eff==0){
            flips[i]=1;
            cur^=1;
        }
    }
    for(int i=n-k+1;i<n;i++){
        if(i>=k)cur^=flips[i-k];
        int eff=(s[i]-'0')^cur;
        if(eff==0) return false;
    }
    return true;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=1;
        for(int k=n;k>=1;k--){
            if(pos(s,n,k)){
                ans=k;break;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}