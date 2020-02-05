#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int n, m;
queue<pair<int, int>> q;

int bfs(int x, int y) {
    while (!q.empty()) {
        q.pop();
    }

    if (a[x][y] == 1) {
        return 0;
    }

    q.push(make_pair(x, y));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int d[n][m];
    int xa = x, ya = y;
    memset(d, 1, sizeof(d));
    d[x][y] = 0;
    while (!q.empty() && !(a[xa][ya] == 1)) {
        for (int i = 0; i < 4; i++) {
            xa = q.front().first + dx[i];
            ya = q.front().second + dy[i];
            if (xa < 0 || ya < 0 || xa >= n || ya >= m) {
                continue;
            }
            if (d[xa][ya] == 16843009) {
                d[xa][ya] = d[q.front().first][q.front().second] + 1;
                q.push(make_pair(xa, ya));
            }

            if (a[xa][ya] == 1) {
                break;
            }
        }
        q.pop();
    }

    return d[xa][ya];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int d[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << bfs(i, j) << " ";
        }
        cout << endl;
    }
}