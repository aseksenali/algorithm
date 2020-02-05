#include <iostream>

using namespace std;
int n, m, a[70][70], counters[70][70];
bool used[70][70];
int countways(int x, int y) {
    counters[0][0] = 1;
    for(int i = 0; i < y; i++) {
        if (a[x][i] + i == y) {
            if (!used[x][i]) {
                counters[x][y] += countways(x, i);
            } else {
                counters[x][y] += counters[x][i];
            }
        }
    }

    for (int i = 0; i < x; i++) {
        if (a[i][y] + i == x) {
            if (!used[i][y]) {
                counters[x][y] += countways(i, y);
            } else {
                counters[x][y] += counters[i][y];
            }
        }
    }
    used[x][y] = true;
    return counters[x][y];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cout << countways(n - 1, m - 1);
    return 0;
}