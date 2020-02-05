#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxi = 0;
    int index = 0;
    set<int> k;
    for (int i = 0; i < n; i++) {
        k.clear();
        for (int j = 1; j <= a[i]; j++) {
            if (a[i] % j == 0) {
                k.insert(j);
            }
        } 

        if (k.size() > maxi) {
            maxi = k.size();
            index = i;
        }
    }

    cout << a[index];
}