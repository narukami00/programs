#include <iostream>
using namespace std;

class Base {
public:
    virtual const char* GetClassType() const { return "Base"; } // Identify class type
};

class Derived1 : public Base {
public:
    const char* GetClassType() const override { return "Derived1"; }
};

class Derived2 : public Base {
public:
    const char* GetClassType() const override { return "Derived2"; }
};

void IdentifyClassType(const Base* obj) {
    cout << "Object is of type: " << obj->GetClassType() << endl;
}

int main() {
    Base base;
    Derived1 derived1;
    Derived2 derived2;

    IdentifyClassType(&base);      // Output: Object is of type: Base
    IdentifyClassType(&derived1);  // Output: Object is of type: Derived1
    IdentifyClassType(&derived2);  // Output: Object is of type: Derived2

    return 0;
}
