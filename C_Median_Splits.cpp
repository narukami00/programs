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
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        cin>>arr;
        for(int i=0;i<n;i++){
            if(arr[i]<=k)arr[i]=1;
            else arr[i]=-1;
        }

        int op=2;
        bool f=0;
        while(op--){
            reverse(all(arr));
            vector<int>pre(n);
            pre[0]=arr[0];
            for(int i=1;i<n;i++)pre[i]=pre[i-1]+arr[i];
            int pos=-1;
            for(int i=0;i<n-1;i++){
                if(pos>=0){
                    if(pre[i]-pre[pos]>=0 || pre[n-1]-pre[i]>=0){
                        f=1;
                        break;
                    }
                }
                if(pre[i]>=0){
                    if(pos==-1 || pre[i]<pre[pos])pos=i;
                }
            }
            if(f)break;
        }

        if(f)yes;
        else no;
    }
return 0;
}