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

#include <cstring>
#include <string>
using namespace std;

vector<vector<int>> res;

void backTrack(vector<int>& candidates, vector<int> &nums,int target, int cur){
    if(target<=0){
        if(target==0)
            res.push_back(nums);
        return;
    }
    for(int i=cur;i<candidates.size();i++){
        nums.push_back(candidates[i]);
        backTrack(candidates,nums,target-candidates[i],i);
        nums.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end(),greater<int>());
    vector<int> nums;
    backTrack(candidates,nums,target,0);
    return res;
}
int main() {
   vector<int> candidates = {2,3,6,7};
   int target = 7;
   for(auto i:combinationSum(candidates,target)){
       for(auto j:i)
           cout<<j<<" ";
       cout<<endl;
   }
}

