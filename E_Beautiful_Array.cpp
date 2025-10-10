#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,n=3;
    cin>>x>>y;

    if(x==y){
        cout<<"1\n";
        cout<<x<<endl;
        return 0;
    }

    int sum=n*x-2*y;
    //int m1=sum-1;
    int zero=0;
    cout<<n<<endl;

    cout<<y<<" "<<y<<" "<<sum<<endl;

    return 0;
}