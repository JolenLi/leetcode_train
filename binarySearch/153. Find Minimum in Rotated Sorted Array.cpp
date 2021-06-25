//
// Created by Jolen on 2021/6/25.
//



//// 二分查找


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l >> 1);
        if(nums[r]>nums[mid])
            r = mid;
        else
            l = mid+1;
    }
    return nums[l];
}

int main() {
    vector<int> nums = {4, 5, 6, 7,8};
    cout << findMin(nums) << endl;
}