#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int d[100];
bool used[100];

int main() {
    bool OK = true;
    memset(d, 1, sizeof(d));
    d[0] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && ((k == -1) || d[k] > d[j])) {
                k = j;
            }
        }
        used[k] = true;
        for (int j = i; j < n; j++) {
            if (d[i] == a[k][j]) {
                OK = false;
            }
            if (!used[j] && a[k][j] > 0 && d[j] > a[k][j]) {
                d[j] = a[k][j];
            }
        }
    }
    if (OK == true)
        for (int i = 0; i < n; i++) {
            cout << d[i] << " ";
        }
    else {
        cout << "Not Unique!";
    }
}