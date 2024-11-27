// 8. Coin Change Combinations:

#include <iostream>
#include <vector>
using namespace std;

int coinChangeCombinations(vector<int>& coins, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1; 
    for (int coin : coins) {
        for (int j = coin; j <= sum; j++) {
            dp[j] += dp[j - coin];
        }
    }
    return dp[sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    cout << coinChangeCombinations(coins, sum) << endl;
    return 0;
}
