#include<iostream>
using namespace std;

class savings{
    float cash;
    public:
    savings(){
        cash=0;
    }
    void deposit(float m){
        cash+=m;
    }
    void withdraw(float m){
        cash-=m;
    }
    void show(){
        cout<<"Cash: "<<cash<<endl;
    }

};

class Account:public savings{
    string name;
    public:
    int id;
    Account(string s):name(s){
        id++;
    }
    string getName(){return name;}
};




Account::id=0;
int main(int argc, char const *argv[])
{
    Account a1("Tahmid");
    a1.deposit(20.0);
    a1.show();
    

    return 0;
}
