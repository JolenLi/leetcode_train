//
// Created by Jolen on 2022/3/14.
//

//
// Created by Jolen on 2021/6/26.
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

#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
    for(int i =0;i<nums.size();i++){
        while(nums[i]!=nums[nums[i]])
            swap(nums[i],nums[nums[i]]);
        if(nums[i]!=i)
            return i;
    }
    return 0;
}

int main() {
    vector<int> nums = {1,2,2};
    cout << findRepeatNumber(nums) << endl;
}

