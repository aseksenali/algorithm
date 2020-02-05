#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
        string s;
        cin >> s;

        bool ok1 = false, ok2 = false, ok3 = false;
        char ok[12] = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y'};
        if (s.size() != 6) {
            cout << "No" << endl;
            continue;
        }
        for (int i = 0; i < 12; i++) {
            if (s[0] == ok[i]) {
                ok1 = true;
            }
            if (s[4] == ok[i]) {
                ok2 = true;
            }
            if (s[5] == ok[i]) {
                ok3 = true;
            }
        }

        if (s[1] - '0' < 10 && s[1] - '0' >= 0 && s[2] - '0' < 10 && s[2] - '0' >= 0 && s[3] - '0' < 10 && s[3] - '0' >= 0) {
            if (ok1 && ok2 && ok3) {
                cout << "Yes" << endl;
                continue;
            }
        }

        cout << "No" << endl;
    }
}