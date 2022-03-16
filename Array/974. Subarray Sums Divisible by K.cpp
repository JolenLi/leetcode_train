//
// Created by Jolen on 2021/6/24.
//
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

int subarraysDivByK(vector<int> &nums, int k) {
    unordered_map<int, int> prefix;
    prefix[0] = 1;
    int sum = 0, res = 0;
    for (int &num:nums) {
        sum = (((sum + num) % k)+k)%k;
        res += prefix[sum];
        prefix[sum]++;
    }
    return res;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << subarraysDivByK(nums, k) << endl;
}