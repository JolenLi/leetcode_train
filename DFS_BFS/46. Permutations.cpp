//
// Created by Jolen on 2022/3/14.
//

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> res;
    void backTrack(vector<int>& nums,vector<int>& temp){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return ;
        }
        for(int i = 0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                temp.push_back(nums[i]);
                backTrack(nums,temp);
                temp.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(),0);
        vector<int> temp;
        backTrack(nums,temp);
        return res;
    }
};