#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)



int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int extra=0;
        int f=1;
        sort(all(arr));
        // for(int i=0;i<n;i++){
        //     if(mp[arr[i]]>=2){
        //         extra=mp[arr[i]]-2;
        //         mp[arr[i]+1]+=extra;
                
        //     }else{
        //         f=0;
        //         break;
        //     }
        // }
        int min=arr[0];
        int max=arr[n-1];
        for(int i=min;i<=max;i++){
            if(mp[i]>=2){
                extra=mp[i]-2;
                mp[i+1]+=extra;
            }else if(mp[i]==0){
                
            }
            else{
                f=0;
                break;
            }
        }
        if(f)yes;
        else no;
    }
return 0;
}