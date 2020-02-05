#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int counter = 0;
    int result = 0;
    for (int h = 1; h < n; h++) {
        for (int i = 0; i < n - h; i++) {
            counter = 0;
            for (int j = i; j <= i + h / 2; j++) {
                if (s[j] == s[i + h - j - 1]) {
                    counter++;
                }
            }
        }   
        if (counter < k) {
            result++;
        }
    }

    cout << result;
}