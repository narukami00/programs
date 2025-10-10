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
#define f first
#define s second
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

vector<int> sieve(int n=1e7) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    if(n >= 0) isPrime[0] = false;
    if(n >= 1) isPrime[1] = false;
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int32_t main(){
    Flashyy
    vector<int> primes = sieve();
    vector<int>pre(sz(primes) + 1, 0);
    for(int i = 0; i < sz(primes); i++)pre[i+1] = pre[i] + primes[i];
    tc
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        cin>>arr;
        sort(rall(arr));
        vector<int>prea(n+1,0);
        for(int i=0;i<n;i++)prea[i+1] = prea[i] + arr[i];

        int l=0,r=n,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(prea[mid]>=pre[mid]) {ans=n-mid;l=mid+1;}
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
return 0;
}