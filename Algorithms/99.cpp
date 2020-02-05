#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, n, m;
    cin >> h >> n >> m;
    char lab[h][n][m];
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> lab[i][j][k];
                if (lab[i][j][k] == '1') {
                    start.push_back(i);
                    start.push_back(j);
                    start.push_back(k);
                }
                if (lab[i][j][k] == '2') {
                    end.push_back(i);
                    end.push_back(j);
                    end.push_back(k);
                }
            }
        }
    }

    int dx[5] = {0, 1, -1, 0, 0};
    int dy[5] = {1, 0, 0, -1, 0};
    int dz[5] = {0, 0, 0, 0, 1};
    queue<vector<int>> a;
    int d[h][n][m];
    bool used[h][n][m];
    memset(used, 0, sizeof(used));
    memset(d, 1, sizeof(d));
    d[start[0]][start[1]][start[2]] = 0;
    used[start[0]][start[1]][start[2]] = true;
    a.push(start);
    while (!(a.empty())) {
        for (int i = 0; i < 5; i++) {
            int x = a.front()[1] + dx[i];
            int y = a.front()[2] + dy[i];
            int z = a.front()[0] + dz[i];
            if (z < 0 || x < 0 || y < 0 || z >= h || x >= n || y >= m) {
                continue;
            }
            if (lab[z][x][y] != 'o' && used[z][x][y] == false) {
                vector<int> tmp;
                tmp.push_back(z);
                tmp.push_back(x);
                tmp.push_back(y);
                a.push(tmp);        
                d[z][x][y] = min(d[z][x][y], d[a.front()[0]][a.front()[1]][a.front()[2]] + 1);
                used[z][x][y] = true;
            }
        }
        a.pop();
    }
    cout << d[end[0]][end[1]][end[2]] * 5;
}