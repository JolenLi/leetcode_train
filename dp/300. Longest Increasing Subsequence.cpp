//
// Created by Jolen on 2021/6/24.
//
//
// Created by Jolen on 2021/6/23.
//



//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;


int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int ans = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}



//
//int lengthOfLIS(vector<int> &nums) {
//    if(nums.size()==0)
//        return 0;
//    vector<int> ans;
//    ans.push_back(nums[0]);
//    for(int cur =1;cur<nums.size();cur++)
//    {
//        int left=0,right = ans.size()-1;
//        int pos = 0;
//        while(left<=right){
//            int mid = (left+right)/2;
//            if(nums[cur]>ans[mid])
//            {
//                left=mid+1;
//                pos = left;
//            }else {
//                right=mid-1;
//            }
//        }
//        if(pos==ans.size())
//            ans.push_back(nums[cur]);
//        else
//            ans[pos] = nums[cur];
//    }
//    for(int i:ans)
//        cout<<i<<" ";
//    cout<<endl;
//    return ans.size();
//}


int main() {
    vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    cout << lengthOfLIS(nums) << endl;
}