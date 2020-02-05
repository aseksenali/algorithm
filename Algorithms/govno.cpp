#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> g[100];
bool used[100];
vector<vector<int> > result;

void bfs(int v) {
    used[0] = 0;
    q.push(v);
    while (!q.empty()) {
        for (int i = 0; i < g[v].size(); i++) {
            used[g[i][v]] = used[v] + 1;
            q.push(g[v][i]);
        }
        q.pop();
    }
}

int main() {
    int n, m;
    int x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> y;
            g[x - 1].push_back(y - 1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < n; i++) {
        cout << result[i][0] + 1 << " " << result[i][1] << " " << result[i][2] << endl;
    }
    return 0;
}