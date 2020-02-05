#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[n + 1][2];
    vector<int> result;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
        cin >> dp[i][0];
    dp[0][0] = 0;
    dp[0][1] = -1;
    dp[1][1] = -1;
    
    for(int i = 2; i <= n; i++){
        if (dp[i - 1][0] > dp[i - 2][0]) {
            dp[i][0] += dp[i - 1][0];
            dp[i][1] = i - 1; 
        } else {
            dp[i][0] += dp[i - 2][0];
            dp[i][1] = i - 2;
        }
    }
    cout << dp[n][0] << endl; 
    int i = n;
    while (i != -1) {
        result.push_back(i);
        i = dp[i][1];
    } 
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        if (result[i] != 0)
            cout << result[i] << " ";
    }          
}