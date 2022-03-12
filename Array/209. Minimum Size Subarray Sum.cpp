//
// Created by Jolen on 2022/3/11.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
    int res = INT_MAX;
    int l = 0, r = 0;
    int sum = 0;
    while (r<nums.size()) {
        sum+=nums[r++];
        while(sum>=target){
            res = min(res,r-l);
            sum-=nums[l++];
        }
    }
    return res==INT_MAX?0:res;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl;
}