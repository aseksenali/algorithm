#include <bits/stdc++.h>

using namespace std;

int main() {
    int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;

    if (v4 <= 2 * v3 && v4 >= v3 && v4 < v2 && v4 < v1) {
        cout << v1 << endl << v2 << endl << v3;
    } else {
        cout << -1;
    }
}