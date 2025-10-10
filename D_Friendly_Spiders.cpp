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
        int n;
        cin>>n;
        vector<int>a(n+1);
        int mx=0;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            mx=max(mx,a[i]);
        }

        int s,t;
        cin>>s>>t;
        if(s==t){
            cout<<1<<endl<<s<<endl;
            return 0;
        }

        vector<int>spf(mx+1);
        for(int i=2;i<=mx;i++){
            if(spf[i]==0){
                for(int j=i;j<=mx;j+=i){
                    if(spf[j]==0)spf[j]=i;
                }
            }
        }

        vector<vector<int>>facs(n+1);
        vector<vector<int>>box(mx+1);
        for(int i=1;i<=n;i++){
            int x=a[i];
            while(x>1){
                int p=spf[x];
                facs[i].push_back(p);
                while(x%p==0)x/=p;
            }
            for(int p:facs[i]){
                box[p].push_back(i);
            }
        }

        vector<int>par(n+1,-1);
        vector<bool>vis(n+1,0);
        queue<int>q;
        vis[s]=1;
        q.push(s);

        while(!q.empty()){
            int u=q.front();q.pop();
            for(int p:facs[u]){
                auto &vec=box[p];
                for(int v:vec){
                    if(!vis[v]){
                        vis[v]=1;
                        par[v]=u;
                        if(v==t){
                            vector<int>path;
                            int cur=t;
                            while(cur!=-1){
                                path.push_back(cur);
                                cur=par[cur];
                            }
                            reverse(all(path));
                            cout<<sz(path)<<endl;
                            for(int id:path){
                                cout<<id<<sp;
                            }
                            cout<<endl;
                            return 0;
                        }
                        q.push(v);
                    }
                }
                vec.clear();
            }
        }
        
        cout<<-1<<endl;
    }
return 0;
}