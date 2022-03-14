//
// Created by Jolen on 2022/3/12.
//

int maximumProduct(vector<int> &nums) {
    // 最小的和第二小的
    int min1 = INT_MAX, min2 = INT_MAX;
    // 最大的、第二大的和第三大的
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int x: nums) {
        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }

        if (x > max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max3 = max2;
            max2 = x;
        } else if (x > max3) {
            max3 = x;
        }
    }

    return max(min1 * min2 * max1, max1 * max2 * max3);
}


int maximumProduct(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int res = nums[size - 1] * nums[size - 2] * nums[size - 3];
    res = max(res, nums[0] * nums[1] * nums[size - 1]);
    return res;
}