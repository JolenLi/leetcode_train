//
// Created by Jolen on 2021/6/24.
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


using namespace std;

int maxSubArray(vector<int> &nums) {
    if (nums.size() == 0)
        return 0;
    vector<int> memo(nums.size(), 0);
    memo[0] = nums[0];
    int lastSum = memo[0];
    int ans = lastSum;
    for (int i = 1; i < nums.size(); i++) {
        lastSum = max(lastSum+nums[i],nums[i]);
        ans = max(ans,lastSum);
    }
    return ans;
}

int main() {
    vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    cout << maxSubArray(nums) << endl;
}