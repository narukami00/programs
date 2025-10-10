#include<iostream>
#include<fstream>

using namespace std;

class Student {
    string name;
    int roll;
    float cg;
public:
    Student(){
        name = "Unknown";
        roll = 0;
        cg = 4;
    }
    Student(string s, int r, float c):name(s),roll(r),cg(c){}
    void display(){
        cout << name << " " << roll << " " << cg << endl;
    }
};

int main(){
    Student* students = new Student[10];
    for (int i = 0; i < 10; i++){
        students[i] = Student("rafsan", 6, 2.00);
    }
    fstream file("aaa.dat", ios::binary|ios::out);
    file.write((char*)students, sizeof(Student)*10);
    file.close();
    file.open("aaa.dat", ios::binary|ios::in);
    Student* st = new Student[10];
    file.read((char*)st, sizeof(Student)*10);
    for (int i = 0; i < 10; i++){
        st[i].display();
    }
    cout << "Nigga runned successfully\n";
    file.close();
}