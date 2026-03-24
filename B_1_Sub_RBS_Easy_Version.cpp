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
    tc
    {
        int n;string s;
        cin>>n>>s;

        vector<int>nxt(n+1,-1),cnt(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')nxt[i]=i;
            else nxt[i]=nxt[i+1];

            if(s[i]=='(')cnt[i]=1;
            cnt[i]+=cnt[i+1];
        }

        int ans=-1;
        for(int i=0;i<n;i++){
            if(s[i]==')' && nxt[i]!=-1){
                int p=nxt[i]-i;
                if(cnt[nxt[i]+1]>=p){
                    ans=max(ans,n-2*p);
                }
            }
        }

        cout<<ans<<endl;
    }
return 0;
}