#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[1000],n;
    while(cin>>n && n!=0){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int pos=0,i=0;
        stack<int> p;
        while(n>i){
            while(p.size() && p.top()==pos+1)pos++,p.pop();
            if(arr[i]!=pos+1) p.push(arr[i]);
            else pos++;
            i++;
        }
        while(p.size() && p.top()==pos+1)pos++,p.pop();
        if(pos==n)cout<<"yes\n";
        else cout<<"no\n";
    }
}