int getMaximumGenerated(int n) {
    if(n<2)return n;
    vector<int> dp = {0,1};
    int res = 0;
    for(int i=2;i<=n;i++){
        if(i%2==0)
            dp.push_back(dp[i/2]);
        else
            dp.push_back(dp[i/2]+dp[i/2+1]);
        res = max(res,dp[i]);
    }

    return res;

}