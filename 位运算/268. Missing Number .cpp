//
// Created by Jolen on 2021/6/26.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int missingNumber(vector<int>& nums) {
    int res = nums.size();
    for(int i =0;i<nums.size();i++)
        res^= i^nums[i];
    return res;
}


