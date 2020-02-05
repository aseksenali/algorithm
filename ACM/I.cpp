#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int d[100];
bool used[100];

int main() {
    bool OK;
    int t;
    cin >> t;
    for (int h = 0; h < t; h++) {
        memset(a, 0, sizeof(a));
        memset(d, 1, sizeof(d));
        OK = true;
        d[0] = 0;
        int n, m, x, y, dist;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> dist;
            a[x - 1][y - 1] = dist;
            a[y - 1][x - 1] = dist;
        }

        for (int i = 0; i < n; i++) {
            int k = -1;
            for (int j = 0; j < n; j++) {
                if (!used[j] && ((k == -1) || d[k] > d[j])) {
                    k = j;
                }
            }
            used[k] = true;
            for (int j = i + 1; j < n; j++) {
                if (d[i] == a[k][j]) {
                    OK = false;
                }
                if (!used[j] && a[k][j] > 0 && d[j] > a[k][j]) {
                    d[j] = a[k][j];
                }
            }
        }
        if (OK == true) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += d[i];
            }
            cout << sum << endl;
        } else {
            cout << "Not Unique!" << endl;
        }
    }
}