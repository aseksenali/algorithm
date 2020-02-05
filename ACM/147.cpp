#include <bits/stdc++.h>

using namespace std;

int d[40];

int dp(int n) {
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        d[i + 1] += d[i];
        d[i + 2] += d[i];
    }
    return d[n - 1];
}

int main() {
    int n;
    cin >> n;
    cout << dp(n);
}