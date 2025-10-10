#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    double cg;

    // Overload the >> operator for input
    friend istream& operator>>(istream& in, Student& s) {
        in >> s.name >> s.roll >> s.cg;
        return in;
    }

    // Overload the << operator for output
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Name: " << s.name << "\nRoll: " << s.roll << "\nCG: " << s.cg;
        return out;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    Student s;

    if (in.is_open() && out.is_open()) {
        in >> s;  // Reads data from "input.txt" into the `Student` object `s`
        out << s; // Writes data from the `Student` object `s` into "output.txt"
        in.close();
        out.close();
    } else {
        cout << "Failed to open input or output file." << endl;
    }

    return 0;
}
