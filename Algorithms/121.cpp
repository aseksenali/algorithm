#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dp[n];
    memset(dp, 0, sizeof(dp));
    sort(a, a + n);
    dp[0] = 0;
    dp[1] = a[1] - a[0];
    dp[2] = a[2] - a[0];
    dp[3] = a[3] - a[2] + a[1] - a[0];
    for (int i = 4; i < n; i++) {
        dp[i] = min(dp[i - 2] + (a[i] - a[i - 1]), dp[i - 3] + (a[i] - a[i - 2]));
    }

    cout << dp[n - 1];
    return 0;
}