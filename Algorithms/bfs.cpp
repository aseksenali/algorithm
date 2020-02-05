#include <bits/stdc++.h>

using namespace std;

queue<int> a;
int n, m, x, y;
bool used[10000];
int d[10000];
vector<int> g[30000];
int counter = 1; 

void bfs(int v) {
    a.push(v);
    used[v] = true;
    while (!a.empty()) {
        v = a.front();
        for (int i = 0; i < g[v].size(); i++) {
            if (used[g[v][i]] == false) {
                a.push(g[v][i]);
                used[g[v][i]] = true;
                d[g[v][i]] = d[v] + 1;
            }
        }
        a.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(0);

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
}