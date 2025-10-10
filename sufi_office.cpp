#include <fstream>  // for file-stream functions
#include <iostream>
#include <typeinfo> // for typeid()
#include <process.h> // for exit()

using namespace std;

const int LEN = 32; // maximum length of last names
const int MAXEM = 100; // maximum number of employees

enum employee_type { tmanager, tscientist, tlaborer };

class employee {
private:
    char name[LEN]; // employee name
    unsigned long number; // employee number
    static int n; // current number of employees
    static employee* arrap[MAXEM]; // array of pointers to employees

public:
    virtual void getdata() {
        cin.ignore(10, '\n');
        cout << "Enter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    virtual void putdata() {
        cout << "Name: " << name;
        cout << " Number: " << number;
    }

    virtual employee_type get_type(); // get type

    static void add(); // add an employee
    static void display(); // display all employees
    static void read(); // read from disk file
    static void write(); // write to disk file
};

// static variables
int employee::n = 0; // current number of employees
employee* employee::arrap[MAXEM]; // array of pointers to employees

class manager : public employee {
private:
    char title[LEN]; // "vice-president" etc.
    double dues; // golf club dues

public:
    void getdata() {
        employee::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter golf club dues: ";
        cin >> dues;
    }

    void putdata() {
        employee::putdata();
        cout << " Title: " << title;
        cout << " Golf club dues: " << dues;
    }
};

class scientist : public employee {
private:
    int pubs; // number of publications

public:
    void getdata() {
        employee::getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
    }

    void putdata() {
        employee::putdata();
        cout << " Number of publications: " << pubs;
    }
};

class laborer : public employee {
    // No additional data members
};

// add employee to list in memory
void employee::add() {
    char ch;
    cout << "'m' to add a manager\n's' to add a scientist\n'l' to add a laborer\nEnter selection: ";
    cin >> ch;

    switch (ch) {
    case 'm':
        arrap[n] = new manager;
        break;
    case 's':
        arrap[n] = new scientist;
        break;
    case 'l':
        arrap[n] = new laborer;
        break;
    default:
        cout << "Unknown employee type\n";
        return;
    }
    arrap[n++]->getdata(); // get employee data from user
}

// display all employees
void employee::display() {
    for (int j = 0; j < n; j++) {
        cout << (j + 1);
        switch (arrap[j]->get_type()) {
        case tmanager:
            cout << ". Type: Manager";
            break;
        case tscientist:
            cout << ". Type: Scientist";
            break;
        case tlaborer:
            cout << ". Type: Laborer";
            break;
        default:
            cout << "Unknown type";
        }
        arrap[j]->putdata();
        cout << endl;
    }
}

// return the type of this object
employee_type employee::get_type() {
    if (typeid(*this) == typeid(manager))
        return tmanager;
    else if (typeid(*this) == typeid(scientist))
        return tscientist;
    else if (typeid(*this) == typeid(laborer))
        return tlaborer;
    else {
        cerr << "Bad employee type";
        exit(1);
    }
    return tmanager; // should never reach here
}

// write all current memory objects to file
void employee::write() {
    int size;
    cout << "Writing " << n << " employees.\n";
    ofstream ouf; // open ofstream in binary
    employee_type etype; // type of each employee object

    ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
    if (!ouf) {
        cout << "Can't open file\n";
        return;
    }

    for (int j = 0; j < n; j++) { // for every employee object
        // get its type
        etype = arrap[j]->get_type();
        // write type to file
        ouf.write((char*)&etype, sizeof(etype));
        // find its size
        switch (etype) {
        case tmanager:
            size = sizeof(manager);
            break;
        case tscientist:
            size = sizeof(scientist);
            break;
        case tlaborer:
            size = sizeof(laborer);
            break;
        }
        // write employee object to file
        ouf.write((char*)(arrap[j]), size);
        if (!ouf) {
            cout << "Can't write to file\n";
            return;
        }
    }
}

// read data for all employees from file into memory
void employee::read() {
    int size; // size of employee object
    employee_type etype; // type of employee
    ifstream inf; // open ifstream in binary

    inf.open("EMPLOY.DAT", ios::binary);
    if (!inf) {
        cout << "Can't open file\n";
        return;
    }

    n = 0; // no employees in memory yet
    while (true) {
        // read type of next employee
        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof()) // quit loop on eof
            break;
        if (!inf) { // error reading type
            cout << "Can't read type from file\n";
            return;
        }
        // make new employee of correct type
        switch (etype) {
        case tmanager:
            arrap[n] = new manager;
            size = sizeof(manager);
            break;
        case tscientist:
            arrap[n] = new scientist;
            size = sizeof(scientist);
            break;
        case tlaborer:
            arrap[n] = new laborer;
            size = sizeof(laborer);
            break;
        default:
            cout << "Unknown type in file\n";
            return;
        }
        // read data from file into it
        inf.read((char*)arrap[n], size);
        if (!inf) { // error but not eof
            cout << "Can't read data from file\n";
            return;
        }
        n++; // count employee
    }
    cout << "Reading " << n << " employees\n";
}

int main() {
    char ch;
    while (true) {
        cout << "'a' .. add data for an employee\n'd' .. display data for all employees\n'w' .. write all employee data to file\n'r' .. read all employee data from file\n'x' .. exit\nEnter selection: ";
        cin >> ch;
        switch (ch) {
        case 'a': // add an employee to list
            employee::add();
            break;
        case 'd': // display all employees
            employee::display();
            break;
        case 'w': // write employees to file
            employee::write();
            break;
        case 'r': // read all employees from file
            employee::read();
            break;
        case 'x':
            exit(0); // exit program
        default:
            cout << "Unknown command\n";
        }
    }
    return 0;
}
