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
        vector<int>arr(n),cnt(n+2,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]<=n)cnt[arr[i]]++;
        }

        int mex=0;
        while(cnt[mex]>0)mex++;

        vector<int>dif(n+2,0);
        for(int i=0;i<=mex;i++){
            int l=cnt[i];
            int r=n-i;
            if(l<=r){
                dif[l]++;
                if(r+1<=n){
                    dif[r+1]--;
                }
            }
        }

        vector<int>ans(n+1,0);
        if(n>=0) ans[0]=dif[0];
        for(int i=1;i<=n;i++){
            ans[i]=ans[i-1]+dif[i];
        }

        cout<<ans<<endl;
    }
return 0;
}