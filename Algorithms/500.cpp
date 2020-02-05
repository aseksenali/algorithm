#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    reverse(a, a + n);
    int d[n];
    memset(d, 0, sizeof(d));
    d[0] = 0;
    d[1] = a[0].second;
    d[2] = d[1] + a[1].second;
    d[3] = d[1] + a[2].second;
    for (int i = 4; i < n; i++) {
        d[i] = min(d[i - 2] + a[i - 1].second, d[i - 3] + a[i - 2].second + a[i - 1].second);
    }
    cout << d[n - 1];
    return 0;
}