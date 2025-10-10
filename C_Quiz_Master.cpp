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
        vector<int>arr(n);
        cin>>arr;
        sort(all(arr));

        vector<vector<int>>divs(n);
        for(int i=0;i<n;i++){
            int x=arr[i];
            for(int d=1;d*d<=x;d++){
                if(x%d==0){
                    if(d<=m)divs[i].pb(d);
                    if((x/d)!=d && (x/d)<=m)divs[i].pb(x/d);
                }
            }
        }

        vector<int>cnt(m+1,0);
        int need=m;
        int l=0,ans=LLONG_MAX;

        for(int r=0;r<n;r++){
            for(int div:divs[r]){
                if(cnt[div]==0)need--;
                cnt[div]++;
            }
            while(need==0 && l<=r){
                ans=min(ans,arr[r]-arr[l]);
                for(int div:divs[l]){
                    cnt[div]--;
                    if(cnt[div]==0)need++;
                }
                l++;
            }
        }
        
        if(ans==LLONG_MAX)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
return 0;
}