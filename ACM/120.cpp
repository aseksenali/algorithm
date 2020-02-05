#include <bits/stdc++.h>

using namespace std;

int a[22][22];
int d[22][22];

void dp(int n, int m) {
    memset(d, 1, sizeof(d));
    d[0][0] = a[0][0];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i + 1][j] = min(d[i][j] + a[i + 1][j], d[i + 1][j]);
            d[i][j + 1] = min(d[i][j] + a[i][j + 1], d[i][j + 1]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp(n, m);
    cout << d[n - 1][m - 1];
}