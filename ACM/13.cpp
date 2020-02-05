#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int c[4], d[4];
    for (int i = 0; i < 4; i++) {
        c[i] = a[i] - '0';
        d[i] = b[i] - '0';
    }

    int result1 = 0, result2 = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (c[i] == d[j]) {
                if (i == j) {
                    result1++;
                } else {
                    result2++;
                }
            }
        }
    }

    cout << result1 << " " << result2;
    return 0;
}