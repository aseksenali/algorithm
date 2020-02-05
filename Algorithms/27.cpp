#include <bits/stdc++.h>

using namespace std;
int main() {
    int w, h;
    cin >> w >> h;
    int a[w][h];
    memset(a, 0, sizeof(a));
    int n;
    cin >> n;
    int area = 0;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                if (a[j][k] != 1) {
                    area++;
                    a[j][k] = 1;
                }
            }
        }
    }

    cout << w * h - area;
}