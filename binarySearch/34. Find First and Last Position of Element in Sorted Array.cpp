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
//
//    int resL = -1, resR = -1;
//    if (nums.empty())
//        return {resL, resR};
//    int l = 0, r = nums.size() - 1;
//    while (l < r) {
//        int mid = l + (r - l >> 1);
//        if (nums[mid] >= target) {
//            r = mid;
//        } else {
//            l = mid + 1;
//        }
//    }
//    if (nums[l] == target)
//        resL = l;
//
//    l = 0, r = nums.size() - 1;
//    while (l < r) {
//        int mid = l + (r - l + 1 >> 1);
//        if (nums[mid] <= target) {
//            l = mid;
//        } else {
//            r = mid - 1;
//        }
//    }
//    if (nums[l] == target)
//        resR = l;
//
//    return {resL, resR};
//}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 9};
    cout << searchRange(nums, 6)[0] << " " << searchRange(nums, 6)[1] << endl;
}