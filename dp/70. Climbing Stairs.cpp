//
// Created by Jolen on 2021/6/26.
//
int climbStairs(int n) {
    vector<int> memo = {1,1};
    for(int i = 2;i<=n;i++){
        memo.push_back(memo[i-1]+memo[i-2]);
    }
    return memo[n];
}