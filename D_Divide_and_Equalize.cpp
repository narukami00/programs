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

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    if(n >= 0) isPrime[0] = false;
    if(n >= 1) isPrime[1] = false;
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}


int32_t main(){
    Flashyy
    tc
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        cin>>arr;
        vector<int>prim=sieve(1000);
        unordered_map<int,int> exp;

        for(auto it: arr){
            int temp=it;
            for(auto p:prim){
                if(p*p>temp) break;
                int cnt=0;
                while(temp%p==0){
                    cnt++;
                    temp/=p;
                }
                if(cnt>0){
                    exp[p]+=cnt;
                }
            }
            if(temp>1){
                exp[temp]++;
            }
        }
        bool pos=1;
        for(auto &it:exp){
            if(it.second%n!=0){
                pos=0;
                break;
            }
        }

        if(pos)yes;
        else no;
    }
return 0;
}