//
// Created by Jolen on 2022/3/12.
//

int missingNumber(vector<int>& nums) {
    int l=0,r=nums.size()-1;
    while(l<=r){
        int mid = (r-l>>1)+l;
        if(nums[mid]!=mid)
            r=mid-1;
        else
            l=mid+1;
    }
    return r+1;
}