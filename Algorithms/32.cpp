#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    bool neg1 = false, neg2 = false;
    cin >> a >> b;
    if(a[0] == '-') {
        neg1 = true;
        a = a.substr(1, a.size() - 1);
    }
    if(b[0] == '-') {
        neg2 = true;
        b = b.substr(1, b.size() - 1);
    }
    vector<int> a1;
    vector<int> b1;
    for (int i = 0; i < a.size(); i++) {
        a1.push_back(a[i] - '0');
    }

    for (int i = 0; i < b.size(); i++) {
        b1.push_back(b[i] - '0');
    }

    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    if (!neg1) {
        reverse(a1.begin(), a1.end());
    }

    if (neg2) {
        reverse(b1.begin(), b1.end());
    }
    
    if (a1[0] == 0) {
        int i;
        for (i = 1; a1[i] == 0; i++);
        swap(a1[0], a1[i]);
    }

    if (b1[0] == 0) {
        int i;
        for (i = 1; b1[i] == 0; i++);
        swap(b1[0], b1[i]);
    }

    long long  h = 0, w = 0;
    for (int i = 0; i < a1.size(); i++) {
        h += a1[i] * pow(10, a1.size() - 1 - i);
    }

    for (int i = 0; i < b1.size(); i++) {
        w += b1[i] * pow(10, b1.size() - 1 - i);
    }

    cout << h * pow(-1, neg1) - w * pow(-1, neg2);
}