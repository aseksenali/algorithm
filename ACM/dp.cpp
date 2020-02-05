#include <bits/stdc++.h>

using namespace std;

int d[100000];
int s[100000];
vector<int> result;

void dp(int n) {
    memset(d, 1, sizeof(d));
    d[1] = 0;
    s[1] = 1;
    for (int i = 1; i < n; i++) {
        if (d[i + 1] > d[i] + 1) {
            d[i + 1] = d[i] + 1;
            s[i + 1] = i;
        }
        if (i * 2 <= n) {
            if (d[i * 2] > d[i] + 1) {
                d[i * 2] = d[i] + 1;
                s[i * 2] = i;
            }
        }
        if (i * 3 <= n) {
            if (d[i * 3] > d[i] + 1) {
                d[i * 3] = d[i] + 1;
                s[i * 3] = i;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    dp(n);
    cout << d[n] << endl;
    while (n != 1) {
        cout << s[n] << " ";
        n = s[n];
    }
}