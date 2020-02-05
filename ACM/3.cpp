#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a;
    cin >> a;
    if (a == 5) {
        cout << "25";
        return 0;
    }
    long long int b = a / 10;
    cout << b * (b + 1) << "25";
}