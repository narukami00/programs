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
        int  n;
        cin>>n;
        vector<string>genre(n),writer(n),vals;

        for(int i=0;i<n;i++){
            cin>>genre[i]>>writer[i];
            vals.pb(genre[i]);
            vals.pb(writer[i]);
        }

        sort(all(vals));
        vals.erase(unique(all(vals)),vals.end());

        vector<int>gid(n),wid(n);
        for(int i=0;i<n;i++){
            gid[i]=lower_bound(all(vals),genre[i])-vals.begin();
            wid[i]=lower_bound(all(vals),writer[i])-vals.begin();
        }   

        int mx=1<<n;
        vector<vector<bool>>dp(mx,vector<bool>(n,0));

        for(int i=0;i<n;i++){
            dp[1<<i][i]=1;
        }

        for(int k=0;k<mx;k++){
            for(int i=0;i<n;i++){
                if(!dp[k][i])continue;

                for(int j=0;j<n;j++){
                    if(k & (1<<j))continue;

                    if(gid[i]==gid[j] || wid[i]==wid[j]){
                        dp[k|(1<<j)][j]=1;
                    }
                }
            }
        }

        int best=0;
        for(int i=0;i<mx;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]){
                    best=max(best,(int)__builtin_popcountll(i));
                }
            }
        }

        cout<<n-best<<endl;
    }
return 0;
}