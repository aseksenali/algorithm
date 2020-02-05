#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a[5000];
    memset(a, 0, sizeof(a));
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        a[i] = (int)(s[s.size() - i - 1] - '0');
    }

    long long int b[5000];
    memset(b, 0, sizeof(b));
    string s1;
    cin >> s1;
    for (int i = 0; i < s1.size(); i++) {
        b[i] = (int)(s1[s1.size() - i - 1] - '0');
    }
    
    bool isamore;
    if (s.size() > s1.size()) {
        isamore = true;
    } else if (s.size() < s1.size()) {
        isamore = false;
    } else {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (a[i] > b[i]) {
                isamore = true;
                break;
            } 
            else if (a[i] < b[i]) {
                isamore = false;
                break;
            } else {
                cout << 0;
                return 0;
            }
        }
    }

    int carry = 0;
    if (isamore) {
        for (int i = 0; i < s.size() || carry; ++i) {
            a[i] -= carry + (i < s1.size() ? b[i] : 0);
            carry = a[i] < 0;
            if (carry)  a[i] += 10;
        }
    } else {
        for (int i = 0; i < s1.size() || carry; ++i) {
            b[i] -= carry + (i < s.size() ? a[i] : 0);
            carry = b[i] < 0;
            if (carry)  b[i] += 10;
        }
    }

    bool vivelo = false;
    if (isamore) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (vivelo || a[i] != 0) {
                cout << a[i];
                vivelo = true;
            }
        }
    } else {
        cout << '-';
        for (int i = s1.size() - 1; i >= 0; i--) {
            if (vivelo || b[i] != 0) {
                cout << b[i];
                vivelo = true;
            }
        }
    }
}