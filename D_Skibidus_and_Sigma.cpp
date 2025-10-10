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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> presums(n);
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += a[i][j];
        }
        presums[i] = sum;
    }

    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    sort(all(order), [&](int i, int j) {
        return presums[i] > presums[j];
    });

    vector<int> conc;
    for (int i : order) {
        conc.insert(conc.end(), all(a[i]));
    }

    int score = 0;
    int curr_sum = 0;
    for (int num : conc) {
        curr_sum += num;
        score += curr_sum;
    }

    cout << score << endl;
}

int32_t main() {
    Flashyy
    int TC; cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}