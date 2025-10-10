#include <iostream>
using namespace std;

class Animal {
public:
    virtual void treat() = 0;
};

class Cat : public Animal {
public:
    void treat() override {
        cout << "Cat\n";
    }
};

class Dog : public Animal {
public:
    void treat() override {
        cout << "Dog\n";
    }

    void bark() {
        cout << "Woof\n";
    }
};

void treatAnimal(Animal *p, int &dogCount) {
    p->treat();

    // Use dynamic_cast to check if p is of type Dog
    Dog* dogPtr = dynamic_cast<Dog*>(p);
    if (dogPtr != nullptr) {
        dogPtr->bark();
        ++dogCount;
    }
}

int main() {
    Animal* animals[] = { new Cat(), new Dog(), new Cat(), new Dog() };
    int dogCount = 0;

    for (Animal* animal : animals) {
        treatAnimal(animal, dogCount);
    }

    cout << "Total number of dogs treated: " << dogCount << endl;

    // Clean up allocated memory
    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
