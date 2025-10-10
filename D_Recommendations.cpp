#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

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
    if (x > y) return 0;
    return (x + y) * (y - x + 1) / 2;
}

#define tc int TC; cin >> TC; for (int tt = 1; tt <= TC; tt++)
int stk[1000006], top;
int n;
vector<pair<pair<int, int>, int>> arr;
vector<int> ans1, ans2;

inline bool cmp(pair<pair<int, int>, int>x, pair<pair<int, int>, int>y){
    return x.first.first == y.first.first ? x.first.second > y.first.second : x.first.first < y.first.first;
}

inline void solve(vector<int>& ans){
    sort(all(arr), cmp);
    top = 0;
    for (int i = 1; i <= n; i++) {
        while (top && arr[stk[top]].first.second < arr[i].first.second) top--;
        if (top && arr[stk[top]].first.first == arr[i].first.first && arr[stk[top]].first.second == arr[i].first.second)
            ans[arr[stk[top]].second] = 0;
        else {
            if (top) ans[arr[i].second] = arr[i].first.first - arr[stk[top]].first.first;
            stk[++top] = i;
        }
    }
}

int32_t main() {
    Flashyy
    tc {
        cin >> n;
        arr.resize(n + 1);
        ans1.resize(n + 1);
        ans2.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first.first >> arr[i].first.second;
            arr[i].second = i;
            ans1[i] = ans2[i] = 0;
        }
        solve(ans1);
        for (int i = 1; i <= n; i++) {
            int x = arr[i].first.first, y = arr[i].first.second;
            arr[i].first.first = 1000000000 - y + 1;
            arr[i].first.second = 1000000000 - x + 1;
        }
        solve(ans2);
        for (int i = 1; i <= n; i++) {
            cout << ans1[i] + ans2[i] << endl;
        }
    }
    return 0;
}
