// #include<iostream>
// using namespace std;

// class A{
//     public:
//     A(int a){
//         cout<<"Base A\n";
//     }
// };
// class B{
//     public:
//     B(int a){
//     cout<<"Base B\n";
//     }
// };
// class C: protected A, private B{
//     public:
//     C(int a):B(a),A(a){
//         cout<<"Derived C\n";
//     }
// };

// int main(){
//     C c(10);
//     B a(5);
// }

#include<iostream>
using namespace std;

class A{
    public:
    A(){cout<<"1\n";}
    A(A&obj){cout<<"2\n";}
};

class B:virtual A{
    public:
    B(){cout<<"3\n";}
    B(B&obj):A(obj){cout<<"4\n";}
};


class C:virtual A{
    public:
    C(){cout<<"5\n";}
    C(C&obj):A(obj){cout<<"6\n";}
};


class D:B,C{
    public:
    D(){cout<<"7\n";}
    D(D&obj):C(obj),B(obj){cout<<"8\n";}
};

int main(){
    D d1;
    cout<<"\n\n\n";
    D d(d1);
    cout<<"\n\n\n";
    B b1;
    cout<<"\n\n\n";
    B b(b1);
}