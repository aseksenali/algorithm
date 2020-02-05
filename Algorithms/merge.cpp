#include <iostream>

using namespace std;

int n;
int a[100], b[100];

void merge(int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r) { 
        if (a[i] > a[j]) {
            b[k] = a[j];
            j++;
        } else {
            b[k] = a[i];
            i++;
        }
        k++;
    }

    while (i <= m) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= r) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int i = 0; i < k; i++) {
        a[i] = b[i];
    }
}

void mergesort(int l, int r) {
    int m = (l + r) / 2;
    if (l >= r) {
        return;
    }
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergesort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}