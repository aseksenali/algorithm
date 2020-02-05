#include <iostream>

using namespace std;

void quickSort(int left, int right, int arr[]) {

    int a = left;
    int b = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (a <= b) {
        while (arr[a] < pivot)
            a++;
        while (arr[b] > pivot)
            b--;
        if (a <= b) {
            tmp = arr[a];
            arr[a] = arr[b];
            arr[b] = tmp;
            a++;
            b--;
        }
    };
    if (left < b) {
        quickSort(left, b, arr);
    }
    if (a < right) {
        quickSort(a, right, arr);
    }
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(0, n - 1, a);

    for (int i = 1; i < n - 1; i++) {
        if ((a[i] > a[0]) && (a[i] < a[n - 1])) cnt++;
    }
    cout << cnt;

    return 0;
}