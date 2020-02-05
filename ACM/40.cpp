#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a[500];
    memset(a, 0, sizeof(a));
    int counter = 1;
    int n;
    cin >> n;
    int carry = 0;   
    a[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < counter || carry; ++i) {
            if (i == counter) {
                counter++;
            }
            long long cur = carry + a[i] * 2;
            a[i] = int (cur % 10);
            carry = int (cur / 10);
        }
    }

    for (int i = counter - 1; i >= 0; i--) {
        cout << a[i];
    }
}