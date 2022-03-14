//
// Created by Jolen on 2022/3/14.
//

int maxProduct(vector<int>& nums) {
    vector<vector<int>> dp(nums.size()+1,vector<int>(2,0));
    dp[0][0]=1,dp[0][1]=1;
    int res = nums[0];
    for(int i=0;i<nums.size();i++){
        dp[i+1][0] = min(min(nums[i],dp[i][0]*nums[i]),dp[i][1]*nums[i]);
        dp[i+1][1] = max(max(nums[i],dp[i][0]*nums[i]),dp[i][1]*nums[i]);
        res = max(res,dp[i+1][1]);
    }
    return res;
}