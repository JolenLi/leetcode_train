//
// Created by Jolen on 2022/3/13.
//



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
//// 双重循环
//int subarraySum(vector<int> &nums, int k) {
//    int res = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        int sum = 0;
//        for (int j = i; j < nums.size(); j++) {
//            sum += nums[j];
//            if (sum == k) res++;
//        }
//    }
//    return res;
//}

////前缀和
//int subarraySum(vector<int> &nums, int k) {
//    int res = 0;
//    vector<int> prefix;
//    int sum = 0;
//    prefix.push_back(0);
//    for(int num:nums){
//        sum+=num;
//        prefix.push_back(sum);
//    }
//
//    for (int i = 0; i < nums.size(); i++) {
//        for (int j = i; j < nums.size(); j++) {
//            if (prefix[j+1]-prefix[i]==k) res++;
//        }
//    }
//    return res;
//}


////前缀和+哈希表
int subarraySum(vector<int> &nums, int k) {
    int res = 0;
    unordered_map<int,int> prefix;
    prefix[0] = 0;
    int sum = 0;
    for(int &num:nums){
        sum+=num;
        res+=prefix[sum-k];
        prefix[sum]++;
    }
    return res;
}
int main() {

    vector<int> nums = {-1, -1, 1};
    cout << subarraySum(nums, 0);

}
