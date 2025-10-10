#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
bool allSame(const vector<ll>&vec){
    if(vec.empty())return true;
    ll f=vec[0];
    for(ll i=1;i<vec.size();i++){
        if(vec[i]!=f)return false;
    }
    return true;
}
ll zeroCount(const vector<ll>&vec){
    ll c=0;
    bool fZ=false;
    bool skipZ=false;
    for(ll i=0;i<vec.size();i++){
        if(vec[i]==0){
            if(!fZ && i==0){
                while(i<vec.size()&& vec[i]==0)i++;
                skipZ=true;
            }
            if(i<vec.size()&& vec[i]==0){
                if(!fZ){
                    c++;
                    fZ=true;
                }
            }else {
                fZ=false;
            }
        }else{fZ=false;}    
    }
    return c;
}
*/
void solve(){
    ll n,ans=2;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)cin>>arr[i];
    n=unique(arr.begin(),arr.end())-arr.begin();
    ans=n;
    for(ll i=0;i+2<n;i++){
        ans-=(arr[i]>arr[i+1]&&arr[i+1]>arr[i+2]);
        ans-=(arr[i]<arr[i+1]&&arr[i+1]<arr[i+2]);
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}