//
// Created by Jolen on 2022/3/23.
//

vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> prefix(vector<int>(nums.size(), 1));
    vector<int> suffix(vector<int>(nums.size(), 1));
    for (int i = 1; i < nums.size(); i++)
        prefix[i] = prefix[i - 1] * nums[i - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i + 1];

    for (int i = 0; i < nums.size(); i++)
        nums[i] = prefix[i] * suffix[i];
    return nums;
}