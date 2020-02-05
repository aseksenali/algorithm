#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100];
    memset(a, 0, sizeof(a));
    a[0] = 1;
    int length = 1;
    for (int b = 1; b <= n; b++) {
        long long int carry = 0;
        for (size_t i = 0; i < length || carry; ++i) {
            long long cur = carry + a[i] * 1ll * b;
            a[i] = int (cur % 10);
            if (i == length) {
                while (carry != 0) {
                    length++;
                    carry /= 10;
                }
            }
            carry = int (cur / 10);
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}