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

int fun(vector<int>&arr){
    int n=sz(arr);
    vector<bool>vis(n,0);
    int par=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int len=0;
            int cur=i;
            while(!vis[cur]){
                vis[cur]=1;
                cur=arr[cur]-1;
                len++;
            }
            par^=((len-1)&1);
        }
    }
    return par;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n),odd,even;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if((i+1)%2==0)even.pb(a[i]);
            else odd.pb(a[i]);
        }
        sort(all(odd));sort(all(even));
        for(int i=0,o=0,e=0;i<n;i++){
            if((i+1)%2==0)b[i]=even[e++];
            else b[i]=odd[o++];
        }
        int p1=fun(a),p2=fun(b);
        if(p1!=p2)swap(b[n-1],b[n-3]);
        cout<<b<<endl;
    }
return 0;
}