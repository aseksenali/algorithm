#include<iostream> 

using namespace std; 
int main()
{
    int n;
    cin >> n;
    long long int res;
    res = ((n / 10) * ((n / 10) + 1)) * 100 + 25;
    cout << res;
} 