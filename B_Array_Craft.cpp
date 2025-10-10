#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    x--;y--;
    int a=-1;
    vector<int>arr(n,1);
    for(int i=y-1;i>=0;i--){arr[i]=a;a*=-1;}
    a=-1;
    for(int i=x+1;i<n;i++){arr[i]=a;a*=-1;}
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<arr[i];
    }
    cout<<endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}