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
    int k;
    cin >> k;
    string t[k];
    int counter = 0;
    int maximum = -1;
    vector<int> pi[k];
    for (int i = 0; i < k; i++) {
        cin >> t[i];
        pi[i] = prefix_function(t[i]);
    }
    string s;
    cin >> s;
    int i = 0, j = 0;
    
    for (int h = 0; h < k; h++) {
        while (i != s.length()) {
            if (s[i] == t[h][j]) {
                i++;
                j++;
                
                if (j == t[h].length()) {
                    counter++;
                    i++;
                }
            }
            
            if (s[i] != t[h][j]){
                if (j != 0)
                    j = pi[h][j - 1];
                else 
                    i++;
            }
        }
    }
}