#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        result += pow(-1, i) * (s[i] - '0');
    }

    if (result % 11 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}