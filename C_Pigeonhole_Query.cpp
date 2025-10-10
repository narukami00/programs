#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> pcurr(N + 1);
    vector<int> pcnt(N + 1, 1);
    int nest = 0;

    for (int i = 1; i <= N; i++)
    {
        pcurr[i] = i;
    }

    while (Q--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int P, H;
            cin >> P >> H;

            int old = pcurr[P];

            pcnt[old]--;
            if (pcnt[old] == 1)
            {
                nest--;
            }

            if (pcnt[H] == 1)
            {
                nest++;
            }
            pcnt[H]++;

            pcurr[P] = H;
        }
        else if (q == 2)
        {
            cout << nest << '\n';
        }
    }

    return 0;
}
