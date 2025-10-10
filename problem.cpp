#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A constructor\n"; }
    virtual ~A() { cout << "A destructor\n"; }
};

class B : public A {
public:
    B() { cout << "B constructor\n"; }
    ~B() { cout << "B destructor\n"; }
};

class C : public B {
public:
    C() { cout << "C constructor\n"; }
    ~C() { cout << "C destructor\n"; }
};

int main() {
    A *a;
    a = new C;
    delete a;
    return 0;
}
