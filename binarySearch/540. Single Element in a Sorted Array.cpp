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

int singleNonDuplicate(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left >> 1);
        int res = right - left - 1 >> 1;
        if (res % 2) {
            if (nums[mid] == nums[mid - 1])
                right = mid - 2;

            else if (nums[mid] == nums[mid + 1])
                left = mid + 2;
            else
                return nums[mid];
        } else {
            if (nums[mid] == nums[mid - 1])
                left = mid + 1;

            else if (nums[mid] == nums[mid + 1])
                right = mid - 1;
            else
                return nums[mid];
        }
    }
    return nums[left];
}

int main() {
    vector<int> nums = {3, 3, 7, 7, 6, 6, 10, 11, 11};
    cout << singleNonDuplicate(nums) << endl;
}