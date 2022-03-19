//
// Created by Jolen on 2022/3/19.
//

int maxNonOverlapping(vector<int>& nums, int target) {
    int sum=0,maxAns=0;
    unordered_set<int> prefix={0};
    for(int i =0;i<nums.size();i++){
        sum += nums[i];
        if(prefix.count(sum-target)){
            prefix = {};
            maxAns++;
        }
        prefix.insert(sum);
    }
    return maxAns;
}