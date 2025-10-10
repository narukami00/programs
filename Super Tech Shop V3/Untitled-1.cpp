#include<iostream>
using namespace std;


class Matrix{
    int row, col;
    int **p;
public:
    Matrix(int a, int b){
        row = a;
        col = b;
        p = new int*[a];
        for (int i = 0; i < a; i++){
            p[i] = new int[b];
            for (int j = 0; j < b; j++) p[i][j] = 0;
        }
    }
    
    int* operator[](int index){
        return p[index];
    }


    friend ostream& operator << (ostream& out, Matrix& mat);
};



    ostream& operator << (ostream& out, Matrix& mat){
        for(int i=0;i<mat.row;i++){
            for(int j=0;j<mat.col;j++){
                out<<mat[i][j]<<" ";
            }
            out<<endl;
        }
        return out;
    }

int main(){
Matrix matrix(3, 3);
// matrix[2][3] = 100;
    matrix[1][2] = 9;
    cout << matrix;
    
}