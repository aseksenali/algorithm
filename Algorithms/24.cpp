#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << n;
        return 0;
    }

    if (m == 0) {
        cout << 1;
        return 0;
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int d = 0; d < n; d++) {
            if (i + (m - 1) * d + m <= n) {
                counter++;
            } else {
                break;
            }
        }
    }

    cout << counter;
}