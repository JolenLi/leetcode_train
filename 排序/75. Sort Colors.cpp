//
// Created by Jolen on 2021/7/1.
//
//// sort


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

void sortColors(vector<int> &nums) {
    int ptr = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            swap(nums[i], nums[ptr]);
            ptr++;
        }
    }
    for (int i = ptr; i < nums.size(); i++) {
        if (nums[i] == 1) {
            swap(nums[i], nums[ptr]);
            ptr++;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
}