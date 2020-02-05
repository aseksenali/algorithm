#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

int bin(int a[], int k, int n) {
    int r = n, l = 1, mid = 0;
    while (l <= r) {
        mid = (r + l) / 2;
        if (k > a[mid - 1] && k <= a[mid])
        {
            return mid; 
            break;
        }
        if (a[mid] < k) 
            l = mid + 1;
        else if (a[mid - 1] >= k)
            r = mid - 1;
    }
    return r;
}

int main() {
    int n, m, i;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    cin >> m;

    int x;
    for (int i = 1  ; i < n + 1; i++) {
        cin >> x;
        a[i] = a[i - 1] + x;
    }

    for (i = 0; i < m + 1; i++) {
        int q;
        cin >> q;
        cout << bin(a, q, n) << endl;
    }
    return 0;
}