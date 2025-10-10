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
        vector<int> arr(n);
        cin>>arr;
        int ans=0;
        if(k>1){
            sort(rall(arr));
            for(int i=0;i<k+1;i++){
                ans+=arr[i];
            }
        }else{
            int first=*max_element(arr.begin(),arr.end()-1);
            int last=*max_element(arr.begin()+1,arr.end());
            ans=max(arr[n-1]+first,arr[0]+last);
        }
        cout<<ans<<endl;
    }
return 0;
}