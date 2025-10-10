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

template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

bool check(const vector<int>& a, int b, int start_val) {
    int prev = start_val;
    for (size_t i = 1; i < a.size(); ++i) {
        int op1 = a[i];
        int op2 = b - a[i];
        int chs = -1;
        if (op1 >= prev && op2 >= prev) {
            chs = min(op1, op2);
        } else if (op1 >= prev) {
            chs = op1;
        } else if (op2 >= prev) {
            chs = op2;
        } else {
            return false;
        }
        prev = chs;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    cin >> a >> b;
    
    if (n == 1) {
        yes;
        return;
    }
    
    int str1 = a[0];
    int str2 = b[0] - a[0];
    
    if (check(a, b[0], str1) || check(a, b[0], str2)) {
        yes;
    } else {
        no;
    }
}

int32_t main() {
    Flashyy
    int TC; cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}