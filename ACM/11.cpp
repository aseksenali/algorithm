#include <bits/stdc++.h>

using namespace std;

class BigInt {
    int a[100];
    int length;
    
    public:

    BigInt() {
        memset(a, 0 ,sizeof(a));
        length = 0;
    }

    void read(string s) {
        for (int i = s.length() - 1; i >= 0; i--) {
            a[i] = s[i] - '0';
        } 
        length = s.length();   
    }

    void print() {
        if (length == 0) {
            cout << 0;
        }
        for (int i = length - 1; i >= 0; i--) {
            cout << a[i];
        }
    }

    void add(BigInt c) {
        int carry = 0;
        length = max(length, c.length);
        for (int i = 0; i < max(length, c.length) || carry; ++i) {
            a[i] += carry + (i < c.length ? c.a[i] : 0);
            carry = a[i] >= 10;
            if (carry)  a[i] -= 10;
            if (i == max(length, c.length)) length++;
        }
    }
};

BigInt d[600];

void dp(int k, int n) {
    d[0].read("1");
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            d[i + j].add(d[i]);
            if (i == n) {
                return;
            }
        }
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    dp(k, n);
    d[n].print();
}