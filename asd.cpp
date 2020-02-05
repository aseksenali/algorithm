#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double p=1234.5678;
    cout.setf(ios::fixed);
    cout << "p=" << setprecision(3)<<p<<endl;
    // int a; 
    // cin >> a;
//    cout << fixed << setprecision(4) << sqrt(a) ;
}