#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string s;
    int k = 0;
    for (int i = 0; i < size(s); i++)
    {
        if (s[i] == '(')
            k++;
        else    
            k--;
        if (k < 0) break;
    }
    if (k == 0) cout << "YES";
    else if (k != 0) cout << "NO";
}