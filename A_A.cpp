#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;
    if(y*30<=x) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}