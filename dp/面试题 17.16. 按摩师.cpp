//
// Created by Jolen on 2022/3/17.
//

int getMax(vector<int>&nums,int idx){
    int maxi=0;
    for(int i=2;i<=3;i++){
        if(idx-i>=0)
            maxi = max(maxi,nums[idx-i]);
    }
    return maxi;
}
int massage(vector<int>& nums) {
    // if(nums)
    int maxi = 0;
    for(int i =0;i<nums.size();i++){
        nums[i] += getMax(nums,i);
        maxi = max(maxi,nums[i]);
    }
    return maxi;

}