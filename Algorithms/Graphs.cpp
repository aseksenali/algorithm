#include <iostream>
#include <vector>

using namespace std;

vector<int> a[1000];
int g[1000][1000];
bool used[1000];
int n, m, x, y;

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < n; i++) {
        if (g[v][i] == 1 && used[i] == false) {
            dfs(g[v][i]);
        }
    }
}

void dfs2(int v) {
    used[v] = true;
    for (int i = 0; i < a[v].size(); i++) {
        if (used[a[v][i]] == false) {
            dfs(a[v][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x][y] = 1;
        g[y][x] = 1;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == false) 
            dfs2(i);
    }
    return 0;
}