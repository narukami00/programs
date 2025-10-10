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

vector<int>edges[300005];
int dp[300005];
int indeg[300005];
vector<int>toposort;

int32_t main(){
    Flashyy
    //tc
    {
        int n,m;
        string s;
        cin>>n>>m>>s;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            --x,--y;
            edges[x].push_back(y);
            ++indeg[y];
        }
        queue<int>q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            ++cnt;
            int x=q.front();
            q.pop();
            toposort.push_back(x);

            for(int y:edges[x]){
                --indeg[y];
                if(indeg[y]==0)q.push(y);
            }
        }

        if(cnt<n){
            cout<<-1<<endl;
            return 0;
        }

        int ans=0;
        for(char c='a';c<='z';c++){
            memset(dp,0,sizeof(dp));
            for(int x:toposort){
                if(s[x]==c)++dp[x];
                for(int y:edges[x]){
                    dp[y]=max(dp[y],dp[x]);
                }
                ans=max(ans,dp[x]);
            }
        }
        cout<<ans<<endl;
    }
return 0;
}