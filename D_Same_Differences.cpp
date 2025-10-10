#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    long long c=0;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>x;
        x-=i;
        c+=mp[x];
        mp[x]++;
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(j-i==arr[j]-arr[i])c++;
        }
    }
   for(int i=0;i<n;i++){
    arr[i]=arr[i]-i;
   }
   sort(arr.begin(),arr.end());
   for(int i=1;i<n;i++){
    if(arr[i]==arr[i-1])c++;
   }*/
    cout<<c<<endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}