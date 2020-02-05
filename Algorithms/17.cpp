#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function (int a[], int n) {
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && a[i] != a[j])
			j = pi[j-1];
		if (a[i] == a[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref = prefix_function(a, n);
    int counter = 0;
    int next_prev;
    for (int i = 0; i < pref.size(); i++) {
        if (i != n - 2)
            next_prev = pref[i + 1];
            
        if (i != n - 2) {
            if (pref[i] == 0 || next_prev <= pref[i]) {
                counter = i + 1;
            }
        } else {
            if (pref[i] == 0) {
                counter = i + 1;
            }
        }

        if (counter >= n / 2.0) {
            counter = n - 1;
            break;
        }
    }

    cout << counter;
}