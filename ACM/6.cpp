#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int x1, y1, x2, y2;
    if (s.size() != 5) {
        cout << "ERROR" << endl;
        return 0;
    }

    x1 = s[0] - 'A';
    y1 = s[1] - '0';
    x2 = s[3] - 'A';
    y2 = s[4] - '0';
    if (x1 < 0 || y1 <= 0 || x2 < 0 || y2 <= 0 || x1 > 8 || y1 >= 8 || x2 > 8 || y2 >= 8) {
        cout << "ERROR" << endl;
        return 0;
    }

    if ((abs(x2 - x1) == 2) && (abs(y2 - y1) == 1)) {
        cout << "YES" << endl;
        return 0;
    } 

    if ((abs(x2 - x1) == 1) && (abs(y2 - y1) == 2)) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}