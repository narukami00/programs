#include <iostream>
using namespace std;

class A {
public:
    int y;
    A() {
        cout << "A D" << endl;
    }
    A(int x) {
        y = x;
        cout << "A P" << endl;
    }
};

class B : virtual public A {
public:
    B() {
        cout << "B D" << endl;
    }
    B(int x) : A(x) {
        cout << "B P" << endl;
    }
};

class C : virtual public A {
public:
    int y;
    C() {
        cout << "C D" << endl;
    }
    C(int x) : A(x) {
        cout << "C P" << endl;
    }
};

class E : public B, public C {
public:
    E() {
        cout << "E D" << endl;
    }
    E(int x) : A(x) {
        cout << "E P" << endl;
    }
    E(int x, int y, int z) : A(x), B(y), C(z) {
        cout << "E P" << endl;
    }
};

int main() {
    cout << "_e1_" << endl;
    E e1;
    cout << "_e2(1)_" << endl;
    E e2(1);
    cout << "_e3(2,3,4)_" << endl;
    E e3(2,3,4);
    cout << "_b(5)_" << endl;
    B b(5);
    return 0;
}
