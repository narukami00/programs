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
        int n,l,r;
        cin>>n>>l>>r;
        int arr[n],copy[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            copy[i]=arr[i];
        }
        int j=r-l+1;
        sort(arr,arr+r);
        sort(copy+l-1,copy+n);
        int sum1=0,sum2=0;
        for(int i=0;i<j;i++){
            sum1+=arr[i];
            sum2+=copy[i+l-1];
        }
        cout<<min(sum1,sum2)<<endl;
    }
return 0;
}