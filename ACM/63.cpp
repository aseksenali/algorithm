#include <bits/stdc++.h>

using namespace std;

int a[1000000];

int main() {
    int n;
    cin >> n;
    int carry = 0;
    int length = 1;
    a[0] = 1;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < length || carry; i++) {
            if (i == length) {
                length++;
            }
            long long int cur = carry + a[i] * 2;
            a[i] = cur % 10;
            carry = cur / 10;
        }

    for (int i = length - 1; i >= 0; i--) {
        cout << a[i];
    }
}