#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector<long> c) {
    pair<long, long> d[n + 100];
    sort(c.begin(), c.end());
    memset(d, 0, sizeof(d));
    for (long i: c) {
        d[i].first++;
        d[i].second = i;
    }

    for (long i = c[0]; i < n; i++) {
        if (d[i].first != 0) {
            for (long j = find(c.begin(), c.end(), d[i].second) - c.begin(); j < c.size(); j++) {
                d[i + c[j]].first++;
                d[i + c[j]].second = c[j];
            } 
        }
    }

    return d[n].first;
}


int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<long> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    long ways = getWays(n, c);
    cout << ways;
}