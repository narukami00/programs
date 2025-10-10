#include <iostream>
using namespace std;

class TimeMS; // Forward declaration

class TimeHM {
private:
    int hours;
    int minutes;

public:
    TimeHM(int h = 0, int m = 0) : hours(h), minutes(m) {}

    friend TimeHM operator+(const TimeHM& hm, const TimeMS& ms);
    friend void addTime(TimeHM& hm, const TimeMS& ms);

    void display() const {
        cout << "Time: " << hours << " hours and " << minutes << " minutes" << endl;
    }
};

class TimeMS {
private:
    int minutes;
    int seconds;

public:
    TimeMS(int m = 0, int s = 0) : minutes(m), seconds(s) {}

    friend TimeHM operator+(const TimeHM& hm, const TimeMS& ms);
    friend void addTime(TimeHM& hm, const TimeMS& ms);

    void display() const {
        cout << "Time: " << minutes << " minutes and " << seconds << " seconds" << endl;
    }
};

// Friend function to perform the addition operation
void addTime(TimeHM& hm, const TimeMS& ms) {
    hm.minutes += ms.minutes;
    hm.hours += (hm.minutes / 60);
    hm.minutes %= 60;

    cout << "After addition: ";
    hm.display();
}

// Overloading the + operator
TimeHM operator+(const TimeHM& hm, const TimeMS& ms) {
    TimeHM result = hm;
    result.minutes += ms.minutes;
    result.hours += (result.minutes / 60);
    result.minutes %= 60;

    return result;
}

int main() {
    TimeHM t1(2, 30);
    TimeMS t2(45, 30);

    t1.display();
    t2.display();

    addTime(t1, t2); // Using friend function

    TimeHM t3 = t1 + t2; // Using overloaded + operator
    cout << "Using + operator: ";
    t3.display();

    return 0;
}

