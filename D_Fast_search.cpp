#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define Flashyy ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int lowerBound(int arr[],int n,int left_value){
    int left=0,right=n;
    while(left<right){
            int mid=left+(right-left)/2;
            if(arr[mid]<left_value){
                left=mid+1;
            }
            else right=mid;
        }
    return left;    
}

int upperBound(int arr[],int n,int right_value){
    int left=0,right=n;
    while(left<right){
            int mid=left+(right-left)/2;
            if(arr[mid]<=right_value){
                left=mid+1;
            }
            else right=mid;
        }
        
    return left;    
}

int32_t main(){
    Flashyy
    int n,k;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    
    cin>>k;
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        int left=lowerBound(arr,n,l);
        int right=upperBound(arr,n,r);
        cout<<right-left<<" ";
    }
    

}
