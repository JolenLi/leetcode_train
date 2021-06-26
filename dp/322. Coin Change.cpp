//
// Created by Jolen on 2021/6/23.
//



//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

//
//int dp(const vector<int> &coins, vector<int> &memo, int amount) {
//    if (amount < 0)return -1;
//    if (memo[amount] != -2) return memo[amount];
//    int mini = INT_MAX;
//    for (int coin:coins) {
//        int subQuestion = dp(coins, memo, amount - coin) + 1;
//        if (subQuestion >0)
//            mini = min(mini, subQuestion);
//    }
//    memo[amount] = mini == INT_MAX ? -1 : mini;
//    return memo[amount];
//}
//
//int coinChange(vector<int> &coins, int amount) {
//    vector<int> memo(amount + 1, -2);
//    memo[0] = 0;
////    for (auto i:memo)
////        cout << i << " ";
////    cout << endl;
//    return dp(coins, memo, amount);
//}

int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int coin:coins)
        for (int i = coin; i <= amount; i++)
            dp[i] = min(dp[i], dp[i - coin] + 1);
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {186, 419, 83, 408};
    int amount = 6249;
    cout << coinChange(coins, amount);
}