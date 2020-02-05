#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n, k;
    cin >> n >> s;
    k = s.size();
    int result = 1;
    do {
        result *= n;
        n -= k;
    } while (n >= k);
    cout << result;
}