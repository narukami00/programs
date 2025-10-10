#include <bits/stdc++.h>
using namespace std;

bool isSynonymous(const string &s1, const string &s2)
{
    return count(s1.begin(), s1.end(), '1') == count(s2.begin(), s2.end(), '1');
}

void synonymize(string s1, const string &s2)
{
    vector<pair<int, int>> operations;
    int n = s1.size();

    for (int i = 0; i < n; ++i)
    {
        if (s1[i] != s2[i])
        {
            int j = i;
            int count1 = 0;

            while (j < n)
            {
                if (s1[j] != s2[j])
                {
                    if (s1[j] == '1')
                        count1++;
                    j++;
                }
                else if (count1 == 0)
                {
                    if (s1[j] == '1')
                        count1++;
                    j++;
                }
                else if (count1 % 2 != 0)
                {
                    if (s1[j] == '1')
                        count1++;
                    j++;
                }
                else
                    break;
            }
            if (count1 != 0 && count1 % 2 == 0)
            {
                reverse(s1.begin() + i, s1.begin() + j);
                // cout<<s1<<endl;
                operations.emplace_back(i + 1, j);
            }
        }
    }
    if (s1 != s2)
    {
        cout << "NO" << endl;
        return;
    }

    if (operations.size() > 16 * s1.size())
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << operations.size() << endl;
        for (const auto &op : operations)
        {
            cout << op.first << " " << op.second << endl;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    if (!isSynonymous(s1, s2))
    {
        cout << "NO\n";
        return 0;
    }

    synonymize(s1, s2);

    return 0;
}
