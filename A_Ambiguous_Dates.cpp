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

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    // tc
    {
        int n;
        cin>>n;
        int ara[n+1]={0};
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            // if(v[i]<n)
            // ara[v[i]]++;
            // else {
            //     ara[n]++;
            // }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i]<n)
            ara[v[i]]++;
            else {
                ara[n]++;
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<ara[i]<<" ";
        // }
        for(int i=n-1;i>=1;i--){
            ara[i]+=ara[i+1];
        }
        // for(int i=1;i<=n;i++){
        //     cout<<ara[i]<<" ";
        // }
        long long ans=0;
        for(int i=0;i<n;i++){
            int take= min(n,ara[i+1]);
        
            take=min(v[i],take);
            if(i!=0){
                take = min(v[i-1],take);
            }
            // cout<<take<<" ";
            if(take-1>0){
                
                ans+=take-1;
                // cout<<ans<<
            }
        }
        // cout<<endl;
        cout<<ans<<endl;
    }
return 0;
}