//
// Created by Jolen on 2021/6/27.
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


using namespace std;

int numSquares(int n) {
    vector<int> nums;
    int base = 1;
    while (base * base <= n) {
        int num = base * base;
        nums.push_back(num);
        base++;
    }

    ////    常规解法
//    vector<vector<int>> memo(n + 1, vector<int>(nums.size() + 1, INT_MAX));
//    for (int i = 0; i <= nums.size(); i++)
//        memo[0][i] = 0;
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= nums.size(); j++) {
//            if (nums[j - 1] <= i) {
//                memo[i][j] = min(memo[i][j - 1], memo[i - nums[j - 1]][j] + 1);
//            } else {
//                memo[i][j] = memo[i][j - 1];
//            }
//        }
//    }
//    return memo[n][nums.size()];

////  状态压缩
    vector<int> memo(n + 1, INT_MAX);
    memo[0] = 0;
    for (int i = 1; i <= nums.size(); i++) {
        for (int j = nums[i - 1]; j <= n; j++) {
            memo[j] = min(memo[j], memo[j - nums[i - 1]] + 1);
        }
    }
    return memo[n];
}

int main() {
    cout << numSquares(13) << endl;
}

