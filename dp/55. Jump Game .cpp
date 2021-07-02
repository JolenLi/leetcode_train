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
bool canJump(vector<int>& nums) {
    int maxN = 0;
    for(int i=0;i<=maxN;i++){
        int farthest = i+nums[i];
        if(farthest>=nums.size()-1)
            return true;
        maxN = max(maxN,farthest);
    }
    return false;
}

int main() {
    vector<int> intervals = {2,3,1,1,4};
    cout << canJump(intervals);

}