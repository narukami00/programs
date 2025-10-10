#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
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
int l1,l2,r1,r2;
int binary_search(int x,int t){
    int l=(l2+t-1)/t,r=min(x,r2/t);
    return r<l ? 0 : r-l+1;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    tc
    {
        int k,ans=0;
        cin>>k>>l1>>r1>>l2>>r2;
        for(int i=k;i<=r2;i*=k){
           ans+=binary_search(r1,i)-binary_search(l1-1,i); 
        }
        ans+=binary_search(r1,1)-binary_search(l1-1,1);
        cout<<ans<<endl;
    }
return 0;
}