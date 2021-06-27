//
// Created by Jolen on 2021/6/26.
//

int numberOfArithmeticSlices(vector<int> &nums) {

    int n = nums.size();
    int *dp = new int[n];
    for (int i = 0; i < nums.size(); i++) {
        dp[i] = 0;
    }
    for (int i = 2; i < n; i++) {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        total += dp[i];
    }

    return total;
}