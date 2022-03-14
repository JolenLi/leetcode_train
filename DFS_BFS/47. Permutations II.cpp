//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>
#include <set>

using namespace std;

vector<int> visited;
vector<vector<int>> ans;

void backTrack(vector<int> &nums, vector<int> &res) {
    if (res.size() == nums.size()) {
        ans.push_back(res);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            if (i == 0 || nums[i - 1] != nums[i] || visited[i - 1]) {
                visited[i] = 1;
                res.push_back(nums[i]);
                backTrack(nums, res);
                res.pop_back();
                visited[i] = 0;
            }

        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    visited = vector<int>(nums.size(), 0);
    vector<int> res;
    backTrack(nums, res);
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 2};
    auto ans = permuteUnique(nums);
    for (auto i:ans) {
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
}