//
// Created by Jolen on 2022/3/28.
//


int check(vector<int> &nums,int i){
    if(i!=0&&nums[i-1]>nums[i])
        return -1;
    if(i!=nums.size()-1&&nums[i+1]>nums[i])
        return 1;
    else return 0;
}
int findPeakElement(vector<int>& nums) {
    int lo=0,hi=nums.size();
    while(lo<hi){
        int mid = lo+(hi-lo>>1);
        int flag = check(nums,mid);
        if(flag==0)return mid;
        else if(flag==-1)
            hi = mid;
        else if(flag==1)
            lo = mid+1;
    }
    return -1;
}