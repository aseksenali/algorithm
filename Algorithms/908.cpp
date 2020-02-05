#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    memset(d, 1, sizeof(d));
    d[n - 1] = 0;
    for (int i = n - 1; i >= 0; i--) {
        d[i - 1] = min(d[i - 1], d[i] + 1);
        if ((i + 1) % 2 == 0) {
            d[(i + 1) / 2 - 1] = min(d[(i + 1) / 2 - 1], d[i] + 1);
        }
        if ((i + 1) % 3 == 0) {
            d[(i + 1) / 3 - 1] = min(d[(i + 1) / 3 - 1], d[i] + 1);
        }
    }

    cout << d[0];
}