#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string result;

string bin(int a){
    if (a == 1) {
        return "1";
    }
    result = bin(a / 2) + (char)(a % 2 + 48);
    return result;    
}

void tmp(int i) {
    cout << bin(i) << endl;
}

int main (){
    int n, j;
    cin >> n;
    vector <int> v;
    for (int i=0; i<n; i++){
        cin >>j;
        v.push_back(j);
    }
    for_each(v.begin(), v.end(), tmp);
    return 0;
}