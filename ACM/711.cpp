#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string names[n];
    int a[n][m];
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int results[n];
    int min = INT_MAX;
    string name;
    memset(results, 0, sizeof(results));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            results[i] += a[i][j];
        }
        if (results[i] < min) {
            min = results[i];
            name = names[i];
        }
    }

    cout << name;
}