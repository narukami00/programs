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
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(m);
        cin>>a>>b;
        priority_queue<int>pqa,pqb;
        for(int i=0;i<n;i++)pqa.push(a[i]);
        for(int i=0;i<m;i++)pqb.push(b[i]);

        bool x=0;
        while(!pqa.empty() && !pqb.empty()){
            if(x==0){
                x=1;
                int u=pqa.top();
                int v=pqb.top();
                if(u>=v){
                    pqb.pop();
                }else{
                    pqb.pop();
                    pqb.push(v-u);
                }
            }else{
                x=0;
                int u=pqa.top();
                int v=pqb.top();
                if(v>=u){
                    pqa.pop();
                }else{
                    pqa.pop();
                    pqa.push(u-v);
                }
            }
        }

        if(pqa.empty())cout<<"Bob\n";
        else cout<<"Alice\n";
    }
return 0;
}