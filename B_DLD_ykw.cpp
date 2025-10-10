#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,k,val,c=0;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    /*
    for(ll i=0;i<n;i++){
        if(i+1==k && arr[i]==arr[i+1]){
            cout<<"-1"<<endl;
            return 0;
        }
        else if(i+1==k){
            cout<<arr[i]<<endl;
            return 0;
        }
    }
    */
   if(k==0)val=arr[0]-1;
   else val=arr[k-1];
   for(ll i=0;i<n;i++)if(arr[i]<=val)c++;
   if(c!=k || !(1<= val && val<=1000000000)){cout<<"-1"<<endl;return 0;}
    cout<<val<<endl;
   return 0;
}