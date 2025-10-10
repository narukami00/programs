#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<m;j++)cin>>b[j];
    
    sort(b.begin(), b.end());
    
    int prev = -1e18;
    
    for (int i = 0; i < n; ++i) {
        int curr_og = a[i];
        bool og_valid = (curr_og >= prev);
        
        int need = prev + a[i];
        auto it = lower_bound(b.begin(), b.end(), need);
        int new_min = 1e18;
        if (it != b.end()) {
            new_min = *it - a[i];
        }
        
        vector<int> poss;
        if (og_valid) {
            poss.push_back(curr_og);
        }
        if (it != b.end() && new_min >= prev) {
            poss.push_back(new_min);
        }
        
        if (poss.empty()) {
            cout << "NO" << endl;
            return;
        }
        
        int chosen = *min_element(poss.begin(), poss.end());
        prev = chosen;
    }
    
    cout << "YES" << endl;
}

signed main() {
    FastIO
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}