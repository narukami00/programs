#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the + operator for complex numbers
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the << operator for easy output
    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real << "+" << c.imag << "i";
        return out;
    }
};

class Matrix {
public:
    Complex mat[2][2];

    // Overload the + operator for matrices
    Matrix operator+(const Matrix &other) const {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    // Overload the << operator for easy output
    friend ostream& operator<<(ostream &out, const Matrix &m) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                out << m.mat[i][j] << "\t";
            }
            out << endl;
        }
        return out;
    }
};

int main() {
    // Define two 2x2 matrices of complex numbers
    Matrix mat1 = {{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}}};
    Matrix mat2 = {{{{2, 3}, {4, 5}}, {{6, 7}, {8, 9}}}};

    // Add the matrices
    Matrix result = mat1 + mat2;

    // Output the result
    cout << "Matrix 1:\n" << mat1 << endl;
    cout << "Matrix 2:\n" << mat2 << endl;
    cout << "Result of addition:\n" << result << endl;

    return 0;
}
