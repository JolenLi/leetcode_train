//
// Created by Jolen on 2021/6/21.
//
#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int slow=1,fast=1;
    if(nums.size()<1)
        return nums.size();
    while(fast<nums.size())
    {
        if(nums[slow-1]!=nums[fast])
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}
int main() {
    vector<int> nums = {2,3,3, 5,5,5, 6};
    int a = removeDuplicates(nums);
    return 0;
}
