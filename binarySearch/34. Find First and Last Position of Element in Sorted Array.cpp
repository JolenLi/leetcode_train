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

    int resL = -1, resR = -1;
    if(nums.empty())
        return {resL,resR};
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l >> 1);
        if (nums[mid] >= target) {
            r=mid;
        }else{
            l = mid+1;
        }
    }
    if(nums[l]==target)
        resL=l;

    l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l +1>> 1);
        if (nums[mid] <= target) {
            l=mid;
        }else{
            r = mid-1;
        }
    }
    if(nums[l]==target)
        resR=l;

    return {resL,resR};
}

int main() {
    vector<int> nums = {};
    cout << searchRange(nums, 6)[1] << endl;
}