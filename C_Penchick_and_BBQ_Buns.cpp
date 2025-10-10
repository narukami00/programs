#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define sp " "
#define Flashyy                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define tc     \
    int TC;    \
    cin >> TC; \
    for (int tt = 1; tt <= TC; tt++)
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
bool isSquare(int x)
{
    if (x < 0)
        return false;

    int l = 0, r = 5000000001;

    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (mid * mid <= x)
            l = mid;
        else
            r = mid;
    }

    if (l * l == x)
    {
        return true;
    }
    return false;
}
int32_t main()
{
    Flashyy tc
    {
        int n;
        cin >> n;
        if (n % 2 != 0)
        {
            if (n >= 27)
            {
                int m = n - 27;
                for (int i = 1; i <= m / 2; i++)
                {
                    cout << i << sp << i << sp;
                }
                int b = m / 2 + 1;
                cout << b + 12 << sp;
                vector<int> arr = {b, b + 1, b + 1, b + 2, b + 2, b + 3, b + 3, b + 4, b + 4, b, b + 5, b + 5, b + 6, b + 6, b + 7, b + 7, b + 8, b + 8, b + 9, b + 9, b + 10, b + 10, b + 11, b + 11, b + 12, b};
                cout << arr << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            for (int i = 1; i <= n / 2; i++)
            {
                cout << i << sp << i << sp;
            }
            cout << endl;
        }
    }
    return 0;
}