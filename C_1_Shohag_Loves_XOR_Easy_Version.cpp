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

vector<int> divis(int n) {
    vector<int> divs;
    for (int i = 1; i*i <= n; i++){
        if(n % i == 0){
            divs.push_back(i);
            if(i * i != n)
                divs.push_back(n / i);
        }
    }
    return divs;
}
 
int32_t main(){
    Flashyy;
    tc {
        int x, m; 
        cin >> x >> m;
        int ans = 0;
 
        vector<int> divs = divis(x);

        for(auto d : divs){
            int y = x ^ d;
            if(y != x && y >= 1 && y <= m) ans++;
        }
 
        
        int b = 64 - __builtin_clzll(x); 
        int u = (1LL << b) - 1; 

        for (int d = 1; d <= u; d++){
            int y = x ^ d;
            if(y > m) continue;
            
            if(x % d == 0) continue;
            if(y % d == 0) ans++;
        }
 
        cout << ans << endl;
    }
    return 0;
}