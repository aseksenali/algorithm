#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int counter = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            counter++;
        } else {
            if (counter > max) {
                max = counter;
            }
            counter = 0;
        }
    }

    if (counter > max) {
        max = counter;
    }
    cout << max;
}