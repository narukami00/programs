#include <iostream>
using namespace std;

// template<typename T>
// void exceptionHandler(T c){
// try{throw c;}
// catch(char c){cout<<"character\n";}
// catch(int x){cout<<"integer\n";}
// catch(double d){cout<<"double\n";}
// }
// int main(){
// exceptionHandler('a'-0);}

template<typename T>
void exceptionHandler(T c)  { // Exception specification
    throw c; // Simply throw the exception
}

int main() {
    try {
        exceptionHandler('a'-0);
    } catch (char c) {
        cout << "character\n";
    } catch (int x) {
        cout << "integer\n";
    } catch (double d) {
        cout << "double\n";
    }
    return 0;
}