#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <chrono>

// Helper function to measure execution time
template<typename Func>
void measureTime(Func func, const std::string& label) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << label << ": " << duration.count() << " ms" << std::endl;
}

int main() {
    const int N = 100000;

    // Vector operations
    std::vector<int> vec;
    measureTime([&] {
        for (int i = 0; i < N; ++i) {
            vec.push_back(i);
        }
    }, "Vector push_back");

    // List operations
    std::list<int> lst;
    measureTime([&] {
        for (int i = 0; i < N; ++i) {
            lst.push_back(i);
        }
    }, "List push_back");

    // Map operations
    std::map<int, int> mp;
    measureTime([&] {
        for (int i = 0; i < N; ++i) {
            mp[i] = i;
        }
    }, "Map insert");

    return 0;
}
