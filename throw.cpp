#include<iostream>
using namespace std;
//int f(int x)throw(){ //not allowed to throw exception
//int f(int x)noexcept(true){ //not allowed to throw exception (modern)
int f(int x)noexcept(false){ //allowed to throw exception(default)
    if(x==1)throw 1;
    else throw 0;
    return 0;
}
int main(){
    try{
        f(1);
    }
    catch(int){
        cout<<"Exception of type Int is detected\n";    
    }
    return 0;
}