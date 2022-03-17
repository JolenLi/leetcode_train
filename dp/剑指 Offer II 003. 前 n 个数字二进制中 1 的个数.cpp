class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        dp.push_back(0);
        for(int i =1;i<=n;i++)
            dp.push_back((i&1)+dp[(i>>1)]);
        return dp;
    }
};