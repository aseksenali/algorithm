#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[500000];
    memset(a, 0, sizeof(a));
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        a[i] = (int)(s[s.size() - i - 1] - '0');
    }
    int b;
    cin >> b;
    
    if (b == 0) {
        cout << 0;
        return 0;
    }

    int counter = s.size();
    int carry = 0;
    for (int i = 0; i < counter || carry; ++i) {
        if (i == counter) {
            counter++;
        }
        long long cur = carry + a[i] * b;
        a[i] = int (cur % 10);
        carry = int (cur / 10);
    }

    for (int i = counter - 1; i >= 0; i--) {
        cout << a[i];
    }
}