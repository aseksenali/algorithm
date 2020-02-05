#include <bits/stdc++.h>

using namespace std;

double u[1000][1000];
bool used[1000];
vector<int> q;
int n;
vector<double> result;
vector <pair<int,pair<int,int> >> g;
vector<int> tree_id;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void minost(int v) {
    int cost = 0;

    for (int i=0; i < g.size(); ++i)
    {
        int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
        if (tree_id[a] != tree_id[b])
        {
            cost += l;
            int old_id = tree_id[b],  new_id = tree_id[a];
            for (int j = 0; j < n; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
    }
}

int main() {
    int t;
    int s;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> s >> n;
        
        double x[1000], y[1000];
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                u[i][j] = dist(x[i], y[i], x[j], y[j]);
            }
        }
        sort (g.begin(), g.end());
        for (int i=0; i<n; ++i)
        tree_id[i] = i;
        minost(0);
        sort(result.begin(), result.end());
        printf("%.2f", result[result.size() - 1 - s / 2]);
        result.clear();
        memset(u, 0, sizeof(u));
        q.clear();
        memset(used, 0, sizeof(used));
    }
}
