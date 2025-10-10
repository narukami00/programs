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
#define sz(x) x.size()
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
        // int n;
        // cin >> n;
        // vector<int> arr(n);
        // cin>>arr;
        // sort(all(arr));
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     if(arr[i]+arr[i+1]<=arr[n-1])ans++;
        // }
        // cout<<ans<<endl;

        // int n;
        // cin >> n;
        // vector<int> arr(n);
        // for(auto &x : arr)
        //     cin >> x;
        // sort(all(arr));
        
        // int keep = 0;
        // int j = 0;
        // for(int i = 0; i < n; i++){
        //     while(j < n && arr[j] < 2 * arr[i]){
        //         j++;
        //     }
        //     int cnt = j - i;
        //     if(i == 0 || arr[i] != arr[i-1]){
        //         keep = max(keep, cnt);
        //     }
        // }
        
        // cout << n - keep << endl;

        int n;
        cin>>n;
        vector<int> arr(n);
        cin>>arr;
        sort(all(arr));

        int ans=n;
        for(int i=0;i+1<n;i++){
            int l=i+1,r=n-1,indx=i+1;
            while(l<=r){
                int mid=(l+r)/2;
                if(arr[i]+arr[i+1]>arr[mid]){
                    indx=mid,l=mid+1;
                }else r=mid-1;
            }

            ans=min(ans,n-(indx-i+1));
        }

        cout<<ans<<endl;
    }
return 0;
}