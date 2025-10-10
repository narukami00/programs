// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n,s=0;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++)cin>>arr[i];
//     bool p=true;
//     for(int i=1;i<n;i++){
//         if(abs(arr[i]-arr[i-1])>1 && arr[i]<arr[i-1]){p=false;break;}
//     }
//     if(p)cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;
// }
// int main(){
//     int t; cin >> t;
//     while(t--) solve();
//     return 0;
// }
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
        bool f=1;
        for(int i=0;i<n;i++){
            if(abs(arr[i]-(i+1))>1){
                f=0;
                break;
            }
        }
        if(f)yes;
        else no;

    }
return 0;
}