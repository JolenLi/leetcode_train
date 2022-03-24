//
// Created by Jolen on 2022/3/23.
//

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> left(vector<int>(nums.size(),1));
    vector<int> right(vector<int>(nums.size(),1));
    for(int i =1;i<nums.size();i++)
        left[i] = left[i-1]*nums[i-1];
    for(int i =nums.size()-2;i>=0;i--)
        right[i]=right[i+1]*nums[i+1];

    for(int i =0;i<nums.size();i++)
        nums[i]=left[i]*right[i];
    return nums;
}