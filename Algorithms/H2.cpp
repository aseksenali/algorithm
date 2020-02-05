#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double u[1000][1000];
bool used[1000];
int n;
vector <pair<int,pair<int,int> >> g;
vector<int> tree_id;

int minost(int v) {
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
    return cost;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> u[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g.push_back(make_pair(u[i][j], make_pair(i, j)));
            g.push_back(make_pair(u[i][j], make_pair(j, i)));
        }
    }

    sort (g.begin(), g.end());
    for (int i=0; i<n; ++i)
        tree_id.push_back(i);

    cout << minost(0) << endl;
}
