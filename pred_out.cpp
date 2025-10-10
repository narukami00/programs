#include <iostream>
#include <set>
#include <algorithm>

class Lsb_less {
public:
    bool operator()(int x, int y) {
        return (x % 10) < (y % 10);
    }
};

int main() {
    std::set<int, Lsb_less> s = {21, 23, 26, 27};
    std::set<int, Lsb_less>::iterator itr1, itr2;

    itr1 = std::find(s.begin(), s.end(), 36);
    itr2 = s.find(36);

    if (itr1 != s.end()) {
        std::cout << "Found 36 using std::find\n";
    } else {
        std::cout << "36 not found using std::find\n";
    }

    if (itr2 != s.end()) {
        std::cout << "Found 36 using set's find\n";
    } else {
        std::cout << "36 not found using set's find\n";
    }

    return 0;
}
