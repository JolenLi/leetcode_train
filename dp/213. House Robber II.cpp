class Solution {
public:


    int func(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> value(nums.size()+1,0);
        value[1] = nums[0];
        for(int i = 2;i<=nums.size();i++)
        {
            value[i]=max(value[i-1],value[i-2]+nums[i-1]);
        }
        return value[nums.size()];
    }


    int rob(vector<int>& nums) {
        if(nums.size()<3)
            return func(nums);

        vector<int> copy(nums.begin()+2,nums.end()-1);
        int robFirst = nums[0]+func(copy);
        nums.erase(nums.begin());
        int robNotFirst = func(nums);
        return max(robFirst,robNotFirst);
    }
};