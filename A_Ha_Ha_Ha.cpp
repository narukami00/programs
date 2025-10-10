#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int m=100000;
    vector<ll> f(m+1,0);
    for(int i=0;i<n;i++){
        f[arr[i]]+=arr[i];
    }
    vector<ll> d(m+1,0);
    d[1]=f[1];
    for(int i=2;i<=m;i++){
        d[i]=max(d[i-1],d[i-2]+f[i]);
    }
    cout<<d[m]<<endl;
}