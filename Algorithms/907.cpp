#include <iostream>
#include <string>

using namespace std;

int main() {
    int x, y;
    string s;
    cin >> s;
    x = s[0] - 'A';
    y = s[1] - '0';
    if ((x + y) % 2 == 0) cout << "WHITE";
    else cout << "BLACK";
}