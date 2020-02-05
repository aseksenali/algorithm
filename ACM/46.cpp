#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    s = "271828182845904523536028750";
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (i == 1) cout << '.';
        if (i == n) {
            if (s[i + 1] - '0' < 5)
                cout << s[i] - '0';
            else 
                cout << s[i] - '0' + 1;
        } else {
            cout << s[i] - '0';
        }
    }
}