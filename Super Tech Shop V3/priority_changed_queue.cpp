#include <iostream>
#include <queue>
#include <vector>

// Custom comparator
class CustomCompare {
public:
    bool operator()(int lhs, int rhs) {
        // Change to greater for min-heap, less for max-heap
        return lhs > rhs;
    }
};

int main() {
    // Define a priority queue using the custom comparator
    std::priority_queue<int, std::vector<int>, CustomCompare> pq;

    // Insert elements
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    pq.push(9);

    // Display elements in priority order
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
