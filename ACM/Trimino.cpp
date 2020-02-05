#include <iostream>

using namespace std;

int n, x, y, k = 1;
int a[111][111];

void fill(int x, int y, int xp, int yp) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; i++)
            if ((x + i == xp) && (y + i == yp)) continue;
            else a[x + i][y + j] = k;
    k++;
}

void rec(int x, int y, int sz, int xp, int yp) {
    if (sz == 2) 
    {
        fill (x, y, xp, yp);
        return;
    }

    if (xp < x && yp < y) {
        fill (x + sz / 2 - 1, y + sz / 2 - 1, x + sz / 2 - 1, y + sz / 2 - 1);
        rec(x, y, sz / 2, xp, yp);
        rec(x + sz / 2, y, sz / 2, x + sz / 2, y + sz / 2 - 1);
        rec(x, y + sz / 2, sz / 2, x + sz / 2 - 1, y + sz / 2);
        rec(x + sz / 2, y + sz / 2, sz / 2, x + sz / 2, y + sz / 2);
    } else if (xp >= x && yp < y) {
        fill (x + sz / 2 - 1, y + sz / 2 - 1, x + sz / 2, y + sz / 2 - 1);
        rec(x, y, sz / 2, x + sz / 2 - 1, y + sz / 2 - 1 );
        rec(x + sz / 2, y, sz / 2, xp, yp);
        rec(x, y + sz / 2, sz / 2, x + sz / 2 - 1, y + sz / 2);
        rec(x + sz / 2, y + sz / 2, sz / 2, x + sz / 2, y + sz / 2);
    } else if (xp < x && yp >= y) {
        fill (x + sz / 2 - 1, y + sz / 2 - 1, x + sz / 2 - 1, y + sz / 2);
        rec(x, y, sz / 2, x + sz / 2 - 1, y + sz / 2 - 1 );
        rec(x + sz / 2, y, sz / 2, x + sz / 2, y + sz / 2 - 1);
        rec(x, y + sz / 2, sz / 2, xp, yp);
        rec(x + sz / 2, y + sz / 2, sz / 2, x + sz / 2, y + sz / 2);
    } else if (xp >= x && yp >= y) {
        fill (x + sz / 2 - 1, y + sz / 2 - 1, x + sz / 2, y + sz / 2);
        rec(x, y, sz / 2, x + sz / 2 - 1, y + sz / 2 - 1 );
        rec(x + sz / 2, y, sz / 2, x + sz / 2, y + sz / 2 - 1);
        rec(x, y + sz / 2, sz / 2, x + sz / 2 - 1, y + sz / 2);
        rec(x + sz / 2, y + sz / 2, sz / 2, xp, yp);
    }
}

int main() {
    cin >> n >> x >> y;
    int size = (1 << n);
    rec(0, 0, size, x, y);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}