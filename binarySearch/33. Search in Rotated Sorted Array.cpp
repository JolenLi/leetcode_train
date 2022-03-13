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

int search(vector<int> &nums, int target) {

    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r - l >> 1) + l;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] >= nums[l]) { // 从左到mid有序
            if(target<nums[mid]&&target>=nums[l])
                r = mid-1;
            else
                l = mid+1;
        }else{//从mid到右边有序
            if(target>nums[mid]&&target<=nums[r])
                l = mid+1;
            else
                r = mid-1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {3,1};
    int target = 1;
    cout << search(nums, target) << endl;
}