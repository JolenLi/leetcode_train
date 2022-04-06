//
// Created by Jolen on 2021/6/22.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<string>

using namespace std;

//void moveZeroes(vector<int> &nums) {
//    int slow = 0, fast = 0;
//    while (fast < nums.size()) {
//        if (nums[fast]) {
//            swap(nums[slow], nums[fast]);
//            slow++;
//        }
//        fast++;
//    }
//}


void moveZeroes(vector<int> &nums) {
    int zeros = 0, n = nums.size();
    for (int i = 0; i < n; i++)
        if (nums[i] == 0)
            zeros++;
        else
            nums[i - zeros] = nums[i];
    for (int i = 0; i < n; i++)
        nums[n - i - 1] = 0;
}


int main() {
    vector<int> nums = {1, 2, 0, 3, 1, 2};
    moveZeroes(nums);
}
