#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int m=(n*(n-1))/2;
    vector<int> arr(m);
    for(int i=0;i<m;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    for(int i=0;i<m;i+=--n)cout<<arr[i]<<' ';
    cout<<"1000000000"<<endl;

}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}