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
        int n,k;
        cin>>n>>k;

        vector<vector<int>>adj(n+1);
        vector<int>indeg(n+1,0);

        vector<vector<int>>ss(k,vector<int>(n));
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                cin>>ss[i][j];
            }
        }

        for(int i=0;i<k;i++){
            for(int j=1;j<n-1;j++){
                int u=ss[i][j];
                int v=ss[i][j+1];
                adj[u].pb(v);
                indeg[v]++;
            }
        }

        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            for(int v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        if(cnt==n)yes;
        else no;
    }
return 0;
}