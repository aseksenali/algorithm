#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function (string s) 
{
  int n = (int)s.length();
  vector<int> pi (n);
  for (int i = 1; i < n; i++) 
  {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}


int main() {
    string s;
    bool OK;
    while (true) {
        OK = true;
        cin >> s;
        if (s == ".") {
            break;
        }
        vector<int> pi = prefix_function(s);
        cout << s.size() / (s.size() - pi[s.size() - 1]) << endl;
    }
    return 0;
}