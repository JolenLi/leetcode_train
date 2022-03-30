//
// Created by Jolen on 2022/3/30.
//

int minMoves2(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int mid = nums[nums.size()/2];
    int count = 0;
    for(int &num:nums)
        count+= abs(num-mid);
    return count;
}