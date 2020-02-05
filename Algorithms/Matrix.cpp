#include <bits/stdc++.h>

using namespace std;

class Matrix {
    private:
    int width, height;
    int data[10000][10000];

    public:
    Matrix(int a, int b) {
        height = a;
        width = b;
    }

    Matrix(int a) {
        width = height = a;
        fillMatrix();
    }
    void fillMatrix() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cin >> data[i][j];
            }
        }
    } 

    void print() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix* add(Matrix* b) {
        if ((this -> width) != (b -> width) || (this -> height) != (b -> height)) {
            cout << "Wrong size.";
            return NULL;
        }

        Matrix* result = new Matrix(this -> width, this -> width);
        for (int i = 0; i < this -> height; i++) {
            for (int j = 0; j < this -> width; j++) {
                result -> data[i][j] = this -> data[i][j] + b -> data[i][j];
            }
        }
        return result;
    }
    
	Matrix* substract(Matrix* b) {
		if ((this -> width) != (b -> width) || (this -> height) != (b -> height)) {
            cout << "Wrong size.";
            return NULL;
        }

        Matrix* result = new Matrix(this -> height, this -> width);
        for (int i = 0; i < this -> height; i++) {
            for (int j = 0; j < this -> width; j++) {
                result -> data[i][j] = this -> data[i][j] - b -> data[i][j];
            }
        }
        return result;
	}
    
    Matrix* multiply(Matrix* b) {
    	if (this -> width != b -> height) {
    		cout << "Wrong size.";
    		return NULL;
		}
		
		Matrix* result = new Matrix(this -> height, b -> width);
    	for(int i = 0; i < this -> height; i++) {
    		for (int j = 0; j < b -> width; j++) {
    			for (int k = 0; k < b -> height; k++) {
    				result -> data[i][j] += this -> data[i][k] * b -> data[k][j];
				}
			}
		}
		
		return result;
	}
	
	Matrix* transpose() {
		Matrix* result = new Matrix(this -> width, this -> height);
		for (int i = 0; i < this -> height; i++) {
			for (int j = 0; j < this -> width; j++) {
				result -> data[j][i] = this -> data[i][j];
			}
		}
		
		return result;
	}

	Matrix* echelonize() {
		Matrix* result = new Matrix(this -> width, this -> height);
		for (int col = 0, row = 0; col < this -> width && row < this -> height; col++) {
			int sel = col;
			for (int i = row; i < this -> height; i++) {
				if (abs(this -> data[i][col]) > abs(this -> data[sel][col])) {
					sel = i;
				}
			}
			for (int i = col; i <= this -> width; i++) {
				swap(this -> data[sel][i], this -> data[row][i]);
				result[col] = row;
			}
		}
	}
};

int main() {
	string s;
	cin >> s;
	if (s == "+") {
	    int n, m, c, d;
	    cin >> n >> m;
	
	    cout << "Enter first matrix: " << endl;
	    Matrix* a = new Matrix(n, m);
	    a -> fillMatrix();
	    a -> print();

		cout << endl;
		cin >> c >> d;	
	    cout << "Enter second matrix: " << endl;
	    Matrix* b = new Matrix(c, d);
	    b -> fillMatrix();
	    b -> print();
	
	    Matrix* sum = a -> add(b);
	    if (sum != NULL) {
	        cout << "a + b:" << endl;
	        sum -> print();
	    }
	} else if (s == "-") {
		int n, m, c, d;
	    cin >> n >> m;
	
	    cout << "Enter first matrix: " << endl;
	    Matrix* a = new Matrix(n, m);
	    a -> fillMatrix();
	    a -> print();
	
		cout << endl;
		cin >> c >> d;	
	    cout << "Enter second matrix: " << endl;
	    Matrix* b = new Matrix(c, d);
	    b -> fillMatrix();
	    b -> print();
	
	    Matrix* sub = a -> substract(b);
	    if (sub != NULL) {
	        cout << "a - b:" << endl;
	        sub -> print();
	    }
	} else if (s == "*") {
		int n, m, c, d;
	    cin >> n >> m;
	
	    cout << "Enter first matrix: " << endl;
	    Matrix* a = new Matrix(n, m);
	    a -> fillMatrix();
	    a -> print();
	
		cout << endl;
		cin >> c >> d;	
	    cout << "Enter second matrix: " << endl;
	    Matrix* b = new Matrix(c, d);
	    b -> fillMatrix();
	    b -> print();
	
	    Matrix* mul = a -> multiply(b);
	    if (mul != NULL) {
	        cout << "a * b:" << endl;
	        mul -> print();
	    }
	} else if (s == "transpose" ) {
		int n, m;
		cin >> n >> m;
		Matrix* a = new Matrix(n, m);
		a -> fillMatrix();
		a -> transpose() -> print();
	}
    return 0;
}
