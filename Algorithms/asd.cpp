#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    int b, c;
    for (int i = 0; i < n; i++) {
        cin >> b >> c;
        a[i] = make_pair(b, c);
    }
    
}