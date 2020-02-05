#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int s, min, max;
    s = 0;
    min = INT_MAX;
    max = INT_MIN;
    int minindex;
    int maxindex;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            s += a[i];
        }
        if (a[i] > max) {
            max = a[i];
            maxindex = i;
        }
        if (a[i] < min) {
            min = a[i];
            minindex = i;
        }
    }

    int p = 1;
    for (int i = minindex > maxindex? maxindex : minindex; i < (minindex > maxindex? minindex: maxindex); i++) {
        if (a[i] != min && a[i] != max) {
            p *= a[i];
        }
    }

    cout << s << " " << p;
    return 0;
}