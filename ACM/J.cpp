#include <bits/stdc++.h>

using namespace std;

double a[1000][1000];
bool used[1000];
int n;
double d[1000];

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void minost() {
    fill(d, d + n, INT_MAX);
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && ((k == -1) || d[k] > d[j])) {
                k = j;
            }
        }
        used[k] = true;
        for (int j = 0; j < n; j++) {
            if (!used[j] && a[k][j] > 0 && d[j] > a[k][j]) {
                d[j] = a[k][j];
            }
        }
    }
}

int main() {
    int t;
    int s;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> s >> n;
        double x[1000], y[1000];
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = dist(x[i], y[i], x[j], y[j]);
            }
        }
        minost();
        sort(d, d + n);
        printf("%.2f", d[n - 1 - s / 2]);
        cout << endl;
        memset(d, 0, sizeof(d));
        memset(a, 0, sizeof(a));
        memset(used, 0, sizeof(used));
    }
}