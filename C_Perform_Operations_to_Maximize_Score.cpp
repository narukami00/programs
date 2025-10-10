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
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i].f;
        for(int i=0;i<n;i++)cin>>arr[i].s;

        sort(all(arr));
        int ans=0;

        for(int i=0;i<n;i++){
            if(arr[i].s==1){
                int med;
                if(i<n/2){
                    med=arr[n/2].f;
                }else med=arr[(n-2)/2].f;

                ans=max(ans,arr[i].f+k+med);
            }
        }

        int l=0,r=2e9;
        while(l!=r){
            int mid=(l+r+1)/2;
            int z=0;
            vector<int>small;
            for(int i=0;i<n-1;i++){
                if(arr[i].f>=mid)z++;
                else if(arr[i].s==1){
                    small.pb(mid-arr[i].f);
                }
            }
            
            reverse(all(small));
            int tk=k;
            for(auto x:small){
                if(tk>=x){
                    tk-=x;
                    z++;
                }
            }

            if(z>=(n+1)/2)l=mid;
            else r=mid-1;
        }
        
        ans=max(ans,arr[n-1].f+l);
        cout<<ans<<endl;
    }
return 0;
}