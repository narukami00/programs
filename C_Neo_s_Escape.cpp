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
        int n;
        cin>>n;
        vector<int>arr(n);
        cin>>arr;
        unordered_map<int,stack<int>>pos;
        for(int i=0;i<n;i++){
            pos[arr[i]].push(i);
        }
        vector<int>vis(n,0);
        vector<int>temp=arr;
        sort(rall(temp));
        temp.erase(unique(all(temp)), temp.end());
        int ans=0;
        set<int>cango;
        for(int i=0;i<n;i++){
            int cur=temp[i];
            vector<int>loc;
            while(!pos[cur].empty()){
                loc.pb(pos[cur].top());
                pos[cur].pop();
            }
            sort(all(loc));
            int p=0;
            while(p<sz(loc)){
                int next=p;
                while(next<sz(loc)-1 && loc[next+1]==loc[next]+1)next++;

                bool f=0;
                for(int k=p;k<=next;k++){
                    if(cango.count(loc[k])){
                        f=1;
                        break;
                    }
                }

                if(!f)ans++;

                for(int k=p;k<=next;k++){
                    vis[loc[k]]=1;
                    cango.erase(loc[k]);
                    if(loc[k]>0 && vis[loc[k]-1]==0)cango.insert(loc[k]-1);
                    if(loc[k]<n-1 && vis[loc[k]+1]==0)cango.insert(loc[k]+1);
                }

                p=next+1;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}