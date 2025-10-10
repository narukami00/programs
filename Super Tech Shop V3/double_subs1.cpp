#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols) : data(rows, std::vector<int>(cols)) {}

    // Helper function to access elements
    int& at(int row, int col) {
        return data[row][col];
    }

    const int& at(int row, int col) const {
        return data[row][col];
    }

    // Overload the first subscript operator to return a helper function
    auto operator[](int row) {
        return [this, row](int col) -> int& {
            return at(row, col);
        };
    }

    // For const correctness
    auto operator[](int row) const {
        return [this, row](int col) -> const int& {
            return at(row, col);
        };
    }
};

int main() {
    Matrix mat(3, 3);

    // Using double subscript operator
    mat[0][0] = 1;
    mat[1][1] = 2;
    mat[2][2] = 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
