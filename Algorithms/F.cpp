#include <iostream>
#include <algorithm>

using namespace std;

void bubble(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                a[j] += a[j + 1];
                a[j + 1] = a[j] - a[j + 1];
                a[j] -= a[j + 1];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int counter = 1;
    int max = 1;
    int m = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubble(a, n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] == a[i]) {
            counter++;   
            if (counter > max) {
                max = counter;
            }
            continue;
        }
        counter = 1;
        m++;
    }

    cout << max << " " << m;
    return 0;
}