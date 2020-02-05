#include <bits/stdc++.h>

using namespace std;

set<long long int> k;

int main() {
    int n;
    cin >> n;
    vector<long long int> x;
    x.push_back(1);
    k.insert(1);
    for (int i = 0; i < n; i++) {
        if (k.find(x[i] * 2) == k.end()) {
            x.push_back(x[i] * 2);
            k.insert(x[i] * 2);
        }
        if (k.find(x[i] * 3) == k.end()) {
            x.push_back(x[i] * 3);
            k.insert(x[i] * 3);
        }
        if (k.find(x[i] * 5) == k.end()) {
            x.push_back(x[i] * 5);
            k.insert(x[i] * 5);
        }
    }

    sort(x.begin(), x.end());
    cout << x[n - 1];
}