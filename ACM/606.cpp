#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int a, b;
        a = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
        b = (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0');
        int f = b + 1; 
        int k = b - 1;
        int c = a / 100 + a / 10 % 10 + a % 10;
        int d = f / 100 + f / 10 % 10 + f % 10;
        int e = k / 100 + k / 10 % 10 + k % 10;
        if (c == d || c == e) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}