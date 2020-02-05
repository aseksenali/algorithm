#include <bits/stdc++.h>

using namespace std;

int d[1000000];

void dp(int n) {
    d[0] = 1;
    d[1] - 1;
    int num = 1;
    int i = 2;
    while (num < n) {
        num = d[i - 1] + d[i - 2];
        d[i] = num;
        i++;
    }
    if (num == n) {
        cout << 1 << "\n" << i - 2;
    } else {
        cout << 0;
    }
}

int main() {
    int n;
    cin >> n;
    dp(n);
}