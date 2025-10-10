#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int tc){
    ll n,p;//1 odd, 2 even
    cin>>n>>p;
    ll rem=0;
    cout<<"Case "<<tc<<": ";
    if(n==1 && p ==1)cout<<"Evenius"<<endl;
    else if(n!=1 && p==2 && (n-1)%4==0)cout<<"Evenius"<<endl;
    else cout<<"Oddius"<<endl;
    //else if(n%2==0 && p=2)
    //else if()
    //else if(n%2==0 && p==1) cout<<"Oddius"<<endl;
    //else if(n%2!=0 && p=2) cout<<"Oddius"<<endl;
    
}
int main(){
    int t; cin >> t;
    // while(t--) solve();
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}