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

vector<int> searchRange(vector<int> &nums, int target) {
    int ansL = -1, ansR = -1;
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (nums[mid] < target)
            lo = mid + 1;
        else if (nums[mid] > target)
            hi = mid - 1;
        else if (nums[mid] == target)
            hi = mid - 1;
    }
    if (lo < nums.size() && nums[lo] == target)
        ansL = lo;
    lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (nums[mid] < target)
            lo = mid + 1;
        else if (nums[mid] > target)
            hi = mid - 1;
        else if (nums[mid] == target)
            lo = mid + 1;
    }
    if (hi >= 0 && nums[hi] == target)
        ansR = hi;
    return {ansL, ansR};
}
//
//vector<int> searchRange(vector<int> &nums, int target) {
//    int ansL = -1, ansR = -1;
//    int left = 0, right = nums.size();
//    while (left < right) {
//        int mid = ((right - left) >> 1) + left;
//        if (nums[mid] == target)
//            right = mid;
//        else if (nums[mid] < target)
//            left = mid + 1;
//        else if (nums[mid] > target)
//            right = mid;
//    }
//    if (left < nums.size() && nums[left] == target)
//        ansL = left;
//
//    left = 0, right = nums.size();
//    while (left < right) {
//        int mid = ((right - left) >> 1) + left;
//        if (nums[mid] == target)
//            left = mid + 1;
//        else if (nums[mid] < target)
//            left = mid + 1;
//        else if (nums[mid] > target)
//            right = mid;
//    }
//    if (left - 1 < nums.size() && nums[left - 1] == target)
//        ansR = left - 1;
//
//    return {ansL, ansR};
//}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9};
    cout << searchRange(nums, 6)[0] << " " << searchRange(nums, 6)[1] << endl;
}