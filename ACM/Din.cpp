#include <bits/stdc++.h>

using namespace std;

int d[100];

void dp(int n) {
    memset(d, 1, sizeof(d));
    d[1] = 0;
    for(int i = 1; i < n; i++) {
        if (i * 2 <= n) {
            d[i * 2] = min(d[i * 2], d[i] + 1);
        }
        if (i * 3 <= n) {
            d[i * 3] = min(d[i * 3], d[i] + 1);
        }
        d[i + 1] = min(d[i + 1], d[i] + 1);
    }
}

int main() {
    int n;
    cin >> n;
    dp(n);
    cout << d[n];
}