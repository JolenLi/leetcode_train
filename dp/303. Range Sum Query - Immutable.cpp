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

//// 前缀和
using namespace std;

class NumArray {
public:

    int *preSum ;
    NumArray(vector<int> &nums) {
        preSum = new int[nums.size()+1];
        preSum[0] = 0;
        for(int i =1;i<=nums.size();i++){
            preSum[i] = preSum[i-1]+nums[i-1];
        }
    }

    int sumRange(int left, int right) {
        return preSum[right+1]-preSum[left];
    }
};


int main() {

    cout << uniquePaths(3, 2) << endl;
}

