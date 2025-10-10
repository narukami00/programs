#include <bits/stdc++.h>
using namespace std;

vector<long long> s;

void precompute() {
    s.clear();
    long long num = 0;
    for (int digits = 1; digits <= 18; digits++) {
        num = num * 10 + 9;
        s.push_back(num);
    }
}

bool has7(long long x) {
    string str = to_string(x);
    return str.find('7') != string::npos;
}

int main() {
    precompute();
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string str_n = to_string(n);
        if (str_n.find('7') != string::npos) {
            cout << 0 << endl;
            continue;
        }
        bool found = false;
        for (long long x : s) {
            long long sum = n + x;
            if (has7(sum)) {
                cout << 1 << endl;
                found = true;
                break;
            }
        }
        if (found) continue;
        for (long long x : s) {
            for (long long y : s) {
                long long sum = n + x + y;
                if (has7(sum)) {
                    cout << 2 << endl;
                    found = true;
                    goto next_case;
                }
            }
        }
        next_case:
        if (found) continue;
        cout << 3 << endl;
    }
    return 0;
}