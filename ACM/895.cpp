#include <bits/stdc++.h>

using namespace std;

int main() {
    int n[3][3];
    char d;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> d;
            switch(d){
                case 'O':
                    n[i][j] = 0;
                    break;
                case 'X':
                    n[i][j] = 1;
                    break;
                case '.':
                    n[i][j] = 2;
                    break;
            }
        }
    }
    
    bool x = n[0][0] == 1;
    bool y = n[0][1] == 1;
    bool z = n[0][2] == 1;
    bool k = n[1][0] == 1;
    bool l = n[1][1] == 1;
    bool m = n[1][2] == 1;
    bool a = n[2][0] == 1;
    bool b = n[2][1] == 1;
    bool c = n[2][2] == 1;
    bool x1 = n[0][0] == 0;
    bool y1 = n[0][1] == 0;
    bool z1 = n[0][2] == 0;
    bool k1 = n[1][0] == 0;
    bool l1 = n[1][1] == 0;
    bool m1 = n[1][2] == 0;
    bool a1 = n[2][0] == 0;
    bool b1 = n[2][1] == 0;
    bool c1 = n[2][2] == 0;
    if (x && ((y && z) || (l && c) || (k && a)) || z && ((a && l) || (m && c)) || k && l && m || a && b && c || y && l && b) {
        cout << "Win";
    } else if (x1 && ((y1 && z1) || (l1 && c1) || (k1 && a1)) || z1 && ((a1 && l1) || (m1 && c1)) || k1 && l1 && m1 || a1 && b1 && c1 || y1 && l1 && b1) {
        cout << "Lose";
    } else {
        cout << "Draw";
    }
}