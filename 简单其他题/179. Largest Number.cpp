//
// Created by Jolen on 2022/3/29.
//

class Solution {
public:

    static bool cmp(int &a,int &b){
        string strA = to_string(a)+to_string(b);
        string strB = to_string(b)+to_string(a);
        return strA>strB;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res;

        for(int &num:nums)
            res += to_string(num);

        if(res[0]=='0')return "0";
        return res;
    }
};