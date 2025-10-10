#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define FastAF ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

#define tc int TC;cin>>TC;for(int tt=1;tt<=TC;tt++)

int32_t main(){
    FastAF
    tc
    {
        int n, x; cin >> n;
        map<int, int> mp;

        for (int i = 0; i < n; i++){
            cin >> x;
            mp[x]++;
        }

        int singleMe = 0;
        for (auto i: mp){
            if (i.second==1) singleMe++;
        }

        int ans = 2*((singleMe+1)/2);
        ans += mp.size()-singleMe;

        cout << ans << endl;
    }
return 0;
}