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

vector<int> primes;
void sieve(int N = 1e7) {
    primes.assign(N + 1, 0);
    for (int i = 0; i < N; i++)
        primes[i] = i;
    for (int i = 2; i * i <= N; i++)
        if (primes[i] == i)
            for (int j = i * i; j <= N; j += i)
                primes[j] = min(primes[j], i);
}


void solve(){
    int n;
    cin>>n;
    int x=n/3-1;
    if(x<=0){
        for(int i=1;i<=n;i++)cout<<i<<sp;
        cout<<endl;
        return;
    }

    vector<int> ans;
    for(int i=x;i<n/2+1;i++){
        if(i!=1 && primes[i]==i){
            for(int j=1;j<i+1;j++){
                ans.push_back(j);
                if(i!=j)ans.push_back(2*i-j);
            }
            for(int j=2*i;j<n+1;j++)ans.push_back(j);
            cout<<ans<<endl;
            return;
        }
    }
}
int32_t main(){
    Flashyy
    sieve(2e5);
    tc
    {
        solve();
    }
return 0;
}