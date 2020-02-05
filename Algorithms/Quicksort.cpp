#include <iostream>

using namespace std;

int a[100];
int n;

void quicksort(int l, int r) {
    int mid = a[(l + r) / 2];
    int init_l = l;
    int init_r = r;
    while (l < r) {
        while (a[l] < mid) l++;
        while (a[r] > mid) r--;
        if (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    if (l < init_r) quicksort(l, init_r);
    if (init_l < r) quicksort(init_l, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quicksort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}