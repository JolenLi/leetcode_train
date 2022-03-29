//
// Created by Jolen on 2022/3/27.
//

int searchInsert(vector<int>& nums, int target) {
    int left = 0,right = nums.size();
    while(left<right){
        int mid = left+ ((right-left)>>1);
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            left = mid+1;
        else if(nums[mid]>target)
            right = mid;
    }
    return left;
}

int searchInsert(vector<int>& nums, int target) {
    int left = 0,right = nums.size()-1;
    while(left<=right){
        int mid = left+ ((right-left)>>1);
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            left = mid+1;
        else if(nums[mid]>target)
            right = mid-1;
    }
    return left;
}