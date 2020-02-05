#include <bits/stdc++.h>

using namespace std;

int main() {
    bool bigger = false;
    bool begin = false;
    int n;
    cin >> n;
    
    if (n == 1) {
        int a;
        cin >> a;
        cout << 1;
        return 0;
    }

    int a[n];
    cin >> a[0] >> a[1];
    bigger = a[1] > a[0];
    int counter;
    if (a[1] != a[0])
        counter = 2;
    else
        counter = 1;
    int maxi = 0;
    for (int i = 2; i < n; i++) {
        scanf("%i", a + i);
        if (begin && a[i] != a[i - 1]) {
            counter++;
            begin = false;
        }
        if ((a[i] < a[i - 1] && bigger) || (a[i] > a[i - 1] && !bigger)) {
            counter++;
        } else {
            if (counter > maxi) {
                maxi = counter;
            }
            counter = 1;
            begin = true;
        }
        bigger = a[i] > a[i - 1];
    }

    if (counter > maxi) {
        maxi = counter;
    }
    cout << maxi;
}