#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define FastAF ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    FastAF
    tc
    {
        int n,k,c=0,s=0,f=1;
        cin>>n>>k;
        vector<int> arr(n);
        cin>>arr;
        sort(all(arr));
        reverse(all(arr));
        for(int i=1;i<n;i++){
            arr[i]=arr[i]+arr[i-1];
        }
        for(int i=0;i<n;i++){
            if(arr[i]==k) {c=0; break;}
            else if(arr[i]>k){c=k-arr[i-1];break;}
            else if(i==n-1)c=k-arr[i];
        }
        
        cout<<c<<endl;

    }
return 0;
}