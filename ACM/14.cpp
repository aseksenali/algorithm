#include <bits/stdc++.h>

using namespace std;

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << a * b / gcd(a, b);
}