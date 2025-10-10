#include <iostream>
#include <vector>
using namespace std;

class CustomVector {
private:
    vector<int> data;

public:
    CustomVector(const vector<int>& vec) : data(vec) {}

    // Overload the operator[] to access elements in reverse using negative indices
    int& operator [](int index){
        if (index < 0) {
            index = data.size() + index;
        }
        return data[index];
    }

    // For const objects
    const int& operator [](int index)const{
        if (index < 0) {
            index = data.size() + index;
        }
        return data[index];
    }
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    CustomVector customVec(vec);

    cout << "Element at -1: " << customVec[-1] << endl; // Output: 5
    cout << "Element at -2: " << customVec[-2] << endl; // Output: 4
    cout << "Element at 0: " << customVec[0] << endl;   // Output: 1

    return 0;
}
