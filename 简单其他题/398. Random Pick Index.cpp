//
// Created by Jolen on 2022/3/18.
//



vector<int> nums;
Solution(vector<int>& nums) {
this->nums = nums;
}

int pick(int target) {
    int count = 0;
    int idx = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            count++;
            if(rand()%count==0)
                idx=i;
            // count++;
        }
    }
    return idx;
}
