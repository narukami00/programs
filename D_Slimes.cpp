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
        vector<int>arr(n);
        cin>>arr;
        vector<int>ans(n,n);
        int pre=2;
        while(pre--){
            vector<int>pref(n+1);
            for(int i=0;i<n;i++)pref[i+1]=pref[i]+arr[i];
            vector<int>valid(n,-1);
            for(int i=1;i<n;i++){
                int indx=(pre==1?i:n-i-1);
                int l=1,r=i;
                while(l<=r){
                    int m=(l+r)/2;
                    if(pref[i]-pref[i-m]>arr[i] && valid[i-1]>=i-m){
                        ans[indx]=min(ans[indx],m);
                        r=m-1;
                    }else l=m+1;
                }
                if(arr[i-1]>arr[i])ans[indx]=1;
                if(arr[i]==arr[i-1])valid[i]=valid[i-1];
                else valid[i]=i-1;
            }
            reverse(all(arr));
        }
        for(int i=0;i<n;i++)if(ans[i]==n)ans[i]=-1;
        cout<<ans<<endl;
    }
return 0;
}