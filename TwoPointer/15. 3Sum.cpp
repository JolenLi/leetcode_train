//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<map>

using namespace std;


vector<vector<int>> threeSum(vector<int> &nums) {
    int a, b, c;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (a = 0; a < nums.size(); a++) {
        if (a > 0 && nums[a] == nums[a - 1])
            continue;
        for (b = a + 1, c = nums.size() - 1; b < c;) {
            if (b > a+1 && nums[b] == nums[b - 1]) {
                b++;
                continue;
            }
            if (nums[a] + nums[b] + nums[c] == 0) {
                res.push_back({nums[a],nums[b],nums[c]});
                b++;
                c--;
            } else if (nums[a] + nums[b] + nums[c] > 0) {
                c--;
            } else {
                b++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {0,1,-2,0};
    threeSum(nums);
}