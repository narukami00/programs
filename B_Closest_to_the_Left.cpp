#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int binarySearch(int arr[],int n,int value){
    int left=0,right=n-1,ans=0;
    while(left<=right){
            int mid=(left+right)/2;
            if(arr[mid]<=value){
                ans=mid+1;
                left=mid+1;
            }
            else right=mid-1;
        }
    return ans;    
}

int32_t main(){
    Flashyy
    int n,k;
    cin>>n>>k;
    int arr[n],que[k];

    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<k;i++)cin>>que[i];

    int left=0,right=n-1;

    for(int i=0;i<k;i++){
        cout<<binarySearch(arr,n,que[i])<<endl;
    }
    

}
