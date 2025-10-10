#include <iostream>

// Base class
class A {
public:
    int a;
    A(int val = 0) : a(val) {
        std::cout << "A's constructor called with value " << a << std::endl;
    }
};

// Classes inheriting from A
class B : virtual public A {
public:
    B(int val = 0) : A(val) {
        std::cout << "B's constructor called with value " << a << std::endl;
    }
};

class C : virtual public A {
public:
    int c;
    C(int val = 0) : A(val), c(val) {
        std::cout << "C's constructor called with value " << c << std::endl;
    }
};

class D : public A {
public:
    D(int val = 0) : A(val) {
        std::cout << "D's constructor called with value " << a << std::endl;
    }
};

// Derived classes inheriting from B, C, D
class E : public B {
public:
    E(int val = 0) : B(val) {
        std::cout << "E's constructor called with value " << a << std::endl;
    }
};

class F : virtual public B, virtual public C {
public:
    F(int val = 0) : B(val), C(val) {
        std::cout << "F's constructor called with value " << a << std::endl;
    }
};

class G : public C, public D {
public:
    int g;
    G(int val = 0) : C(val), D(val), g(val) {
        std::cout << "G's constructor called with value " << g << std::endl;
    }
};

// Higher-level derived classes
class H : public E, public F {
public:
    H(int val = 0) : E(val), F(val) {
        std::cout << "H's constructor called with value " << a << std::endl;
    }
};

class I : public F, public G {
public:
    int i;
    I(int val = 0) : F(val), G(val), i(val) {
        std::cout << "I's constructor called with value " << i << std::endl;
    }
};

// Most derived class J
class J : public H, public I {
public:
    int j;
    J(int val = 0) : H(val), I(val), j(val) {
        std::cout << "J's constructor called with value " << j << std::endl;
    }
};

int main() {
    // Creating objects of derived classes
    J obj1;
    J obj2(10);

    return 0;
}
