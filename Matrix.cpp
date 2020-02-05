#include <iostream>

using namespace std;

class Matrix {
    private:
    int width, height;
    int data[10000][10000];

    public:
    Matrix(int a, int b) {
        width = a;
        height = b;
    }

    Matrix(int a) {
        width = height = a;
    }
    void fillMatrix() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                cin >> data[i][j];
            }
        }
    } 

    void print() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix* add(Matrix* b) {
        if ((this -> width) != (b -> width) || (this -> height) != (b -> height)) {
            cout << "Wrong size.";
            return nullptr;
        }

        Matrix* result = new Matrix(this -> width, this -> height);
        for (int i = 0; i < this -> width; i++) {
            for (int j = 0; j < this -> height; j++) {
                result -> data[i][j] = this -> data[i][j] + b -> data[i][j];
            }
        }
        return result;
    }

    
};

int main() {
    int n, m;
    cin >> n >> m;

    cout << "Enter first matrix: " << endl;
    Matrix* a = new Matrix(n, m);
    a -> fillMatrix();
    a -> print();
    int c, d;
    cin >> c >> d;
    cout << "Enter second matrix: " << endl;
    Matrix* b = new Matrix(c, d);
    b -> fillMatrix();
    b -> print();

    Matrix* sum = a -> add(b);
    cout << "a + b:" << endl;
    sum -> print();
    return 0;
}