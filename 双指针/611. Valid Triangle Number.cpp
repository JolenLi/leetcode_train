//
// Created by Jolen on 2022/3/29.
//

//
// Created by Jolen on 2021/10/24.
//


#include <bits/stdc++.h>

using namespace std;

int triangleNumber(vector<int> &nums) {
    if (nums.size() < 3)return 0;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1, k = i + 2; j < nums.size() - 1; j++) {
            while (k < nums.size() && nums[i] + nums[j] > nums[k])
                k++;
            ans += max(k - j - 1, 0);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1};
    cout << triangleNumber(nums) << endl;

}