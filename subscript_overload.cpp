#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, std::vector<int>(c)) {}

    // Overload the subscript operator to return a reference to an element
    int& operator()(size_t row, size_t col) {
        return data[row][col];
    }

    // Overload the subscript operator to return a const reference to an element (for const objects)
    const int& operator()(size_t row, size_t col) const {
        return data[row][col];
    }

    void display() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix mat(3, 3);

    // Assign values using the overloaded subscript operator
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(0, 2) = 3;
    mat(1, 0) = 4;
    mat(1, 1) = 5;
    mat(1, 2) = 6;
    mat(2, 0) = 7;
    mat(2, 1) = 8;
    mat(2, 2) = 9;

    // Display the matrix
    mat.display();

    return 0;
}
