#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n,c=0;
    string s;
    cin>>n>>s;
    for(int i=1;i<=n-2;i++){
        if(s[i-1]==s[i+1])c++;
    }
    ll sol=n-c-1;
    cout<<sol<<endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}