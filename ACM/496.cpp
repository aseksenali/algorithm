#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, k;
    cin >> n >> k;
    int counter = 0;
    int i = n;
    while (i > 9) {
        cout << '9';
        i -= 9;
        counter++;
    }
    cout << i;
    counter++;
    for (int i = 0; i < k - counter; i++) {
        cout << '0';
    }
    cout << " 1";
    i = n - 1;
    string s = "";
    counter = 0;
    while (i > 9) {
        s += '9';
        i -= 9;
        counter++;
    }
    s = s + char(i + '0');

    for (int i = 0; i < k - counter - 2; i++) {
        s += '0';
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
}