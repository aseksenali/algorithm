#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int arr_count;
        cin >> arr_count;
        vector<int> arr(arr_count);
        for(int j = 0; j < arr_count; j++) {
            cin >> arr[j];
        }

        int result = beautifulPermutations(arr);

        cout << result;
    }
    return 0;
}