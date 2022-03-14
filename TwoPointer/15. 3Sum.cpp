//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<map>

using namespace std;

//// 哈希表+ 双重循环
//vector<vector<int>> threeSum(vector<int>& nums) {
//    sort(nums.begin(),nums.end());
//    set<vector<int>> mult;
//    unordered_map<int,int> ind;
//    for(int i =1;i<nums.size();i++){
//        ind[nums[i-1]]=i;
//        for(int j=i+1;j<nums.size();j++){
//            if(ind[-(nums[i]+nums[j])]){
//                mult.insert({nums[ind[-(nums[i]+nums[j])]-1],nums[i],nums[j]});
//            }
//        }
//    }
//    vector<vector<int>> res(mult.begin(),mult.end());
//    return res;
//}

// 固定一个+ 双指针
//vector<vector<int>> threeSum(vector<int> &nums) {
//    int a, b, c;
//    vector<vector<int>> res;
//    sort(nums.begin(), nums.end());
//
//    for (a = 0; a < nums.size(); a++) {
//        if (a > 0 && nums[a] == nums[a - 1])
//            continue;
//        for (b = a + 1, c = nums.size() - 1; b < c;) {
//            if (b > a+1 && nums[b] == nums[b - 1]) {
//                b++;
//                continue;
//            }
//            if (nums[a] + nums[b] + nums[c] == 0) {
//                res.push_back({nums[a],nums[b],nums[c]});
//                b++;
//                c--;
//            } else if (nums[a] + nums[b] + nums[c] > 0) {
//                c--;
//            } else {
//                b++;
//            }
//        }
//    }
//    return res;
//}


vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)return res;
    for (int a = 0; a < nums.size() - 2; a++) {
        if (a > 0 && nums[a] == nums[a - 1])
            continue;
        for (int b = a + 1, c = nums.size() - 1; b < c;) {
            if (b > a + 1 && nums[b] == nums[b - 1]) {
                b++;
                continue;
            }
            if (c < nums.size() - 1 && nums[c] == nums[c + 1]) {
                c--;
                continue;
            }
            int sum = nums[a] + nums[b] + nums[c];
            if (sum == 0)
                res.push_back({nums[a], nums[b], nums[c]});
            if (sum <= 0)
                b++;
            if (sum >= 0)
                c--;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {0, 1, -2, 0};
    threeSum(nums);
}