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

vector<int> fun(vector<int>&p){
    int n=sz(p);
    vector<int> q(n,0);
    vector<int>odd,even;

    for(int i=0;i<n;i++){
        if((i+1)&1)odd.pb(i);
        else even.pb(i);
    }

    sort(all(odd),[&](int i,int j){
        return p[i]<p[j];
    });

    sort(all(even),[&](int i,int j){
        return p[i]>p[j];
    });

    vector<int>big,smol;
    for(int x=n/2+1;x<=n;x++)big.pb(x);
    for(int x=1;x<=n/2;x++)smol.pb(x);

    for(int i=0;i<sz(odd);i++)q[odd[i]]=big[sz(big)-i-1];
    for(int i=0;i<sz(even);i++)q[even[i]]=smol[i];

    return q;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>p(n);
        int mxpos=-1;
        for(int i=0;i<n;i++){
            cin>>p[i];
            if(p[i]==n)mxpos=i+1;
        }
        vector<int>q;
        if(mxpos&1){
            q=fun(p);
        }else{
            reverse(all(p));
            q=fun(p);
            reverse(all(q));
        }
        cout<<q<<endl;
    }
return 0;
}