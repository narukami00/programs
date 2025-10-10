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
        int n;
        cin>>n;
        set<pair<int,int>> adj;
        vector<int> deg(n+1);

        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj.insert(make_pair(u,v));
            adj.insert(make_pair(v,u));
            deg[u]++;
            deg[v]++;
        }

        int ans=0;
        vector<pair<int,int>> b;
        for(int i=0;i<n;i++){
            b.push_back(make_pair(deg[i+1],i+1));
        }
        sort(all(b),greater<pair<int,int>>());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(adj.find(make_pair(b[i].second,b[j].second))==adj.end()){
                    ans=max(ans,b[j].first+b[i].first-1);
                    break;
                }
            }
        }

        for(auto it:adj){
            ans=max(ans,deg[it.first]+deg[it.second]-2);
        }
        cout<<ans<<endl;
    }
return 0;
}