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

int gcd(int a, int b)
{
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int rsum(int x, int y)
{
    if (x > y)
        return 0;
    return (x + y) * (y - x + 1) / 2;
}

#define tc     \
    int TC;    \
    cin >> TC; \
    for (int tt = 1; tt <= TC; tt++)

int32_t main()
{
    Flashyy
    // tc
    {
        int n, r, b;
        cin >> n >> r >> b;
        string s;
        cin >> s;
        if (n % (r + b) != 0)
        {

            cout << "NO" << endl;
            return 0;
        }

        int it1 = 0;
        int it2 = n - 1;
        bool flag = true;
        vector<vector<int>> v;
        for (int i = 0; i < n / (r + b); i++)
        {

            if (!flag)
                break;
            // cout<<i<<endl;
            int tempr = r, tempb = b;
            vector<int> temp;
            for (int j = 0; j < r + b;)
            {
                bool entered = false;
                if (it1 <= it2)
                {
                    if (s[it1] == 'R' && tempr > 0)
                    {
                        tempr--;
                        temp.push_back(it1);
                        it1++;
                        j++;
                        entered = true;
                    }
                    else if (tempb > 0)
                    {
                        tempb--;
                        temp.push_back(it1);
                        it1++;
                        j++;
                        entered = true;
                    }
                    if (s[it2] == 'R' && tempr > 0)
                    {
                        tempr--;
                        temp.push_back(it2);
                        it2--;
                        j++;
                        entered = true;
                    }
                    else if (tempb > 0)
                    {
                        tempb--;
                        temp.push_back(it2);
                        it2--;
                        j++;
                        entered = true;
                    }
                    if (!entered)
                    {
                        cout << "NO" << endl;
                        // cout << "2NO" <<" b "<<tempb<<" r "<< tempr<<" t "<<it1<<"  i "<<it2<<" j "<<j<< endl;
                        return 0;
                    }
                }
                else
                {
                    cout << "NO" << endl;
                    // cout << "3NO" <<" b "<<tempb<<" r "<< tempr<<" t "<<it1<<"  i "<<it2<<" j "<<j<< endl;
                    return 0;
                    // flag= false;
                    // break;
                }
            }
            v.push_back(temp);
        }
        cout << "YES" << endl;
        cout << v.size() << endl;
        for (auto &i : v)
        {
            sort(i.begin(), i.end());
            for (auto &j : i)
            {
                cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}