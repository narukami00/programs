#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,ans=(1<<32)-1;
    cin>>n;
    //vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x!=i)ans&=x;
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}