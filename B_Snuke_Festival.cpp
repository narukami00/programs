#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll upperBound(vector<ll> &arr,ll val){
    ll l=0,r=arr.size();
    while(l<r){
        ll mid=l+(r-l)/2;
        if(arr[mid]<=val)l=mid+1;
        else r=mid;
    }
    return l;
}

ll lowerBound(vector<ll> &arr, ll val){
    ll l=0,r=arr.size();
    while(l<r){
        ll mid=l+(r-l)/2;
        if(arr[mid]<val)l=mid+1;
        else r=mid;
    }
    return l;
}

int main(){
    ll n;
    cin>>n;
    ll cnt=0;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++)cin>>b[i];
    for(ll i=0;i<n;i++)cin>>c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    for(ll i=0;i<n;i++){
        ll low=lowerBound(a,b[i]);
        ll high=c.size()-upperBound(c,b[i]);
        cnt+=low*high;
    }
    cout<<cnt<<endl;
}