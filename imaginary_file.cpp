#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class ComplexNumber {
public:
    int real;
    int imaginary;

    ComplexNumber(int r = 0, int i = 0) : real(r), imaginary(i) {}

    // Overload + operator
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // Overload - operator
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& os, const ComplexNumber& cn) {
        os << cn.real << (cn.imaginary >= 0 ? "+" : "") << cn.imaginary << "i";
        return os;
    }

    // Parse complex number from string
    static ComplexNumber parse(const string& str) {
        stringstream ss(str);
        int real = 0, imaginary = 0;
        char sign = '+', i;
        ss >> real >> sign >> imaginary >> i;
        if (sign == '-') {
            imaginary = -imaginary;
        }
        return ComplexNumber(real, imaginary);
    }
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile) {
        cerr << "Unable to open input file" << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Unable to open output file" << endl;
        return 1;
    }

    string line;
    getline(inputFile, line);  // Skip the first line

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string num1, op, num2;
        iss >> num1 >> op >> num2;

        ComplexNumber c1 = ComplexNumber::parse(num1);
        ComplexNumber c2 = ComplexNumber::parse(num2);

        ComplexNumber result;
        if (op == "+") {
            result = c1 +
             c2;
        } else if (op == "-") {
            result = c1 - c2;
        }

        outputFile << line << " = " << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
