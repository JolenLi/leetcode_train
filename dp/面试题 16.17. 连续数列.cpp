//
// Created by Jolen on 2022/3/17.
//

int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    for(int i=1;i<nums.size();i++){
        nums[i] = max(nums[i],nums[i]+nums[i-1]);
        res = max(nums[i],res);
    }
    return res;
}