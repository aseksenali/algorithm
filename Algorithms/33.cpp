#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
        result %= 10;
    }
    cout << result;
}