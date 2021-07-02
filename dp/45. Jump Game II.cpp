//
// Created by Jolen on 2021/7/2.
//

//
// Created by Jolen on 2021/7/1.
//
//// sort


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;
////     dp
//int jump(vector<int> &nums) {
//    int n = nums.size();
//    vector<int>memo(n,n);
//    memo[0] = 0;
//    for(int i =1;i<n;i++)
//        for(int j =0;j<i;j++){
//            if(j+nums[j]>=i){
//                memo[i] = min(memo[i],memo[j]+1);
//            }
//        }
//    return memo[n-1];
//}


//// 贪心
int jump(vector<int> &nums) {
    int farthest = 0;
    int target = nums.size() - 1;
    int step = 0, jumpTo = 0;
    for (int i = 0; i < target; i++) {
        farthest = max(farthest, i + nums[i]);
        if (jumpTo == i) {
            jumpTo = farthest;
            step++;
        }
    }
    return step;
}

int main() {
    vector<int> intervals = {2, 3, 1, 1, 4};
    cout << jump(intervals);

}