//
// Created by Jolen on 2021/6/26.
//

int rob(vector<int> &nums) {
    vector<int> value(nums.size() + 1, 0);
    value[1] = nums[0];

    for (int i = 2; i <= nums.size(); i++)
        value[i] = max(value[i - 1], value[i - 2] + nums[i - 1]);

    return value[nums.size()];
}
