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
#define sz(x) x.sz()
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
vector<int> adj[150005];
int label[150005];
int sz[150005];
int nedges[150005];

void relabel(int v, int target){
    if(label[v]==target) return;
    label[v]=target;
    for(auto it:adj[v]){
        relabel(it,target);
    }
}

void merge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

    int cu=label[u],cv=label[v];
    ++nedges[cu];

    if(cu==cv) return;
    if(sz[cu]>sz[cv]){
        swap(u,v);
        swap(cu,cv);
    }

    relabel(u,cv);
    sz[cv]+=sz[cu];
    nedges[cv]+=nedges[cu];
}

int32_t main(){
    Flashyy
    //tc
    {
        int n,m;cin>>n>>m;
        for(int i=0;i<n;i++){
            sz[i]=1;
            label[i]=i;
        }

        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            --u,--v;
            merge(u,v);
        }

        bool pos=1;
        for(int i=0;i<n;i++){
            if(nedges[label[i]]!=sz[label[i]]*(sz[label[i]]-1)/2){
                pos=0;
            }
        }

        if(pos)yes;
        else no;

    }
return 0;
}