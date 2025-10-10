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
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++)cin>>arr[i];

        vector<bool>vis(n+1,0);
        int two=0,ntwo=0;

        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                int cur=i;
                vector<int>chain;
                while(1){
                    vis[cur]=1;
                    chain.pb(cur);
                    int nxt=arr[cur];
                    if(vis[nxt]==0){
                        cur=nxt;
                        continue;
                    }
                    int cycle=-1;
                    for(int j=0;j<sz(chain);j++){
                        if(chain[j]==nxt){
                            cycle=j;
                            break;
                        }
                    }
                    if(cycle!=-1){
                        int len=sz(chain)-cycle;
                        if(len==2)two++;
                        else ntwo++;
                    }
                    for(int node:chain)vis[node]=1;
                    break;
                }
            }
        }
        int mn=ntwo+(two>0?1:0);
        int mx=ntwo+two;
        cout<<mn<<sp<<mx<<endl;
    }
return 0;
}