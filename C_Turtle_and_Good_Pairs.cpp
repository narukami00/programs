#include<bits/stdc++.h>
#define ll long long
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second
using namespace std;

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<char,ll> freq;
    for(const auto &x:s){
        freq[x]++;
    }
    vector<pair<ll,char>> chars;
    for(const auto &x:freq){
        chars.push_back({x.second,x.first});
    }
    sort(all(chars));
    reverse(all(chars));

    ll indx=0;
    string t(n,'$');
    for(const auto &x:chars){
        ll f=x.first;
        const char c=x.second;
        while(f--){
            if(indx>=n)indx=1;
            t[indx]=c;
            indx+=2;
        }
    }
    cout<<t<<endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}