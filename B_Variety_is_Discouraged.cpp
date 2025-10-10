#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sp " "
#define all(x) x.begin(), x.end()

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        istream >> it;
    return istream;
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        ostream << it << " ";
    return ostream;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long rsum(long long x, long long y){
    if(x > y) return 0;
    return (x + y) * (y - x + 1) / 2;
}

#define tc int TC; cin >> TC; for(int tt = 1; tt <= TC; tt++)

int main(){
    Flashyy
    tc 
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> mp;
        map<int, int> demo;

        vector<pair<int, pair<int, int>>> loo;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            demo[arr[i]]++;
        }

        int start = 0;
        int end = 0;
        int longest = 0;
        mp.clear();

        for(int i = 0; i < n; i++){
            if(mp[arr[i]] == 0 && demo[arr[i]] == 1){
                mp[arr[i]]++;
                if(longest == 0) start = i + 1;
                longest++;
                end = i + 1;
            } else {
                if(longest > 0){
                    loo.push_back({longest, {start, end}});
                }
                mp.clear();
                longest = 0;
                start = 0;
                end = 0;
            }
        }

        if(longest > 0){
            loo.push_back({longest, {start, end}});
        }

        if(loo.empty()){
            cout << "0" << endl;
        } else {
            sort(all(loo));
            cout << loo.back().second.first << " " << loo.back().second.second << endl;
        }
    }
    return 0;
}
