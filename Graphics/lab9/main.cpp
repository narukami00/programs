#include <bits/stdc++.h>
using namespace std;

template <class myType>
myType GetMax(myType a, myType b){
    myType result;
    result = (a>b)?a:b;
    return result;
}

template <class myType1,class myType2>
myType2 GetMax2(myType1 a, myType2 b){
    myType2 result;
    result = (a>b)?a:b;
    return result;
}

int main()
{
    //int x,y;
    int x;
    long y;
    cin>>x>>y;
    //cout<<GetMax(x,y)<<endl;
    cout<<GetMax2(x,y)<<endl;
    return 0;
}
