int search(vector<int>& nums, int target) {
    int lo = 0,hi= nums.size()-1;
    while(lo<=hi){
        int mid = lo+((hi-lo)>>1);
        if(nums[mid]>=target)
            hi = mid-1;
        else if(nums[mid]<target)
            lo = mid+1;
    }
    int left = lo;
    lo = 0,hi= nums.size()-1;
    while(lo<=hi){
        int mid = lo+((hi-lo)>>1);
        if(nums[mid]>target)
            hi = mid-1;
        else if(nums[mid]<=target)
            lo = mid+1;
    }
    int right = hi;

    return right-left+1;
}