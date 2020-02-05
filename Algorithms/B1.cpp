#include <bits/stdc++.h>

using namespace std;

vector<int> g[1010];
int money[1010];
bool used[1010];
int groups[1010];
int n;
int counter = 0;

void dfs(int v) {
    used[v] = true;
    groups[v] = counter;

    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == false) {
            dfs(g[v][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            counter++;
            dfs(i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int m, u, v;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> money[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        dfs(0);

        int moneypergroup[counter][2];
        for (int i = 0; i <= counter; i++) {
            for (int j = 0; j < 2; j++) {
                moneypergroup[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            moneypergroup[groups[i]][0] += money[i];
            moneypergroup[groups[i]][1]++;
        }
        bool ok = true;
        int moneys = moneypergroup[0][0] / moneypergroup[0][1];
        if (moneypergroup[0][0] % moneypergroup[0][1] != 0) {
            ok = false;
        }
        
        for (int i = 0; i <= counter; i++) {
            if (moneypergroup[i][0] / moneypergroup[i][1] != moneys) {
                ok = false;
                break;
            }
        }

        cout << "Case " << k + 1 << ": ";
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        memset(money, 0, sizeof(money));
        memset(groups, 0, sizeof(groups));
        memset(used, 0, sizeof(used));
        memset(g, 0, sizeof(g));
    }
}