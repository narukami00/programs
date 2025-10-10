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


unsigned int f_val(int m) {
    if(m <= 0) return 0;
    int k = 31 - __builtin_clz(m); 

    if(m == (1 << k))
        return (1u << k) - 1;
    else
        return (1u << (k+1)) - 1;
}
 
int32_t main(){
    Flashyy
    int t;
    cin >> t;
    while(t--){
        int n;
        unsigned int x;
        cin >> n >> x;

        int bestM = -1;
        for (int m = n; m >= 0; m--){
            unsigned int base = f_val(m);
            if ((base & (~x)) != 0) continue;
            unsigned int missing = x & (~base);
            if(missing != 0 && m == n) continue;
            bestM = m;
            break;
        }
 

        vector<unsigned int> ans(n, 0);
        int idx = 0;

        for (int i = 0; i < bestM; i++){
            ans[idx++] = i;
        }

        if(idx < n){
            unsigned int base = f_val(bestM);
            unsigned int missing = x & (~base);
            if(missing != 0){
                ans[idx++] = missing;
            }

            while(idx < n){
                ans[idx++] = 0;
            }
        }

        if(bestM == 0){
            ans[0] = x;
            for(int i = 1; i < n; i++){
                ans[i] = 0;
            }
        }

        for (int i = 0; i < n; i++){
            cout << ans[i] << (i + 1 == n ? "\n" : " ");
        }
    }
    return 0;
}
