//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> hashMap;
    vector<int> vec;
    for(int i = 0;i<nums.size();i++)
    {
         auto it = hashMap.find(target - nums[i]);
         if(it==hashMap.end())
             hashMap[nums[i]] = i;
         else
         {
             vec.push_back(it->second);
             vec.push_back(i);
             break;
         }
    }
    return vec;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    twoSum(nums,5);
}