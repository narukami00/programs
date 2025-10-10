#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<float> elements;

public:
    // 1. Create vector
    Vector(const std::vector<float>& elems) : elements(elems) {}

    // 2. Modify value of given element
    void modifyValue(int index, float value) {
        if (index >= 0 && index < elements.size()) {
            elements[index] = value;
        } else {
            std::cerr << "Index out of bounds" << std::endl;
        }
    }

    // 3. Multiply by a scalar value
    void multiplyByScalar(float scalar) {
        for (auto& element : elements) {
            element *= scalar;
        }
    }

    // 4. Display in the form 1, 2, 3, ...
    void display() const {
        for (size_t i = 0; i < elements.size(); ++i) {
            std::cout << elements[i];
            if (i != elements.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example usage
    std::vector<float> initialElements = {1.0, 2.0, 3.0, 4.0, 5.0};
    Vector vec(initialElements);

    std::cout << "Original vector: ";
    vec.display();

    vec.modifyValue(2, 10.0);
    std::cout << "After modification: ";
    vec.display();

    vec.multiplyByScalar(2.0);
    std::cout << "After multiplication: ";
    vec.display();

    return 0;
}
