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

struct dsu{
    vector<int>par,sz;

    dsu(int n){
        par.resize(n+1);
        sz.resize(n+1,1);
        for(int i=1;i<=n;i++)par[i]=i;
    }

    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }

    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(sz[a]<sz[b])swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }

    bool same(int a, int b){
        return find(a)==find(b);
    }
};

int32_t main(){
    Flashyy
    //tc
    {
        int n,q;
        cin>>n>>q;
        dsu d(n);

        while(q--){
            int t,a,b;
            cin>>t>>a>>b;
            if(t==1)d.merge(a,b);
            else{
                if(d.same(a,b))yes;
                else no;
            }
        }
    }
return 0;
}