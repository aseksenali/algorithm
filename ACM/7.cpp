#include <iostream>

using namespace std;

bool morethat(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }

    for(int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }

    return true;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (morethat(a, b) && morethat(a, c)) {
        cout << a;
    } else if (morethat(b, a) && morethat(b, c)) {
        cout << b;
    } else if (morethat(c, a) && morethat(c, b)) {
        cout << c;
    }
}