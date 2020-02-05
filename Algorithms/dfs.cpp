#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
vector<int> g[1000];
bool used[1000];
int counter = 0;

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0) {
            dfs(g[v][i]);
        }
    }   
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            counter++;
        }
    }
    cout << counter;
    return 0;
}