//
// Created by Jolen on 2021/10/23.
//
#include "bits/stdc++.h"

using namespace std;

int binary_search(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) { // 直接返回
            return mid;
        }
    }
    return -1;
}

int left_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {  //缩小右界
            right = mid - 1;
        }
    }
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}

int right_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {//缩小左界
            left = mid + 1;
        }
    }
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}