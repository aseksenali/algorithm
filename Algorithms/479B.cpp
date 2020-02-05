#include <iostream>

using namespace std;

int counter = 0;
int olddif = 0;
void change(int n, int a[]) {
    int min = INT_MAX, max = 0;
    int maxIndex;
    int newdif;
    int minIndex;
    for (int i = 0; i < n; i++) {
        if (a[i] >= max) {
            maxIndex = i;
            max = a[i];
        }

        if (a[i] <= min) {
            minIndex = i;
            min = a[i];
        }
        newdif = max - min;
    }
    if (newdif > 1) {
        a[minIndex]++;
        a[maxIndex]--;
        counter++;
        cout << maxIndex + 1 << " " << minIndex + 1 << endl;
    }
    olddif = newdif;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[101];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        change(n, a);
    }
    cout << olddif << " " << counter;
    return 0;
}