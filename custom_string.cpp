#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int length;

public:
    // Default constructor for uninitialized string
    String() {
        str = nullptr;
        length = 0;
    }

    // Constructor to initialize with a string constant
    String(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = s[i];
        }
        str[length] = '\0';
    }

    // Copy constructor for deep copy
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    // Destructor to clean up memory
    ~String() {
        delete[] str;
    }

    // Overload + operator to concatenate two strings
    String operator+(const String& other) const {
        String newString;
        newString.length = length + other.length;
        newString.str = new char[newString.length + 1];
        for (int i = 0; i < length; i++) {
            newString.str[i] = str[i];
        }
        for (int i = 0; i < other.length; i++) {
            newString.str[length + i] = other.str[i];
        }
        newString.str[newString.length] = '\0';
        return newString;
    }

    // Overload == operator to compare two strings
    bool operator==(const String& other) const {
        if (length != other.length) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (str[i] != other.str[i]) {
                return false;
            }
        }
        return true;
    }

    // Display the string
    void display() const {
        if (str) {
            std::cout << str;
        }
    }
};

int main() {
    // Create uninitialized string
    String S1;

    // Create initialized strings
    String S2("object oriented ");
    String S3("programming");

    // Display initial strings
    std::cout << "S2: ";
    S2.display();
    std::cout << std::endl;

    std::cout << "S3: ";
    S3.display();
    std::cout << std::endl;

    // Concatenate strings
    String S4 = S2 + S3;
    std::cout << "S4 (S2 + S3): ";
    S4.display();
    std::cout << std::endl;

    // Compare strings
    String S5("object oriented");
    std::cout << "S2 == S5: " << (S2 == S5 ? "True" : "False") << std::endl;

    return 0;
}
