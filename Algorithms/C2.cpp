#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<long long int> prefix_function(string s)
{
    long long int n = s.size();
    vector<long long int> p;
    p.push_back(0);
    for (int i = 1; i < n; i++) {
        int j = p.at(i - 1);
        while (j > 0 && s[j] != s[i])
            j = p.at(j - 1);
        if (s[j] == s[i]) j++;
        p.push_back(j);
    }
    return p;
}

int main() {
    long long int k;
    long long int maximum;
    long long int start;
    string s;
    long long int i;
    long long int j;
    while (true) {
        cin >> k;
        if (k == 0) break;
        string t[k];
        maximum = 0;        
        vector<long long int> pi[k];
        long long int counter[k];
        memset(counter, 0, sizeof(counter));
        for (long long int i = 0; i < k; i++) {
            cin >> t[i];
            pi[i] = prefix_function(t[i]);
        }
        cin >> s;
        i = 0;
        j = 0;

        for (long long int h = 0; h < k; h++) {
            while (i != s.length()) {
                if (s[i] == t[h][j]) {
                    if (j == 0) {
                        start = i;
                    }
                    i++;
                    j++;
                    
                    if (j == t[h].length()) {
                        counter[h]++;
                        i = start + 1;
                        j = 0;
                    }
                } else {
                    if (j != 0)
                        j = pi[h].at(j - 1);
                    else 
                        i++;
                }
            }
            if (counter[h] > maximum) {
                maximum = counter[h];
            }
            i = 0;
            j = 0;
        }
        cout << maximum << endl;

        for (long long int i = 0; i < k; i++) {
            if (counter[i] == maximum) {
                cout << t[i] << endl;
            }
        }
    }
}