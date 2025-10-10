#include <iostream>
using namespace std;

// Forward declaration for friend function
class DB;

class DM {
    double meters;
    double centimeters;

public:
    DM(double m = 0, double cm = 0) : meters(m), centimeters(cm) {}

    // Friend function to add distances from DM and DB
    friend DM addDistances(const DM&, const DB&);

    void display() const {
        cout << "Meters: " << meters << " Centimeters: " << centimeters << endl;
    }
};

class DB {
    double feet;
    double inches;

public:
    DB(double ft = 0, double in = 0) : feet(ft), inches(in) {}

    // Friend function to add distances from DM and DB
    friend DM addDistances(const DM&, const DB&);

    void display() const {
        cout << "Feet: " << feet << " Inches: " << inches << endl;
    }
};

// Conversion constants
const double CM_TO_INCH = 0.39;
const double INCH_TO_CM = 2.54;
const double M_TO_CM = 100;
const double FT_TO_INCH = 12;
const double INCH_TO_FT = 1 / FT_TO_INCH;

DM addDistances(const DM& dm, const DB& db) {
    // Convert DM to centimeters
    double totalCm = dm.meters * M_TO_CM + dm.centimeters;

    // Convert DB to centimeters
    double totalInches = db.feet * FT_TO_INCH + db.inches;
    totalCm += totalInches * INCH_TO_CM;

    // Convert back to meters and centimeters
    double meters = totalCm / M_TO_CM;
    double centimeters = totalCm - (int(meters) * M_TO_CM);
    return DM(meters, centimeters);
}

int main() {
    DM dm(1, 50);  // 1 meter 50 cm
    DB db(5, 9);   // 5 feet 9 inches

    DM result = addDistances(dm, db);
    result.display();

    return 0;
}
