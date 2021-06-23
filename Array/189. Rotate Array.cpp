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

using namespace std;
string s = "ds";
void rotate(vector<int>& nums, int k) {
    vector<int> numsCopy(nums.size(),0);
    int size = nums.size();
    for(int i = 0;i<nums.size();i++)
    {
        numsCopy[(i+k)%size] = nums[i];
    }
    for(int i = 0;i<nums.size();i++)
    {
        nums[i] = numsCopy[i];
    }
}

//void reverse(vector<int>& nums, int  start ,int end){
//    while(start<end)
//    {
//        swap(nums[start],nums[end]);
//        start++;
//        end--;
//    }
//}
//void rotate(vector<int>& nums, int k) {
//    k %= nums.size();
//    reverse(nums,0,nums.size()-1);
//    reverse(nums,0,k-1);
//    reverse(nums,k,nums.size()-1);
//}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    rotate(prices,2);
}