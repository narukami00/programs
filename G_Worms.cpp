#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int brr[n];
    brr[0]=arr[0];
    for(int i=1;i<n;i++)brr[i]=arr[i]+brr[i-1];
    int m;
    cin>>m;

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        int l=-1,r=n,mid;
        while(l+1<r){
            mid=(r+l)/2;
            if(brr[mid]>=x)r=mid;
            else l=mid;
        }
        cout<<r+1<<endl;
    }
}