#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    vector<int> result = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}