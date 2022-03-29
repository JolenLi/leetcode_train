//
// Created by Jolen on 2022/3/28.
//



//
// Created by Jolen on 2021/6/24.
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

bool searchBound(vector<int> &nums, int target, int lo, int hi) {
    if (lo >= hi)
        return false;
    int mid = lo + ((hi - lo) >> 1);
    if (nums[mid] == target)
        return true;

    if (nums[mid] > nums[lo]) {
        if (target > nums[mid])
            lo = mid + 1;
        else if (target < nums[mid] && target >= nums[lo])
            hi = mid;
        else if (target < nums[mid] && target < nums[lo])
            lo = mid + 1;
        return searchBound(nums, target, lo, hi);
    } else if (nums[mid] < nums[hi - 1]) {
        if (target < nums[mid])
            hi = mid;
        else if (target > nums[mid] && target <= nums[hi - 1])
            lo = mid + 1;
        else if (target > nums[mid] && target > nums[hi - 1])
            hi = mid;
        return searchBound(nums, target, lo, hi);
    } else {
        return searchBound(nums, target, lo, mid) ||
               searchBound(nums, target, mid + 1, hi);
    }
}

bool search(vector<int> &nums, int target) {
    return searchBound(nums, target, 0, nums.size());
}


int main() {
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    cout << search(nums, 2) << endl;
//    cout<<INT_MAX<<endl;
}//
// Created by Jolen on 2022/3/28.
//

