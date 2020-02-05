#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    double dd[n];
    double ds[n];
    int x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ds[i] = 2 * sqrt(pow(x - x1, 2) + pow(y - y1, 2));
        dd[i] = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
    }

    double maxd = 0, mins = INT_MAX;
    int index;
    for (int i = 0; i < n; i++) {
        if (ds[i] < mins) {
            mins = ds[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (ds[i] == mins) {
            if (dd[i] > maxd) {
                maxd = dd[i];
                index = i;
            }
        }
    }
    
    if (mins >= dd[index]) {
        cout << "NO";
    } else {
        cout << index + 1;
    }
}