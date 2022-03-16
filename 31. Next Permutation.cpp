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
void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int idx,idx2;
    for (idx = n - 2; idx >= 0; idx--) {
        if (nums[idx] < nums[idx + 1])
            break;
    }
    if(idx==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for( idx2=n-1;idx2>idx;idx2--){
        if(nums[idx2]>nums[idx]){
            swap(nums[idx2],nums[idx]);
            break;
        }
    }
    reverse(nums.begin()+idx+1,nums.end());
}



int main() {
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2);
}