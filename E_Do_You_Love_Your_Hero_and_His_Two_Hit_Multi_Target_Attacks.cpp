#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
    if(x>y)return 0;
    return (x+y)*(y-x+1)/2;
}

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    Flashyy
    tc
    {
        int k;
        cin >> k;

        if(k == 0){
            cout << 0 << "\n";
            continue;
        }
        
        vector<int> grp;
        while(k > 0){
            int s = 2;
            while ( (int)s * (s - 1) / 2 <= k )s++;
            s--;  
            grp.push_back(s);
            k -= (int)s * (s - 1) / 2;
        }
        
        int total = 0;
        for (auto s : grp) total += s;
        
        cout << total << "\n";
        
        int curX = 0;
        int id = 0;
        for(auto s : grp){
            int y = id; 
            for(int j = 0; j < s; j++){
                cout << curX << " " << y << "\n";
                curX++; 
            }
            id++;
        }
    }
return 0;
}

