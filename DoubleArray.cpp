#include <iostream>
#include <algorithm>

class DoubleArray {
private:
    double* data;
    int size;
    double average;

public:
    // Constructor to initialize the array and size
    DoubleArray(int n) : size(n), average(0.0) {
        data = new double[n];
    }

    // Destructor to free the allocated memory
    ~DoubleArray() {
        delete[] data;
    }

    // Deep copy constructor
    DoubleArray(const DoubleArray& other) : size(other.size), average(other.average) {
        data = new double[size];
        std::copy(other.data, other.data + size, data);
    }

    // Method to set data at a specific index
    void setData(int index, double value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    // Method to get data at a specific index
    double getData(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return 0.0; // Return 0 if index is out of bounds
    }

    // Method to calculate the average of the data
    void calculateAverage() {
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        average = (size > 0) ? sum / size : 0.0;
    }

    // Method to display the array and average
    void display() const {
        std::cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\nAverage: " << average << std::endl;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // Create the first object and store N double data
    DoubleArray array1(n);
    std::cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        double value;
        std::cin >> value;
        array1.setData(i, value);
    }

    // Calculate the average for array1
    array1.calculateAverage();

    // Display array1
    array1.display();

    // Create another object using the deep copy constructor, copying data and average
    DoubleArray array2(array1);

    // Display array2 to verify the deep copy
    array2.display();

    return 0;
}
