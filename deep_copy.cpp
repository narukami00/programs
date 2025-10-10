#include <iostream>
#include <cstring>

class DeepCopy {
public:
    char* data;

    DeepCopy(const char* value) {
        data = new char[strlen(value) + 1];
        strcpy(data, value);
    }

    // Deep Copy Constructor
    DeepCopy(const DeepCopy& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Deep Copy Assignment Operator
    DeepCopy& operator=(const DeepCopy& other) {
        if (this == &other) return *this;

        delete[] data;  // Free existing resource

        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);

        return *this;
    }

    ~DeepCopy() {
        delete[] data;
    }
};

int main() {
    DeepCopy obj1("Hello");
    DeepCopy obj2 = obj1;  // Deep copy using copy constructor

    DeepCopy obj3("World");
    obj3 = obj1;  // Deep copy using assignment operator

    // No issues when objects go out of scope
}
