#include <bits/stdc++.h>

using namespace std;

vector<int> g[100100];
int used[100100];
bool usedi[100100];
int ch[100100];
void dfs(int v) {
    usedi[v] = true;
    used[v]++;
    for (int i = 0; i < g[v].size(); i++) {
        if (!usedi[g[v][i]])
            dfs(g[v][i]);
    }  
}

int main() {
    int counter = 0;
    int counteri = 1;
    int k, n, m;
    int x, y;
    int t;
    cin >> t;
    for (int h = 0; h < t; h++) {
        cin >> k >> n >> m;
        for (int i = 0; i < k; i++) {
            cin >> ch[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x - 1].push_back(y - 1);
        }
        for (int i = 0; i < k; i++) {
            memset(usedi, 0, sizeof(usedi));
            dfs(ch[i] - 1);
        }

        for (int i = 0; i < n; i++) {
            if (used[i] >= k) {
                counter++;
            }
        }
        cout << "Case " << counteri << ": " << counter;
        memset(used, 0, sizeof(used));
        memset(ch, 0, sizeof(ch));
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        counteri++;
        counter = 0;
        cout << endl;
    }
    return 0;
}