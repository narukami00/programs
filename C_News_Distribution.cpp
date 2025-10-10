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
        int n,m;
        cin>>n>>m;
        vector<vector<int>>adj(n+1);
        vector<int> vis(n+1,0);
        vector<int>ans(n);
        for(int i=0;i<m;i++){
            int k;
            cin>>k;
            vector<int> arr(k);
            for(int j=0;j<k;j++){
                cin>>arr[j];
                --arr[j];
            }
            for(int j=0;j+1<k;j++){
                adj[arr[j]].push_back(arr[j+1]);
                adj[arr[j+1]].push_back(arr[j]);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> cmp; 

                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();

                    if(vis[node]) continue;
                    vis[node]=1;
                    cmp.push_back(node);
                    for(auto it: adj[node]){
                        if(!vis[it]){
                            q.push(it);
                        }
                    }
                }
                for(auto it: cmp) {
                    ans[it]=cmp.size();
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}