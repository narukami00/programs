#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int id;

    Person(string n, int i) : name(n), id(i) {}

    bool operator<(const Person& other) const {
        return id < other.id;
    }
};

// Function to insert data into the map
void insertData(map<int, set<Person>>& dataMap, int key, const Person& person) {
    dataMap[key].insert(person);
}

// Function to traverse the entire map and print the data
void traverseMap(const map<int, set<Person>>& dataMap) {
    for (const auto& pair : dataMap) {
        cout << "Key: " << pair.first << endl;
        for (const auto& person : pair.second) {
            cout << "  Person Name: " << person.name << ", ID: " << person.id << endl;
        }
    }
}

int main() {
    map<int, set<Person>> dataMap;

    // Insert data into the map
    insertData(dataMap, 1, Person("Alice", 101));
    insertData(dataMap, 1, Person("Bob", 102));
    insertData(dataMap, 2, Person("Charlie", 103));
    insertData(dataMap, 3, Person("David", 104));

    // Traverse the map
    traverseMap(dataMap);

    return 0;
}
