//
// Created by Jolen on 2021/6/23.
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

int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for (int &num:nums)
        sum += num;
    if (sum+target < 0||(sum+target)&1)
        return 0;
    sum = (sum + target)>>1;


    vector<int> dp(sum + 1, 0);
    dp[0]=1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = sum; j >= 0; j--) {
            if (j >= nums[i])
                dp[j] += dp[j - nums[i]];
        }
        for (auto x:dp)
            cout << x << " ";
        cout << endl;
    }
    return dp[sum];
}


int main() {
//    vector<vector<int>> matrix = {{2, 1, 3},
//                                  {6, 5, 4},
//                                  {7, 8, 9}};
    vector<int> num = {1,0,0,1};
    int target = 1;
    cout << findTargetSumWays(num, target) << endl;
}