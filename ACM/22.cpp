#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int counter = 0;
    while (n != 0) {
        counter += n % 2;
        n /= 2;    
    }
    cout << counter;
}