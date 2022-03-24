vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n=nums.size();
    vector<int> prefix(vector<int>(n+1,0));

    for(int i =1;i<=n;i++){
        prefix[i] = prefix[i-1]+nums[i-1];
    }

    for(int i =0;i<n;i++){
        int surfix = prefix[n]-prefix[i+1];
        nums[i] = surfix-nums[i]*(n-2*i-1) - prefix[i];
    }
    return nums;
}