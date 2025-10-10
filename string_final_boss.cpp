#include <iostream>
#include <cstring>
#include <stdexcept>

class MyString {
private:
    char* data;
    size_t length;

public:
    // Constructor
    MyString(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Overload [] operator for index access with wrapping
    char& operator[](int index) {
        if (index < 0) {
            index = (length + (index % static_cast<int>(length))) % static_cast<int>(length);
        } else {
            index %= static_cast<int>(length);
        }
        return data[index];
    }

    // Overload + operator for concatenation
    MyString operator+(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        std::strcpy(result.data, data);
        std::strcat(result.data, other.data);
        return result;
    }

    // Overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.data;
        return os;
    }

    // Length of the string
    size_t size() const {
        return length;
    }
};

int main() {
    MyString str1("Hello, ");
    MyString str2("World!");

    // Concatenate strings
    MyString str3 = str1 + str2;
    std::cout << "Concatenated: " << str3 << std::endl;

    // Access elements with positive and negative indices
    std::cout << "Element at index 1: " << str3[1] << std::endl;
    std::cout << "Element at index -1 (last): " << str3[-1] << std::endl;

    // Access elements with indices exceeding the length
    std::cout << "Element at index 100: " << str3[100] << std::endl;
    std::cout << "Element at index -100: " << str3[-100] << std::endl;

    return 0;
}
