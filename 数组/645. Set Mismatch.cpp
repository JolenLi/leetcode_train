//
// Created by Jolen on 2022/4/6.
//

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> memo(nums.size()+1);
    for(auto num:nums)
        memo[num]++;
    int x,y;
    for(int i=1;i<memo.size();i++){
        if(memo[i]==2)
            x=i;
        else if(memo[i]==0)
            y=i;
    }
    return {x,y};
}