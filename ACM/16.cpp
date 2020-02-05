#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result[n];
    memset(result, 0, sizeof(result));
    for (int i = 1; i < n; i++) {
        int j = result[i - 1];
        while (j > 0 && a[i] != a[j])
            j = result[j - 1];
        if (a[i] == a[j]) j++;
        result[i] = j;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    int index = 0, counter = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] <= counter) {
            index = i;
            counter++;
        }
    }

    cout << index;
}