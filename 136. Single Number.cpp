//
// Created by Jolen on 2021/6/22.
//

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<string>

using namespace std;

//int singleNumber(vector<int> &nums) {
//    unordered_map<int, int> table;
//    for (int i:nums)
//        table[i] += 1;
//    for (auto i:nums)
//        if (table[i] == 1)
//            return i;
//}

int singleNumber(vector<int> &nums) {
    int sum = 0;
    for (int i:nums)
        sum ^=i;
    return sum;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2};
    cout << singleNumber(nums);
}


