#include <iostream>
#include <cmath>


using namespace std;

int n;


void heapify(int a[], int i) {
    if (2 * i + 1 >= n) {
        return;
    }
    int index = 2 * i + 1;
    if (2 * i + 2 < n && a[2 * i + 2] > a[index]) {
        index = 2 * i + 2;
    }
    if (a[i] < a[index]) {
        a[index] += a[i];
        a[i] = a[index] - a[i];
        a[index] -= a[i];
        heapify(a, index);
    }
}

int main() {
    
int a[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n / 2; i >= 0; i--) {
        heapify(a, i);
    }

    int k = n;
    for (int i = 0; i < k; i++) {
        swap(a[0], a[n - 1]);
        n--;
        heapify(a, 0);
    }

    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }
    return 0;
}