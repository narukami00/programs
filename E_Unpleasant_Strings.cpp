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
    //tc
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<vector<int>>nxt(n+2,vector<int>(k,-1));
        vector<int>last(k,-1);
        for(int i=n-1;i>=0;i--){
            last[s[i]-'a']=i;
            for(int j=0;j<k;j++){
                nxt[i][j]=last[j];
            }
        }
        
        vector<int>dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            dp[i]=LLONG_MAX;
            for(int j=0;j<k;j++){
                if(nxt[i][j]==-1){
                    dp[i]=1;
                }else{
                    dp[i]=min(dp[i],1+dp[nxt[i][j]+1]);
                }
            }
        }

        int q;
        cin>>q;
        while(q--){
            string t;
            cin>>t;
            int p=0;
            bool f=0;
            for(char c:t){
                if(nxt[p][c-'a']==-1){
                    f=1;
                    break;
                }
                p=nxt[p][c-'a']+1;
            }
            if(f)cout<<0<<endl;
            else cout<<dp[p]<<endl;
        }
    }
return 0;
}