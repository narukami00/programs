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
#define rall(x) x.rbegin(), x.rend()
#define sz(x) x.size()
#define f first
#define s second
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<int>pos;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                pos.pb(i);
            }
        }

        int m=sz(pos);
        if(m<=k){
            cout<<"Alice"<<endl;
            continue;
        }

       bool f = false;
        for (int i = 0; i + k - 1 < m; i++) {
            int span = pos[i + k - 1] - pos[i] + 1;
            if (span <= k) {
                f = true;
                break;
            }
        }

        if (f)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
return 0;
}