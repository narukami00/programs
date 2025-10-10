#include <iostream>
#include <stdexcept>

// Simulates a stack frame with a resource
class Frame {
public:
    Frame(const std::string& name) : m_name(name) {
        std::cout << "Entering " << m_name << std::endl;
    }
    ~Frame() {
        std::cout << "Exiting " << m_name << std::endl;
    }
private:
    std::string m_name;
};

void funcC() {
    Frame frameC("funcC");
    throw std::runtime_error("Exception in funcC");
}

void funcB() {
    Frame frameB("funcB");
    funcC();
}

void funcA() {
    Frame frameA("funcA");
    funcB();
}

int main() {
    try {
        funcA();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
