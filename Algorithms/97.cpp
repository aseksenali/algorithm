#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n][n];
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    memset(d, 0, sizeof(d));
    queue<pair<int, int>> a;
    bool used[n][n];
    memset(used, 0, sizeof(used));

    d[x1][y1] = 0;
    used[x1][y1] = true;
    a.push(make_pair(x1, y1));
    int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
    while (!a.empty() && !used[x2][y2]) {
        for (int i = 0; i < 8; i++) {
            int x = a.front().first + dx[i];
            int y = a.front().second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= n) {
                continue;
            }

            if (used[x][y] == false) {
                a.push(make_pair(x, y));
                used[x][y] = true;
                d[x][y] = d[a.front().first][a.front().second] + 1;
            }
        }
        a.pop();
    }
    cout << d[x2][y2];
}