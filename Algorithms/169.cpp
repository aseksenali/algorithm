#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int d[k][k];
    memset(d, 0, sizeof(d));
    d[0][0] = 1;
    if (n == k) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            int a = d[j - 1][i - 1];
            if (j - 1 < 0) {
                a = 0;
            }
            int b = d[j + 1][i - 1];
            if (j + 1 > k) {
                b == 0;
            }
            d[j][i] = a + b;
        }
    }
    cout << d[n - 1][k - 1];
}