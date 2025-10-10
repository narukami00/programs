#include <iostream>
#include <string>

class Person {
private:
    std::string name;

public:
    Person(const std::string& n) : name(n) {std::cout<<"person copy\n";}

    virtual void info() const {
        std::cout << "Name: " << name << std::endl;
    }

    virtual ~Person() {}  // Ensure proper cleanup in derived classes
};

class Student : public Person {
private:
    int matric_number;

public:
    Student(const std::string& n, int m) : Person(n), matric_number(m) {std::cout<<"student copy\n";}

    void info() const override {
        Person::info();  // Call base class info
        std::cout << "Matric Number: " << matric_number << std::endl;
    }
};

class MasterStudent : public Student {
private:
    std::string subject;

public:
    MasterStudent(const std::string& n, int m, const std::string& s)
        : Student(n, m), subject(s) {std::cout<<"master copy\n";}

    void info() const override {
        Student::info();  // Call base class info
        std::cout << "Subject: " << subject << std::endl;
    }
};

int main() {
    Person p("John Doe");
    Student s("Jane Doe", 12345);
    MasterStudent ms("Alice Smith", 54321, "Computer Science");
    std::cout<<"\n";
    p.info();
    std::cout << std::endl;

    s.info();
    std::cout << std::endl;

    ms.info();
    std::cout << std::endl;

    return 0;
}
