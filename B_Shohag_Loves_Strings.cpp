#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define sp " "
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)
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

int32_t main(){
    Flashyy
    tc
    {
        string s;
        cin >> s;
        int n = s.size();
        bool found = false;
        string ans;

        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                ans = s.substr(i, 2);
                found = true;
                break;
            }
        }

        if(!found){
            for(int i = 0; i < n - 2; i++){
                if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2]){
                    ans = s.substr(i, 3);
                    found = true;
                    break;
                }
            }
        }
        
        if(found)
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    
    }
return 0;
}
