#include <iostream>
#include <cmath>

using namespace std;

int a[100000];
int sz = 0;

void heapify(int i) {
    if (2 * i + 1 >= sz) {
        return;
    }
    int index = 2 * i + 1;
    if (2 * i + 2 < sz && a[2 * i + 2] > a[index]) {
        index = 2 * i + 2;
    }
    if (a[i] < a[index]) {
        swap(a[i], a[index]);
        heapify(index);
    }
}

int main() {
    int q;
    cin >> q;
    int com;
    for (int i = 0; i < q; i++) {
        cin >> com;
        if (com == 0) {
            cin >> a[sz];
            sz++;      
        } else {       
            for (int i = sz / 2; i >= 0; i--) {
                heapify(i);
            }
            swap(a[0], a[sz - 1]);
            cout << a[sz - 1] << endl;
            sz--;
            heapify(0);
        }
    }
    return 0;
}