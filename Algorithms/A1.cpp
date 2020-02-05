#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> a;

int w, h;
bool used[25][25];
char ch[25][25];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int bfs(int x, int y) {
    int counter = 0;
    a.push(make_pair(x, y));

    while (!a.empty()) {
        x = a.front().first;
        y = a.front().second;

        for (int i = 0; i < 4; i++) {
            if ((x + dx[i]) < h && (y + dy[i]) < w && (x + dx[i]) >= 0 && (y + dy[i]) >= 0) {
                if (used[x + dx[i]][y + dy[i]] == false && ch[x + dx[i]][y + dy[i]] != '#') {
                    a.push(make_pair(x + dx[i], y + dy[i]));
                    used[x + dx[i]][y + dy[i]] = true;
                    counter++;
                }
            }
        }
        a.pop();
    }

    if (counter == 0) counter = 1;

    return counter;
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> w >> h;
        int initx, inity;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> ch[i][j];
                
                if (ch[i][j] == '@') {
                    initx = i;
                    inity = j;
                }
            }
        }

        cout << "Case " << k + 1 << ": " << bfs(initx, inity) << endl;
        memset(used, 0, sizeof(used));
        memset(ch, 0, sizeof(ch));
    }
}