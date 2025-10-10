#include<iostream>
using namespace std;

class A {
public:
    A(){cout << "A" << endl;}
};

class B {
public:
    B(){cout << "B" << endl;}
};

class C: virtual B {
public:
    C(){cout << "C" << endl;}
};

class D:  A, virtual B {
public:
    D(){cout << "D" << endl;}
};

class E: A {
public:
    E(){cout << "E" << endl;}
};

class F: virtual D, C {
public:
    F(){cout << "F" << endl;}
};

class G: D, virtual  E {
public:
    G(){cout << "G" << endl;}
};

class I: virtual F {
public:
    I(){cout << "I" << endl;}
};

class H: virtual G,  F {
public:
    H(){cout << "H" << endl;}
};


int main(){
    H h;
    cout << "----------------------------------------\n";
}