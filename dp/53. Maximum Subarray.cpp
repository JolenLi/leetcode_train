//
// Created by Jolen on 2021/6/24.
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

int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    cout << maxSubArray(nums) << endl;
}