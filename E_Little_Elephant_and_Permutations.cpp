#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,inv=0,loc_inv=0;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)cin>>arr[i];

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]) inv++;
            }
        }

        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) loc_inv++;
        }

        if(loc_inv==inv)cout<<"YES\n";
        else cout<<"NO\n";

    }
}