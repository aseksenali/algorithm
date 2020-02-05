#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int d[100];
int c[100];
bool used[100];

int main() {
    d[0] = 0;
    int n;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && ((k == -1) || d[k] > d[j])) {
                k = j;
            }
        }
        used[k] = true;
        for (int j = 0; j < n; j++) {
            if (!used[j] && a[k][j] > 0 && d[j] > d[k] + a[k][j]) {
                d[j] = d[k] + a[k][j];
                c[j] = k;
            }
        }
    }
}