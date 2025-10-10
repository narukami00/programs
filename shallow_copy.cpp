#include <iostream>
#include <cstring>

class ShallowCopy {
public:
    char* data;
    
    ShallowCopy(const char* value) {
        data = new char[strlen(value) + 1];
        strcpy(data, value);
    }

    // Shallow Copy Constructor
    ShallowCopy(const ShallowCopy& other) : data(other.data) {}

    ~ShallowCopy() {
        delete[] data;
    }
};

int main() {
    ShallowCopy obj1("Hello");
    ShallowCopy obj2 = obj1;  // Shallow copy

    // This will cause double deletion when obj1 and obj2 go out of scope
}
