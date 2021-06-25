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
//
//int lengthOfLIS(vector<int> &nums) {
//    int n = nums.size();
//    if (!n)
//        return 0;
//    vector<int> memo(nums.size(), 1);
//    for (int i = 0; i < nums.size(); i++)
//        for (int j = i; j < nums.size(); j++) {
//            if (nums[j] > nums[i])
//                memo[j] = max(memo[i] + 1, memo[j]);
//        }
//    int maxs = 0;
//    for(int i:memo)
//        maxs = max(i,maxs);
//
//    return maxs;
//}
//

int lengthOfLIS(vector<int> &nums) {
    if(nums.size()==0)
        return 0;
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int cur =1;cur<nums.size();cur++)
    {
        int left=0,right = ans.size()-1;
        int pos = 0;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[cur]>ans[mid])
            {
                left=mid+1;
                pos = left;
            }else {
                right=mid-1;
            }
        }
        if(pos==ans.size())
            ans.push_back(nums[cur]);
        else
            ans[pos] = nums[cur];
    }
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;
    return ans.size();
}


int main() {
    vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
    cout << lengthOfLIS(nums) << endl;
}