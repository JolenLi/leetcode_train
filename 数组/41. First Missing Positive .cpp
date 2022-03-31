//
// Created by Jolen on 2022/3/14.
//

//
// Created by Jolen on 2021/6/26.
//




//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;

int firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return nums.size() + 1;
}

int main() {
    vector<int> nums = {1,2,};
    cout << firstMissingPositive(nums) << endl;
}

