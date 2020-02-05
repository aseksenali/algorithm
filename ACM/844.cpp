#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, f , l;
    cin >> n >> m >> f >> l;
    cout << (m + f) - (n - l) << " " << n - l - f << " " << n - l - m;
}