#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    string s, st;
    cin >> s;

    ll a = 0, b = 0;
    for (ll i = 0;s.size()>2 && i <= s.size() - 3; i++)
    {
        st = "";
        st += s[i];
        st += s[i + 1];
        st += s[i + 2];
        if (st == "LSC")
            a++;
    }
    for (ll i = 0;s.size()>3 && i <= s.size() - 4; i++)
    {
        st = "";
        st += s[i];
        st += s[i + 1];
        st += s[i + 2];
        st += s[i + 3];

        if (st == "PCMS")
            b++;
          
    }

    //cout << a << " " << b << endl;
    if (a > b)
        cout << "LSC" << endl;
    else if (a < b)
        cout << "PCMS" << endl;
    else
        cout << "Tie" << endl;
}