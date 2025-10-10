#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define Flashyy                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

int32_t main()
{
    Flashyy
    // tc
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> s(n, vector<char>(n));
        vector<vector<char>> t(m, vector<char>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> s[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> t[i][j];
            }
        }

        bool f = false;
        for (int i = 0; i <= n - m; i++)
        {
            for (int j = 0; j <= n - m; j++)
            {
                bool found = true;
                for (int x = 0; x < m; x++)
                {
                    for (int y = 0; y < m; y++)
                    {
                        if (s[i + x][j + y] != t[x][y])
                        {
                            found = false;
                            break;
                        }
                    }
                    if (!found)
                        break;
                }
                if (found)
                {
                    cout << i + 1 << " " << j + 1 << endl;
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
    }
    return 0;
}
