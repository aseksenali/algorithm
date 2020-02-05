#include <iostream>
#


using namespace std;

int n;
int a[100];

void heapify(int k) {
    if (k * 2 + 1 >= n) {
        return;
    }
    int index = 2 * k + 1;
    int m_ch = a[2 * k + 1];
    if (2 * k + 2 < n && a[2 * k + 2] > m_ch) {
        m_ch = a[2 * k + 2];
        index = 2 * k + 2;
    }

    if (a[k] < m_ch) {
        swap(a[k], a[index]);
        heapify(index);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n / 2; i >= 0; i--) {
        heapify(i);
    }
    int m = n;
    for (int i = 0; i < m; i++) {
        swap(a[0], a[n - 1]);
        n--;
        heapify(0);
    }
    
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    return 0;
}