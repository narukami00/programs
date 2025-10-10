#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    
public:
    Matrix(int rows, int cols) : data(rows, vector<int>(cols)) {}

    // Nested class to handle the second subscript
    class Proxy {
    private:
        vector<int>& row;
    public:
        Proxy(vector<int>& rowRef) : row(rowRef) {}

        int& operator[](int col) {
            return row[col];
        }
    };

    // Overload the first subscript operator
    Proxy operator[](int row) {
        return Proxy(data[row]);
    }

    // For const correctness
    class ConstProxy {
    private:
        const vector<int>& row;
    public:
        ConstProxy(const vector<int>& rowRef) : row(rowRef) {}

        const int& operator[](int col) const {
            return row[col];
        }
    };

    ConstProxy operator[](int row) const {
        return ConstProxy(data[row]);
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
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
