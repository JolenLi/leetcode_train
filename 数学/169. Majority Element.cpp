int majorityElement(vector<int> &nums) {
    vector<int> ans(2, 1);
    ans[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == ans[0])
            ans[1]++;
        else if (--ans[1] == 0) {
            ans[0] = nums[i];
            ans[1] = 1;
        }
    }
    return ans[0];
}