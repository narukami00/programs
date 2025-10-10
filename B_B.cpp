#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,c=0;
    cin>>x;
    int arr[x];
    for(int i=0;i<x;i++)cin>>arr[i];

    unordered_map<int,int> f;
    for(int i=0;i<x;i++)f[arr[i]]++;
    
    int max_f = 0;
    for (auto it:f) {
        if (it.second>max_f)max_f=it.second;    
    }
     cout<<x-max_f<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();    
    }
}