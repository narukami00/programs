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
        int n;
        cin>>n;
        vector<int> arr(n);
        cin>>arr;
        sort(all(arr));
        int sum=0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                sum=2*arr[i];
                arr[i]=0,arr[i-1]=0;
                break;
            }
        }
        sort(all(arr));
        int f=1;
        for(int i=n-1;i>=3;i--){
            if(sum+arr[i-1]>arr[i]){
                cout<<sum/2<<sp<<sum/2<<sp<<arr[i-1]<<sp<<arr[i]<<endl;
                f=0;
                break;
            }
        }
        if(f)cout<<-1<<endl;
    }
return 0;
}