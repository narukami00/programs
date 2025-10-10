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

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int findGCD(const std::vector<int>& arr) {
    int result = arr[0];
    for (const int& num : arr) {
        result = gcd(result, num);
        if (result == 1) {
            return 1; 
        }
    }
    return result;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int findLCM(const std::vector<int>& arr) {
    int result = arr[0];
    for (const int& num : arr) {
        result = lcm(result, num);
    }
    return result;
}

int rsum(int x, int y){
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        int ans=0,m=2*n;
        for(int i=1;i<=n;i++)ans+=(2*i-1)*i;
        cout<<ans<<sp<<m<<endl;

        for(int i=n;i>=1;i--){
            cout<<1<<sp<<i<<sp;
            for(int j=1;j<=n;j++)cout<<j<<sp;cout<<endl;
            cout<<2<<sp<<i<<sp;
            for(int j=1;j<=n;j++)cout<<j<<sp;cout<<endl;
        }
        
    }
return 0;
}