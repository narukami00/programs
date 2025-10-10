#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,x,tmp,c=0;
    cin>>n>>x;
    for(ll i=2;i<n;i++){
        ll r=2*i-2;
        ll pos=(n-1)%r +1;
        if(pos<=i){
            tmp=pos;
        }
        else tmp=2*i-pos;
        if(tmp==x)c++;
    }
    cout<<c<<endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}