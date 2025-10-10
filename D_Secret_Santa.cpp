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
        vector<int>arr(n),ans(n,-1);
        vector<bool>vis(n,0);
        map<int,int>mp;
        cin>>arr;


        int best=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                if(!vis[arr[i]-1]){
                    ans[i]=arr[i];
                    vis[arr[i]-1]=1;
                    best++;
                    mp[ans[i]]=i;
                }
            }
        }

        deque<int>not_vis;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                not_vis.pb(i+1);
            }
        }

        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                if(not_vis.front()!=i+1){
                    ans[i]=not_vis.front();
                    not_vis.pop_front();
                }else if(not_vis.back()!=i+1){
                    ans[i]=not_vis.back();
                    not_vis.pop_back();
                }else{
                    ans[mp[arr[i]]]=not_vis.front();
                    not_vis.pop_front();
                    ans[i]=arr[i];
                }
            }
        }

        cout<<best<<endl;
        cout<<ans<<endl;
    }
return 0;
}