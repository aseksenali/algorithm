#include <bits/stdc++.h>

using namespace std;

int d[500];
int a[30000];
void dp(int n) {
    memset(d, 1, sizeof(d));
    d[0] = 0;
    for (int i = 0; i < n; i++) { 
        d[i + 1] = min(abs(a[i + 1] - a[i]) + d[i], d[i + 1]);
        d[i + 2] = min(3 * abs(a[i + 2] - a[i]) + d[i], d[i + 2]);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp(n);
    cout << d[n - 1];
}