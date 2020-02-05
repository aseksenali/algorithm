#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int x, y;
    x = ceil(s.size() / 15.0);
    y = ceil(s.size() / ceil(s.size() / 15.0));
    int t = x - s.size() % x;
    bool ok = false;
    cout << x << " " << y << " " << t << endl;
    for (int i = 0; i < x; i++) {
        if (x - i <= t) {
            ok = true;
            y = s.size() % 15;
        }
        for (int j = 0; j < y; j++) {
            cout << s[i * 15 + j];
        }
        if (ok) cout << "*";
        cout << endl;
    }
    return 0;
}