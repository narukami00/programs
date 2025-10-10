#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int lowerBound(vector<int> &arr, int val){
    int l=0,r=arr.size();
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]<val)l=mid+1;
        else r=mid;
    }
    return l;
}
int32_t main(){
    Flashyy
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    //sort(arr.begin(),arr.end());
    while(q--){
        int s;
        cin>>s;
        int ans=lowerBound(arr,s);
        if(arr[ans]==s){
            cout<<ans<<endl;
        }else cout<<-1<<endl;
    }
    return 0;
}