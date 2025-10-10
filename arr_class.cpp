#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayContainer {
private:
    T* data;
    int size;

    void resize(int newSize) {
        T* newData = new T[newSize];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    ArrayContainer() : data(nullptr), size(0) {}

    ~ArrayContainer() {
        delete[] data;
    }

    void add(const T& element) {
        resize(size + 1);
        data[size++] = element;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        resize(size - 1);
        size--;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void set(int index, const T& element) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = element;
    }

    int getSize() const {
        return size;
    }

    T operator[](int index) const {
        return get(index);
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
};

int main() {
    ArrayContainer<int> arr;

    // Adding elements to the array
    arr.add(1);
    arr.add(2);
    arr.add(3);

    // Displaying the elements
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Removing an element
    arr.remove(1);

    // Displaying the elements after removal
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Checking size after removals
    std::cout << "Current size: " << arr.getSize() << std::endl;

    return 0;
}
