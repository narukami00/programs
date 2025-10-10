#include<bits/stdc++.h>
using namespace std;

void solve(int tc){
    long long n,k;
    cin>>n>>k;
    long long ans=0;
    vector <pair<long long,long long>> arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        ans+=(k/arr[i].first);
    }
    
    cout<<"Case "<<tc<<": "<<ans<<endl;


}
int main(){
    int t; cin >> t;
    // while(t--) solve();
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}