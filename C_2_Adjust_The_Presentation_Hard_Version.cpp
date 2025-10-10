#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"TIDAK\n"
#define yes cout<<"YA\n"
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
        int n,m,q;
        cin>>n>>m>>q;

        vector<int>pos(n+1);
        for(int i=1;i<=n;i++){
            int x;cin>>x;pos[x]=i;
        }

        vector<int>b(m+1);
        int f=0;

        vector<set<int>>st(n+1);
        for(int i=1;i<=n;i++){
            st[i].insert(m+i);
        }

        for(int i=1;i<=m;i++){
            cin>>b[i];
            b[i]=pos[b[i]];
            st[b[i]].insert(i);
        }

        auto fun=[&](int i){
            if(i==0 || i==n+1)return 0;
            if(i>1 && *st[i].begin()<*st[i-1].begin())return 0;
            if(i<n && *st[i].begin()>*st[i+1].begin())return 0;
            return 1;
        };

        for(int i=1;i<=n;i++)f+=fun(i);
        if(f==n)yes;
        else no;

        while(q--){
            int x,y;cin>>x>>y;
            y=pos[y];
            int t=b[x];
            set<int>valid{b[x]-1,b[x],b[x]+1,y-1,y,y+1};
            for(auto it:valid)f-=fun(it);

            st[b[x]].erase(x);
            b[x]=y;
            st[b[x]].insert(x);
            for(auto it:valid)f+=fun(it);

            if(f==n)yes;
            else no;
        }
    }
return 0;
}