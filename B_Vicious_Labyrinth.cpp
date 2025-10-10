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
        int k;
        cin >> n >> k;
        
        if(n == 2) {
            cout << "2 1\n";
            continue;
        }
        
        if(k % 2 == 1) {
            for (int i = 1; i < n; i++) {
                cout << n << " ";
            }
            cout << n - 1 << "\n";
        } else {
            for (int i = 1; i <= n - 2; i++) {
                cout << n - 1 << " ";
            }
            cout << n << " " << n - 1 << "\n";
        }
    }
return 0;
}


