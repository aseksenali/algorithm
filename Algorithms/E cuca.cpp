#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = a[i - 1] +x;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        int l = 1;
        int r = n;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] < y)
                l = mid + 1;
            else if (a[mid - 1] >= y)
                r = mid - 1;
            else if (y > a[mid - 1] && y <= a[mid]) {
                cout << mid << endl;
                break;
            }
        }
    }

    return 0;
}