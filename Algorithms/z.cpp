#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector< pair<int, int>> a(n);
    int b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a[i] = make_pair(b, i);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
    int sum = 0;
    int p = 0;
    for (int i = 0; i < k; i++) {
        for (int j = p; j < a.front().second; j++) {
            a.erase(find(a.begin(), a.end(), j));
        }
    }
}