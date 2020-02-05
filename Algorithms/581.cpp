#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;
    long long int max = (a > b) ? a : b;
    long long int min = (a > b) ? b : a;
    int countMax = min;
    int countMin = 0;
    for (int i = min; i > 0; i--) {
        if (max == i) {
            countMin += min;
            break;
        }
        max -= 2;
        countMin++;
    }

    cout << countMin << " " << countMax;
}