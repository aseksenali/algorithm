#include <bits/stdc++.h>

using namespace std;

map<int, int> spies;
int d[10001];

void dp(int n) {
    
}

int main() {
    int n;
    cin >> n;
    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        spies.insert(make_pair(a, b));
    }

    for (map<int, int>::iterator it = spies.begin(); it != spies.end(); it++) {
        cout << *it;
    }
